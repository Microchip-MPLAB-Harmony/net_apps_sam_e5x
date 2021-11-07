# TCP/IP Berkeley UDP Relay

The Berkeley UDP Relay configuration demonstrates the use of multiple sockets for both sending and receiving. There are three different sub-functions of this application:

-   UDP Relay, which accepts UDP packets on one socket, and sends the packets out on a different socket

-   UDP Relay Client, which generates UDP traffic that is compatible with the UDP Relay Server

-   UDP Relay Server, which receives and checks traffic for a packet count and reports is any packets are dropped


**TCP/IP Berkeley UDP Relay MHC Configuration**

The following Project Graph diagram shows the Harmony components included in the TCP Client demonstration application.

-   MHC is launched by selecting **Tools \> Embedded \> MPLAB® Harmony 3 Configurator** from the MPLAB X IDE and after successful database migration , TCP/IP demo project is ready to be configured and regenerated.

    ![tcpip_same54_project](../../docs/GUID-BDCABA15-8CFC-4BBD-B152-813303321FF6-low.png)

-   **TCP/IP Root Layer Project Graph**

    The root layer project shows that SERCOM2 peripheral is selected to do read and write operation for TCP/IP commands.

    This is the basic configuration with SYS\_CONSOLE, SYS\_DEBUG and SYS\_COMMAND modules. These modules are required for TCP/IP command execution.

    ![tcpip_same54_project](../../docs/GUID-45B87642-8F0E-4607-A2F0-B53DB1B3E01C-low.png)

    **FreeRTOS** component is required for RTOS application. For bare-metal \(non-RTOS\) **FreeRTOS** component should not be selected.

    **NOTE** - The above diagram contains **FreeRTOS** component and that is required for RTOS application. For bare-metal\(non-RTOS\) **FreeRTOS** component shouldn't be selected.

    ![tcpip_same54_project](../../docs/GUID-49CBCF8F-130E-4268-A6ED-10605AAE4941-low.png)

-   **TCP/IP Required Application**

    TCP/IP demo use these application module components for this demo. **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **DNS Client** provides DNS resolution capabilities to the stack.

    **Berkeley API** module provides the Berkeley\_Socket\_Distribution \(BSD\) wrapper to the native Microchip TCP/IP Stack APIs. During this component selection, the required transport and network modules are also selected.

    ![tcpip_same54_project](../../docs/GUID-F53C1B79-32A9-4821-A6E5-784F72A71811-low.png)

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8091 PHY driver** library for SAME54 demonstartion.

    ![tcpip_same54_project](../../docs/GUID-CA9BB7EB-854A-41AA-B6AB-324BC76EDB9D-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP Berkeley UDP Relay Hardware Configuration**

This is the following section describes the hardware configuration used for this application demonstration.

1.  This section describes the required default hardware configuration use USB device as **on board debugger and programmer** for this application demonstration.

    -   No hardware related configuration or jumper setting changes are necessary

    -   Refer to the SAM E54 Ethernet Starter Kit [User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/70005321A.pdf)

        ![required_hardware](../../docs/GUID-38FBEB65-FF92-4E6E-BD39-95B6DFEA5091-low.png)

    -   Connect the micro USB cable from the computer to the DEBUG USB connector on the SAM E54 Xplained Pro Evaluation Kit

    -   Establish a connection between the router/switch with the SAM E54 Xplained Pro Evaluation Kit through the RJ45 connector

    ![required_hardware](../../docs/GUID-EC77D4D8-500E-4398-B7ED-1E0C339FED16-low.png)


**TCP/IP Berkeley UDP Relay Running Application**

This table list the name and location of the MPLAB X IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_e54\_xpro.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the Berkeley UDP Relay on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Bare Metal \( non-RTOS\).|
|sam\_e54\_xpro\_freertos.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the Berkeley UDP Relay on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Freertos.|

There are several different commands available in the demonstration from the console port:

-   current - Displays the current configuration

-   start - Starts the packet relay service

-   stop - Stops the packet relay service


-   relayhost < host name \> - Sets the host to which packets are to be relayed

-   relayport < port number \> - Sets the port to which packets are to be relayed

-   ipv4port < port number \> - Sets the IPv4 port that the relay server will listen to for packets to relay

-   ipv6port < port number \> - Sets the IPv6 port that the relay server will listen to for packets to relay


-   relayclienthost < host name \> - Sets the host to which packets are to be sent

-   relayclientiter < number \> - The number of packets to generate

-   relayclientstart - Starts the relay client. This command must be used after the general application start. After a start is called, and the first packet is received by either the relay or the relay server, periodic updates will be sent to the console with information about the number of packets and bytes received.


**Running Demonstration Steps**

1.  Build and download the demonstration project on the target board.

2.  If the board has a SERCOM configuration:

    1.  A virtual COM port will be detected on the computer, when the USB cable is connected to USB-UART connector.

    2.  Open a standard terminal application on the computer \(like Hyper-terminal or Tera Term\) and configure the virtual COM port.

    3.  Set the serial baud rate to 115200 baud in the terminal application.

    4.  See that the initialization prints on the serial port terminal.

    5.  When the DHCP client is enabled in the demonstration, wait for the DHCP server to assign an IP address for the development board. This will be printed on the serial port terminal.

        -   Alternatively: Use the Announce service or ping to get the IP address of the board.

        -   Run **tcpip\_discoverer.jar** to discover the IPv4 and IPv6 address for the board.

3.  Execution:


-   To test the UDP packet relay with IPv4, send the following commands,

    -   relayclienthost < ip address of the relay client \>

    -   relayclientiter < number of packets to relay \>

    -   relayhost < ip address of the host to which packets are to be relayed \>

    -   relayport < port number to which packets are to be relayed \>

    -   ipv4port < port number to which the relay server listens to, for packets to relay \>

    -   current

    -   start

    -   relayclientstart

-   Output - The above steps will relay the UDP packet from the host address set using the **relayclienthost** command to the destination address set by the command **relayhost**.

    The relay packet will be received at the port set by command **relayport**.


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM E5X Family](../../docs/GUID-30573197-7C83-4B97-BBF2-7CA462FAE748.md)

