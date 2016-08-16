#include <Arduino.h>
#include "VdoPressureSender.h"

VdoPressureSender::VdoPressureSender(int analogPin, unsigned int dataTable[11]) {
  _debug = false;

  for(int i = 0; i < 11; i++) {
      _dataTable[i] = dataTable[i];
  }

	_analogPin = analogPin;
  //memcpy(&dataTable, _dataTable, 11 * sizeof(unsigned int));
}

double VdoPressureSender::getPressure() {
	  // Read raw value 0 - 1023
  	int rawValue = analogRead(_analogPin);

  	// Debug
    if (_debug) {
      	Serial.println(" === VDO Pressure Sender === ");
      	Serial.print("Analog Pin: ");
      	Serial.println(_analogPin);
      	Serial.print("RAW Value: ");
      	Serial.println(rawValue);
      	Serial.println("");
    }
  
  	// Convert to PSI / Bar
  	double pressure = 0;

  	//This searches the 2 surrounding values, and then linear interpolates between them.
  	for(int i = 0; i < 10; i++)
  	{
    		if(rawValue >= _dataTable[i] && rawValue <= _dataTable[i + 1])
    		{
      			pressure = i + ( (rawValue - _dataTable[i]) / (1.0f * (_dataTable[i + 1] - _dataTable[i]) ) );
      			break;
    		}
  	}  
  	
  	return pressure;
}

void VdoPressureSender::debug(bool debug) {
    _debug = debug;
}