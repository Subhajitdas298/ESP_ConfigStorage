#include "Arduino.h"
#include <EEPROM.h>  // reuired for EEPROM opertaions
#include "ESP_ConfigStorage.h"

/*
  ESP_ConfigStorage.cpp - EEPROM variable library
  Copyright (c) 2016 Subhajit Das.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 3.0 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
      Data storage structure:

     ----------------------
     | Size  | Variable   |
     ----------------------
     |  10   | wifimode   |
     |  30   | ssid       |
     |  1    | protection |
     |  70   | pass       |
     |  20   | host       |
     |  1    | configmode |
     |  15   | ip         |
     |  15   | gateway    |
     |  15   | subnet     |
     ----------------------
*/

#define WIFI_MODE_START (_startAddr)
#define WIFI_MODE_END (WIFI_MODE_START+9)

#define SSID_START (WIFI_MODE_END+1)
#define SSID_END (SSID_START+29)

#define PROTECTION (SSID_END+1)

#define PASSWORD_START (PROTECTION+1)
#define PASSWORD_END (PASSWORD_START+69)

#define HOST_START (PASSWORD_END+1)
#define HOST_END (HOST_START+19)

#define CONFIG_MODE (HOST_END+1)

#define IP_START (CONFIG_MODE+1)
#define IP_END (IP_START+14)

#define GATEWAY_START (IP_END+1)
#define GATEWAY_END (GATEWAY_START+14)

#define SUBNET_START (GATEWAY_END+1)
#define SUBNET_END (SUBNET_START+14)

Storage::Storage(uint16_t startAddress) {
  EEPROM.begin(512);  // initiate EEPROM storage
  _startAddr = startAddress;
}

Storage::Storage(uint16_t startAddress, uint16_t size) {
  EEPROM.begin(size);  // initiate EEPROM storage
  _startAddr = startAddress;
}

void Storage::clear() {
  // clearing EEPROM
  for (uint16_t i = 0; i < 512; ++i) {
    EEPROM.write(i, 0);
  }
}

String Storage::getEEPROM(uint16_t startAddr, uint16_t endAddr) {
  String data = "";
  byte b;
  for (unsigned int i = startAddr; i <= endAddr; ++i) {
    b = EEPROM.read(i);
    if (b == 0 || b == '\n') break;
    data += char(b);
  }
  return data;
}
boolean Storage::setEEPROM(uint16_t startAddr, uint16_t endAddr, String data) {
  if (endAddr < startAddr + data.length() - 1) return false;
  for (byte i = 0; i < data.length(); ++i) {
    EEPROM.write(startAddr + i, data[i]);
  }
  return true;
}

// wifimode
String Storage::getWiFiMode() {
  return getEEPROM(WIFI_MODE_START, WIFI_MODE_END);
}
boolean Storage::setWiFiMode(String data) {
  return setEEPROM(WIFI_MODE_START, WIFI_MODE_END, data);
}

// ssid
String Storage::getSSID() {
  return getEEPROM(SSID_START, SSID_END);
}
boolean Storage::setSSID(String data) {
  return setEEPROM(SSID_START, SSID_END, data);
}

// encryption
boolean Storage::getProtection() {
  return boolean(byte(EEPROM.read(PROTECTION)) != byte(0));
}
void Storage::setProtection(byte data) {
  EEPROM.write(PROTECTION, data);
}

// pass
String Storage::getPassword() {
  return getEEPROM(PASSWORD_START, PASSWORD_END);
}
boolean Storage::setPassword(String data) {
  return setEEPROM(PASSWORD_START, PASSWORD_END, data);
}

// host
String Storage::getHostname() {
  return getEEPROM(HOST_START, HOST_END);
}
boolean Storage::setHostname(String data) {
  return setEEPROM(HOST_START, HOST_END, data);
}

// configmode
boolean Storage::getConfigMode() {
  return boolean(byte(EEPROM.read(CONFIG_MODE)) != byte(0));
}
void Storage::setConfigMode(byte data) {
  EEPROM.write(CONFIG_MODE, data);
}

// ip
String Storage::getIP() {
  return getEEPROM(IP_START, IP_END);
}
boolean Storage::setIP(String data) {
  return setEEPROM(IP_START, IP_END, data);
}

// gateway
String Storage::getGateway() {
  return getEEPROM(GATEWAY_START, GATEWAY_END);
}
boolean Storage::setGateway(String data) {
  return setEEPROM(GATEWAY_START, GATEWAY_END, data);
}

// subnet
String Storage::getSubnet() {
  return getEEPROM(SUBNET_START, SUBNET_END);
}
boolean Storage::setSubnet(String data) {
  return setEEPROM(SUBNET_START, SUBNET_END, data);
}

void Storage::finalize() {
  EEPROM.commit();  // set to eeprom
}
