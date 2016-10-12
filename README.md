<<<<<<< HEAD
# ESP8266 ESP_ConfigStorage library 

The ESP_ConfigStorage library is an extension of the standard ESP EEPROM library. It extends the functionality of the original Arduino EEPROM library with:

* Reading, Writing Configuration, passwords, host info etc
* Provided get, set standard naming convension

## Downloading

This package can be downloaded in different manners 


- By directly loading fetching the Archive from GitHub: 
 1. Go to [https://github.com/thijse/Arduino-EEPROMEx](https://github.com/Subhajitdas298/ESP_ConfigStorage)	**
 2. Click the DOWNLOAD ZIP button in the panel on the
 3. Rename the uncompressed folder **Arduino-EEPROMEx-master** to **EEPROMEx**.
 4. You may need to create the libraries subfolder if its your first library.  
 5. Place the **EEPROMEx** library folder in your **arduinosketchfolder/libraries/** folder. 
 5. Restart the IDE.


### For writing:
```
boolean setWiFiMode(String data);
boolean setSSID(String data);
void setProtection(byte data);
boolean setPassword(String data);
boolean setHostname(String data) ;
void setConfigMode(byte data);
boolean setIP(String data);
boolean setGateway(String data);
boolean setSubnet(String data);
```
### For reading:
```
String getWiFiMode();
String getSSID();
boolean getProtection();
String getPassword();
String getHostname();
boolean getConfigMode();
String getIP();
String getGateway();
String getSubnet();
```
## Copyright

ESP_ConfigStorage is provided Copyright © 2016 under LGPL License.
=======
# ESP_ConfigStorage
Simple Configuration storage library for ESP8266

Provides class for storing and retrieving configuration of ESP8266 with ease.
>>>>>>> origin/master
