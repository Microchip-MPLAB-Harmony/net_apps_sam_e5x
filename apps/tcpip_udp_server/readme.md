# TCP/IP UDP Server

The UDP Server configuration demonstrates creating a network server that uses the MPLAB Harmony UDP API to create a UDP/IP echo server on port 9760.

**TCP/IP UDP Server MHC Configuration**

The following Project Graph diagram shows the Harmony components included in this application demonstration.

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

    TCP/IP demo use these application module components for this demo.

    **Announce** module to discover the Microchip devices within a local network.

    **DHCP Client** module to discover the IPv4 address from the nearest DHCP Server.

    **DNS Client** provides DNS resolution capabilities to the stack. During these components selection, the required transport and network modules are also selected.

    ![tcpip_same54_project](../../docs/GUID-C45E588C-5E86-4A94-B09D-4B4C6F05040C-low.png)

-   **TCPIP Driver Layer**

    **Internal ethernet driver\(gmac\)** is enabled with the external **KSZ8091 PHY driver** library for SAME54 demonstartion.

    ![tcpip_same54_project](../../docs/GUID-CA9BB7EB-854A-41AA-B6AB-324BC76EDB9D-low.png)

    The MIIM Driver supports asynchronous read/write and scan operations for accessing the external PHY registers and notification when MIIM operations have completed.


**TCP/IP UDP Server Hardware Configuration**

This is the following section describes the hardware configuration used for this application demonstration.

1.  This section describes the required default hardware configuration use USB device as **on board debugger and programmer** for this application demonstration.

    -   No hardware related configuration or jumper setting changes are necessary

    -   Refer to the SAM E54 Ethernet Starter Kit [User Guide](http://ww1.microchip.com/downloads/en/DeviceDoc/70005321A.pdf)

        ![required_hardware](../../docs/GUID-38FBEB65-FF92-4E6E-BD39-95B6DFEA5091-low.png)

    -   Connect the micro USB cable from the computer to the DEBUG USB connector on the SAM E54 Xplained Pro Evaluation Kit

    -   Establish a connection between the router/switch with the SAM E54 Xplained Pro Evaluation Kit through the RJ45 connector

    ![required_hardware](../../docs/GUID-EC77D4D8-500E-4398-B7ED-1E0C339FED16-low.png)


**TCP/IP UDP Server Running Application**

This table list the name and location of the MPLAB X IDE project folder for the demonstration.

|Project Name|Target Device|Target Development Board|Description|
|------------|-------------|------------------------|-----------|
|sam\_e54\_xpro.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the UDP Server on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Bare Metal \( non-RTOS\).|
|sam\_e54\_xpro\_freertos.X|ATSAME54P20A|ATSAM E54 Xplained pro|Demonstrates the UDP Server on development board with ATSAME54P20A device and KSZ8091 PHY daughter board. This implementation is based on Freertos.|

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

    1.  As soon as a valid IP address is assigned through the DHCP to the demonstration, it is ready to accept a UDP/IP connection on port 9760.

    2.  Send a UDP packet to the IP address of the hardware board and port 9760 from any UDP Client application running on the computer \(SocketTest, Packet Sender etc\).

    3.  The UDP Server demonstration running on the evaluation kit will echo back everything it receives along the connection.


**Parent topic:**[MPLAB® Harmony 3 TCP/IP Application for SAM E5X Family](../../docs/GUID-30573197-7C83-4B97-BBF2-7CA462FAE748.md)

