#include "HDC1080.h"
//#include "Arduino.h"

/*!
 *   @brief  Initialise sensor with given parameters / settings
 *   @param addr the I2C address the device can be found on
 *   @returns true on success, false otherwise
 */
bool HDC1080::begin(void) {
  return init();
}


/*!
 *   @brief  Initialise sensor with given parameters / settings
 *   @returns true on success, false otherwise
 */
bool HDC1080::init(void) {
  	// Default settings: 
	//  - Heater off
	//  - 14 bit Temperature and Humidity Measurement Resolutions
	hdc1080.begin(0x40);

//	Serial.print("Manufacturer ID=0x");
//	Serial.println(hdc1080.readManufacturerId(), HEX); // 0x5449 ID of Texas Instruments
//	Serial.print("Device ID=0x");
//	Serial.println(hdc1080.readDeviceId(), HEX); // 0x1050 ID of the device
    if (hdc1080.readDeviceId() != 0x1050 && hdc1080.readManufacturerId() != 0x5449) {
//	    Serial.println("HDC1080 expected values (Manufacturer ID=0x5449 and Device ID=0x1050) NOT found on I2C Addr. 0x40"); 
        return false;
    }
  return true;
}

/**
 * returns temperature in set resolution (default 14bit)
 * 14bit conversion time: 6.5ms
 */
float HDC1080::readTemperature(void) {
  return hdc1080.readTemperature();
}

/**
 * returns humidity in set resolution (default 14bit)
 * 14bit conversion time: 6.5ms
 */
float HDC1080::readHumidity(void) {
  return hdc1080.readHumidity();
}


