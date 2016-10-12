/*
  ESP_ConfigStorage.h - EEPROM variable library
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

#ifndef ESP_ConfigStorage_H
#define ESP_ConfigStorage_H

class Storage {
  private:
    Storage();
    uint16_t _startAddr;

    String getEEPROM(uint16_t startAddr, uint16_t endAddr);
    boolean setEEPROM(uint16_t startAddr, uint16_t endAddr, String data);

  public:
    Storage(uint16_t);
    Storage(uint16_t, uint16_t);

    void clear();

    // wifimode
    String getWiFiMode();
    boolean setWiFiMode(String data) ;

    // ssid
    String getSSID() ;
    boolean setSSID(String data);

    // encryption
    boolean getProtection();
    void setProtection(byte data);

    // pass
    String getPassword() ;
    boolean setPassword(String data);

    // host
    String getHostname();
    boolean setHostname(String data);

    // ipmode
    boolean getConfigMode();
    void setConfigMode(byte data);

    // ip
    String getIP();
    boolean setIP(String data);

    // gateway
    String getGateway();
    boolean setGateway(String data);

    // subnet
    String getSubnet();
    boolean setSubnet(String data);

    void finalize();
};

#endif
