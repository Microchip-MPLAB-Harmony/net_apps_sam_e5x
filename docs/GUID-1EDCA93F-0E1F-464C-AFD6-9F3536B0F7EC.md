# TCP/IP TCP Client

The TCP Client configuration demonstrates creating a network client with the MPLAB Harmony TCP API to make a TCP/IP connection to a web server.

**TCP/IP TCP Client Using ATMAC MHC Configuration**

The following Project Graph diagram shows the Harmony components included in the TCP Client demonstration application.

-   MHC is launched by selecting **Tools \> Embedded \> MPLAB® Harmony 3 Configurator** from the MPLAB X IDE and after successful database migration , TCP/IP demo project is ready to be configured and regenerated.

    ![tcpip_same54_project](GUID-BDCABA15-8CFC-4BBD-B152-813303321FF6-low.png)

-   **TCP/IP Root Layer Project Graph**

    The root layer project shows that SERCOM2 peripheral is selected to do read and write operation for TCP/IP commands.

    This is the basic configuration with SYS\_CONSOLE, SYS\_DEBUG and SYS\_COMMAND modules. These modules are required for TCP/IP command execution.

    ![tcpip_same54_project](GUID-187EE6EB-A1A2-4888-A780-0B94BA2536BD-low.png)

    The Two-wire Interface \(TWIHS\) interconnects components on a unique two-wire bus. It is used with Two-wire Interface bus Serial EEPROM \( ATMAC \) , I²C-compatible device.

    TCP sockets calculate the ISN using the wolfSSL crypto library.

-   **TCP/IP Required Application**

    TCP/IP demo use these application module components for this demo. **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **DNS Client** provides DNS resolution capabilities to the stack.

    ![tcpip_same54_project](GUID-C45E588C-5E86-4A94-B09D-4B4C6F05040C-low.png)

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8091 PHY driver** library for SAME54 demonstartion.

    ![tcpip_same54_project](GUID-CA9BB7EB-854A-41AA-B6AB-324BC76EDB9D-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP TCP Client Using ATMAC Hardware Configuration**

This is the following section describes the hardware configuration used for this application demonstration.

1.  This section describes the required default hardware configuration use USB device as **on board debugger and programmer** for this application demonstration.

    -   No hardware related configuration or jumper setting changes are necessary

    -   Refer to the SAM E54 Ethernet Starter Kit [User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/70005321A.pdf)

        ![required_hardware](GUID-38FBEB65-FF92-4E6E-BD39-95B6DFEA5091-low.png)

    -   Connect the micro USB cable from the computer to the DEBUG USB connector on the SAM E54 Xplained Pro Evaluation Kit

    -   Establish a connection between the router/switch with the SAM E54 Xplained Pro Evaluation Kit through the RJ45 connector

    ![required_hardware](GUID-EC77D4D8-500E-4398-B7ED-1E0C339FED16-low.png)


**TCP/IP TCP Client Using ATMAC Running Application**

This table list the name and location of the MPLAB X IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_e54\_xpro.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the TCP Client using ATMAC on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Bare Metal \( non-RTOS\).|

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

3.  Execution :

    1.  After the successful broad bring up, the console output becomes

        ![tcpip_tcp_client_project](GUID-CE6E0D68-FDCA-46C8-B789-4BD368A91073-low.png)

    2.  Input the following command from the serial port:

        openurl < url \> - The < url \> argument must be a fully formed URL; for instance, http://www.microchip.com/

    3.  After the command is input, the demonstration will make a DNS query. Then it will open a connection to the requested URL and perform a simple HTTP GET command.

    4.  The response received from the server will be printed on the terminal application through the serial port.

    5.  For TCP Client test, input the following command from the serial port: **openurl < url \>** - The < url \> argument must be a fully formed URL; for instance, http://www.microchip.com/.

        For this above URL , the DNS module will make a DNS query. Then it will open a connection to the requested URL and perform a simple HTTP GET command. The response received from the server will be printed on the terminal application through the serial port.

        The expected output -

        ![tcpip_tcp_client_project](GUID-9129EB87-8A1A-4145-9570-0F59153C20B2-low.png)


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM E5X Family](GUID-30573197-7C83-4B97-BBF2-7CA462FAE748.md)

