# TCP/IP WolfSSL TCP Server

This configuration demonstrates creating a simple Internet Web server, that operates with clear text \(TCP Port 80\), and with encrypted text \(TCP Port 443\). If IPv6 is enabled than the demonstration also serves both types of connections on IPv6. The Web server only serves one page with the text 'Nothing Here' to all Web clients.

This demonstration uses the NET\_PRES layer for encrypted communication through an external service provider for TLS support.

**TCP/IP TCP WolfSSL Server MHC Configuration**

The following Project Graph diagram shows the Harmony components included in the TCP Client demonstration application.

-   MHC is launched by selecting **Tools \> Embedded \> MPLAB® Harmony 3 Configurator** from the MPLAB X IDE and after successful database migration , TCP/IP demo project is ready to be configured and regenerated.

    ![tcpip_same54_project](GUID-BDCABA15-8CFC-4BBD-B152-813303321FF6-low.png)

-   **TCP/IP Root Layer Project Graph**

    The root layer project shows that SERCOM2 peripheral is selected to do read and write operation for TCP/IP commands.

    This is the basic configuration with SYS\_CONSOLE, SYS\_DEBUG and SYS\_COMMAND modules. These modules are required for TCP/IP command execution.

    ![tcpip_same54_project](GUID-F3FD195C-7FDC-4331-9534-422C41289999-low.png)

    **NOTE:-****FreeRTOS** component is required for RTOS application. For bare-metal \(non-RTOS\) **FreeRTOS** component should not be selected.

    The below snapshot provides the details of the wolfssl\_crypto, wolfSSL and presentation layer configuration.

    ![tcpip_same54_project](GUID-187EE6EB-A1A2-4888-A780-0B94BA2536BD-low.png)

    TCP sockets calculate the ISN using the wolfSSL crypto library.

-   **TCP/IP Required Application**

    TCP/IP demo use these application module components for this demo.

    **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **DNS Client** provides DNS resolution capabilities to the stack. During these components selection, the required transport and network modules are also selected.

    ![tcpip_wolfssl_tcp_client_project](GUID-C45E588C-5E86-4A94-B09D-4B4C6F05040C-low.png)

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8091 PHY driver** library for SAME54 demonstartion.

    ![tcpip_same54_project](GUID-CA9BB7EB-854A-41AA-B6AB-324BC76EDB9D-low.png)

    For **SAM V71** demonstration , **LAN8061 PHY driver** ia selcted along with GMAC **Internal ethernet driver**.

    ![tcpip_same54_project](GUID-187EE6EB-A1A2-4888-A780-0B94BA2536BD-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP TCP WolfSSL Server Hardware Configuration**

This is the following section describes the hardware configuration used for this application demonstration.

1.  This section describes the required default hardware configuration use USB device as **on board debugger and programmer** for this application demonstration.

    -   No hardware related configuration or jumper setting changes are necessary

    -   Refer to the SAM E54 Ethernet Starter Kit [User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/70005321A.pdf)

        ![required_hardware](GUID-38FBEB65-FF92-4E6E-BD39-95B6DFEA5091-low.png)

    -   Connect the micro USB cable from the computer to the DEBUG USB connector on the SAM E54 Xplained Pro Evaluation Kit

    -   Establish a connection between the router/switch with the SAM E54 Xplained Pro Evaluation Kit through the RJ45 connector

    ![required_hardware](GUID-EC77D4D8-500E-4398-B7ED-1E0C339FED16-low.png)


**TCP/IP WolfSSL TCP Server Running Application**

This table list the name and location of the MPLAB X IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_e54\_xpro.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the wolfSSL TCP Server on a development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This is a bare-metal \(non-RTOS\) implementation. WolfSSL Hardware crypto enabled|
|sam\_e54\_xpro\_freertos.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the wolfSSL TCP Server on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Freertos.|
|sam\_e70\_xult\_sw.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the wolfSSL TCP Server on a development board with ATSAME54P20A device with and KSZ8091 PHY daughter board. This is a bare-metal \(non-RTOS\) implementation. WolfSSL Software crypto enabled|

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

    As soon as a valid IP address is assigned through the DHCP to the demonstration, it is ready to serve Web pages.

    The demonstration does not offer any additional functionality through the serial port; however, the current IP can be checked.

    Use any Web browser \(i.e., Chrome, Internet Explorer, Firefox, etc.\) to connect to the Web server with either http:// or https://.


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM E5X Family](GUID-30573197-7C83-4B97-BBF2-7CA462FAE748.md)

