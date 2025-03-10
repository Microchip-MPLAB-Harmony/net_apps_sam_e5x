/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application States

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,
    /* In this state, the application waits for a IP Address */
    APP_TCPIP_WAIT_INIT,

    APP_TCPIP_WAIT_FOR_IP,

    APP_TCPIP_WAITING_FOR_COMMAND,
    APP_TCPIP_OPENING_SERVER,


    APP_TCPIP_WAIT_ON_DNS,

    APP_TCPIP_WAIT_FOR_CONNECTION,
    APP_TCPIP_SERVING_CONNECTION,

    APP_TCPIP_WAIT_FOR_RESPONSE,

    APP_TCPIP_CLOSING_CONNECTION,

    APP_TCPIP_ERROR,
} APP_STATES;


// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;

    /* Application's current state */
    APP_STATES              clientState;
    APP_STATES              serverState;

    /* Application data buffer */

    TCP_SOCKET              clientSocket;
    TCP_SOCKET              serverSocket;

    char *            host;

    char *            path;
    uint16_t          port;
} APP_DATA;

/* AT24MAC READ states

  Summary:
    AT24MAC READ states enumeration

  Description:
    These states determine different stages of MAC address read 
    from AT24MAC402.
*/
typedef enum
{
    MAC_ADDR_READ_STATE_READ,
    MAC_ADDR_READ_STATE_WAIT,
    MAC_ADDR_READ_STATE_SUCCESS,
    MAC_ADDR_READ_STATE_ERROR,
}AT24_MAC_ADDR_READ_STATE;

/* AT24MAC READ status

  Summary:
    AT24MAC READ Status enumeration

  Description:
    These states determine different results of AT24MAC402 read.
*/
typedef enum
{
    //An unspecified error has occurred
    ATMAC_READ_ERROR        = -1,
    // ATMAC read success
    ATMAC_READ_SUCCESS      = 0,
    // An operation is currently in progress
    ATMAC_READ_PENDING      = 1,   
} AT24_MAC_READ_STATUS;


#define AT24MAC_SUBADDR         (0x9A)
#define EUI48_MAC_ADDR_LENGTH   (6)
#define AT24MAC_SUBADDR_LEN     (1)

#if defined(__SAME54P20A__)
#define AT24MAC_DEVICE_MACADDR  (0x005E)//on SAME54 XPRO
#elif defined(__SAMV71Q21B__) || defined(__SAME70Q21B__)
#define AT24MAC_DEVICE_MACADDR  (0x005F)//on SAME70/V71 XULT
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks ( void );


#endif /* _APP_H */
/*******************************************************************************
 End of File
 */

