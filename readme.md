![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Harmony 3 Net library application examples for SAM E5X family

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating embedded firmware solutions for Microchip 32-bit SAM and PIC® microcontroller and microprocessor devices.  Refer to the following links for more information.

- [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
- [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
- [Microchip MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide)
- [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
- [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony 3 Net library application examples for SAM E5X family

- [Release Notes](./release_notes.md)
- [Microchip Software License Agreement](./mplab_harmony_license.md)

# Contents Summary

| Folder     | Description                                               |
| ---        | ---                                                       |
| apps       | Contains Net library example applications        |
| docs       | Contains documentation in html format for offline viewing (to be used only after cloning this repository onto a local machine). Use [github pages](https://microchip-mplab-harmony.github.io/net_apps_sam_e5x/) of this repository for viewing it online.|

## Code Examples

The following applications are provided to demonstrate the typical or interesting usage models of the Net libraries.

| Name | Description |
| ---- | ----------- |
| [berkeley_tcp_client](./docs/GUID-6FA31D77-7E3C-4EB5-B58B-E10F90991924.html) | This example application shows a TCP Client demo using BSD API |
| [berkeley_tcp_server](./docs/GUID-69286689-41F1-431B-8071-509558DEE9D9.html) | This example application shows a TCP Server demo using BSD API |
| [berkeley_udp_client](./docs/GUID-39B797E5-42FA-4460-8888-2F7462A45EE3.html) | This example application shows a UDP Client demo using BSD API |
| [berkeley_udp_relay](./docs/GUID-485BB380-E1FE-43DE-ACC0-FC3AA3523FA7.html) | This example application shows a UDP Relay demo using BSD API |
| [berkeley_udp_server](./docs/GUID-E9DD8AC4-5235-4454-BB17-B0DDC66855AD.html)  | This example application shows a UDP Server demo using BSD API |
| [iperf_demo](./docs/GUID-7C1C777A-DB47-468E-BDAB-9A2EC39C10BA.html) | This example application shows running iperf and measuring the network performance |
| [snmpv3_nvm_mpfs](./docs/GUID-95DE67FE-8022-4837-B877-9FCAA1EC8FCC.html) | This example application shows a SNMP & Web Server with Microchip Proprietary File System (MPFS) in the Non-Volatile Memory (NVM)  |
| [snmpv3_sdcard_fatfs](./docs/GUID-E673648D-D80D-420E-8431-128FF7845E0B.html) | This example application shows a SNMP & Web Server with FAT FS file system on the external SD card |
| [tcpip_client_server](./docs/GUID-14D9CE6F-4B1C-4DCA-9C1C-16C09BA4A647.html) | This example application shows a multi-threaded example with TCP and UDP server and client threads |
| [tcpip_tcp_client](./docs/GUID-A3A06AD9-E780-480B-90A9-9E412408508A.html) | This example application shows a TCP Client demo using Harmony native API |
| [tcpip_tcp_client_server](./docs/GUID-9AD07EE8-CF17-4CF1-8B0E-04CE3342B4BB.html) | This example application shows a TCP Client and Server demo using Harmony native API |
| [tcpip_tcp_demo_at24mac](./docs/GUID-1EDCA93F-0E1F-464C-AFD6-9F3536B0F7EC.html) | This example application shows a TCP Client and Server demo with AT24MAC402 Serial EEPROM using Harmony native API |
| [tcpip_tcp_server](./docs/GUID-F805D35F-1372-46CD-ACEE-DB422E074FF7.html)  | This example application shows a TCP Server demo using Harmony native API |
| [tcpip_udp_client](./docs/GUID-6573C5B0-F3B2-4D8A-B76A-4085DE84C01C.html) | This example application shows a UDP Client demo using Harmony native API |
| [tcpip_udp_client_server](./docs/GUID-D6DF936B-7B1A-4B63-974F-FC9BC863E606.html) | This example application shows a UDP Client and Server demo using Harmony native API|
| [tcpip_udp_server](./docs/GUID-7996BDD3-547C-4FFD-A636-512FE2CC5B6B.html) | This example application shows a UDP Server demo using Harmony native API |
| [web_ftp_server_mpfs_fatfs](./docs/GUID-38E38B4A-FB31-4255-BED2-1ABC7D9ACC31.html)| This example application shows a Web server using NVM MPFS and FTP server using SDCARD FATFS|
| [web_ftp_server_usb_fatfs](./docs/GUID-49B2B1BB-EE09-482D-9E34-B4C7AAEE8763.html)| This example application shows a Web server and FTP server with FAT FS file system on the USB flash device |
| [web_net_server_nvm_mpfs](./docs/GUID-3BB2E2CC-A2C4-40CE-A62F-6654D529F641.html) | This example application shows a Web server with Microchip Proprietary File System (MPFS) in the Non-Volatile Memory (NVM) |
| [web_net_server_ppp](./docs/GUID-6D221AB7-FFCE-47BD-8DDE-83C275ED22A1.html) | This example application shows creating an PPP interface and a Web server with Microchip Proprietary File System (MPFS) in the Non-Volatile Memory (NVM) |
| [web_net_server_sdcard_fatfs](./docs/GUID-4156D7F7-CCE8-4EB0-8BD7-5BFDD8A03E54.html) | This example application shows a Web server with FAT FS file system on the external SD card |
| [wolfmqtt_demo](./docs/GUID-D762E200-A0F5-4E17-9281-92D461CCB715.html) | This example application demonstrates a simple MQTT application using the 3rd party wolfMQTT library |
| [wolfssl_tcp_client](./docs/GUID-B87BF4E5-DB14-4557-9D56-1EA7DB070F94.html) | This example application shows a connection to a Web server using TLS to encrypt the connection with wolfSSL |
| [wolfssl_tcp_server](./docs/GUID-6AA84A41-A602-45EA-8EDB-9F8C86FAF9C6.html) | This example application shows Web server demo accepting encrypted TLS connections using wolfSSL |
____


[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_e5x/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_e5x/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_e5x/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg)](https://github.com/Microchip-MPLAB-Harmony/net_apps_sam_e5x/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/net_apps_sam_e5x.svg?style=social)]()


