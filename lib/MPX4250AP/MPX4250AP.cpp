#include <Arduino.h>
#include "MPX4250AP.h"

MPX4250AP::MPX4250AP(int analogPin) {
	_analogPin = analogPin;
}

double MPX4250AP::getPressure() {
	int rawValue = analogRead(_analogPin);

	// Debug
	/*Serial.println(" === MPX4250AP === ");
	Serial.print("Analog Pin: ");
  	Serial.println(_analogPin);
	Serial.print("RAW Value: ");
	Serial.println(rawValue);
	Serial.println("");*/

	// kPa
	// .00488 = 5/1024
	// .02246 is the range of the sensor divided by 1024 (230 kPa / 1024)
	// 20 is the lowest number

	// Formula info:
	//   - http://forum.arduino.cc/index.php?topic=16136.0
    
    double boost = (rawValue * (.00488)/(.022)+20); //Converts raw MAP value to kPa
	//double boost = 250 * rawValue / 1023.0 + 10; // the .0 forces floating-point math instead of integer math.
    
    // 1.01325 - Atmosphere pressure
    double boostBar = boost / 100.0 - 1.01325;

  	//double voltage = rawValue / 204.8;
  	//double pressure = 0.037711935 * (rawValue - 41);
  	
  	return boostBar;
}