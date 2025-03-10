/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "system_config.h"
#include "system_definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

uint8_t mountSdmmcFlag  = false;
uint8_t mountNVMFlag    = false;
APP_LED_STATE LEDstate = APP_LED_STATE_OFF;
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
#if (TCPIP_FTPS_OBSOLETE_AUTHENTICATION == 0)  
/* TODO:  Add any necessary callback functions.
*/
static bool APP_FTPAuthHandler(const char* user, const char* password, const TCPIP_FTP_CONN_INFO* pInfo, const void* hParam);
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Initialize the app state to wait for media attach. */
    appData.state = APP_TCPIP_WAIT_INIT;
    appData.usbState = APP_STATE_USB_BUS_ENABLE;
    appData.deviceIsConnected = false;
}

USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler (USB_HOST_EVENT event, void * eventData, uintptr_t context)
{
    switch (event)
    {
        case USB_HOST_EVENT_DEVICE_UNSUPPORTED:
            break;
        default:
            break;                    
    }
    
    return(USB_HOST_EVENT_RESPONSE_NONE);
}

void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            appData.deviceIsConnected = true;            
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            appData.deviceIsConnected = false;
            break;
            
        default:
            break;
    }
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    SYS_STATUS          tcpipStat;
    TCPIP_NET_HANDLE    netH;
    int                 nNets;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    int                 i;
    const char          *netName, *netBiosName;
    static uint32_t     startTick = 0;
    

    switch(appData.usbState)
    {
        case APP_STATE_USB_BUS_ENABLE:
            /* Set the event handler and enable the bus */
            SYS_FS_EventHandlerSet((void *)APP_SYSFSEventHandler, (uintptr_t)NULL);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0);
            USB_HOST_BusEnable(0);
            appData.usbState = APP_STATE_WAIT_FOR_USB_BUS_ENABLE_COMPLETE;
            break;
        case APP_STATE_WAIT_FOR_USB_BUS_ENABLE_COMPLETE:
            if(USB_HOST_BusIsEnabled(0))
            {
                SYS_CONSOLE_MESSAGE("APP: USB HOST BUS is Enabled \r\n");
                appData.usbState = APP_STATE_WAIT_FOR_USB_MEDIA_ATTACH;
            }
            break;
        case APP_STATE_WAIT_FOR_USB_MEDIA_ATTACH:
            /* Wait for USB MEDIA attach. The state machine will move
             * to the next state when the attach event
             * is received.  */
            if(appData.deviceIsConnected)
            {
                appData.usbState = APP_STATE_USB_MEDIA_CONNECTED;
            }
            break;
        case APP_STATE_USB_MEDIA_CONNECTED:
            SYS_CONSOLE_MESSAGE("APP: USB MEDIA is Connected \r\n");
            appData.usbState = APP_STATE_USB_MEDIA_IDLE;
            break;
        default:
            break;
    }
    
    
    switch(appData.state)
    {
        
        case APP_TCPIP_WAIT_INIT:
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE("APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_TCPIP_ERROR;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the
                // available interfaces and register
                // a Bonjour service

                nNets = TCPIP_STACK_NumberOfNetworksGet();

                for(i = 0; i < nNets; i++)
                {
                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif
                    (void)netName;          // avoid compiler warning 
                    (void)netBiosName;      // if SYS_CONSOLE_PRINT is null macro

                }

#if defined(TCPIP_STACK_USE_HTTP_NET_SERVER)
                // register the application HTTP processing
                HTTP_APP_Initialize();
#endif
#if (TCPIP_FTPS_OBSOLETE_AUTHENTICATION == 0)              
                appData.ftpHandle = TCPIP_FTP_AuthenticationRegister(APP_FTPAuthHandler, 0);
                if(appData.ftpHandle == 0)
                {
                    SYS_CONSOLE_MESSAGE("Failed to register FTP authentication handler!\r\n");
                }
#endif            
                appData.state = APP_TCPIP_TRANSACT;
            }

            break;

        case APP_TCPIP_TRANSACT:
            if(SYS_TMR_TickCountGet() - startTick >= SYS_TMR_TickCounterFrequencyGet()/2ul)
            {
                startTick = SYS_TMR_TickCountGet();
                LEDstate ^= APP_LED_STATE_ON;
                if(LEDstate == 1)
                {
                    APP_LED_1StateSet();
                }
                else if(LEDstate == 0)
                {
                    APP_LED_1StateClear();
                }
            }

            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for(i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                if(!TCPIP_STACK_NetIsReady(netH))
                {
                    return;    // interface not ready yet!
                }
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;

                    SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                    SYS_CONSOLE_MESSAGE(" IP Address: ");
                    SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                }
            }
            break;

        default:
            break;
    }
}

#if (TCPIP_FTPS_OBSOLETE_AUTHENTICATION == 0)  
// Implement the authentication handler
// This trivial example does a simple string comparison
// The application should implement a more secure aproach:
// using hashes, digital signatures, etc.
// The TCPIP_FTP_CONN_INFO can be used to get more details about the client requesting login
static bool APP_FTPAuthHandler(const char* user, const char* password, const TCPIP_FTP_CONN_INFO* pInfo, const void* hParam)
{
    if(strcmp(user, "Microchip") == 0 && strcmp(password, "Harmony") == 0)
    {
        return true;
    }

    return false;
}
#endif
/*******************************************************************************
 End of File
 */
