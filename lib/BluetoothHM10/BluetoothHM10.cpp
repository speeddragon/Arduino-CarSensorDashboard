#include "Arduino.h"
#include "BluetoothHM10.h"

BluetoothHM10::BluetoothHM10(int rxPin, int txPin, SoftwareSerial* serial) {
	pinMode(txPin, OUTPUT);
  	pinMode(rxPin, INPUT);

  	delay(500);

    if (NULL != _serial)
    {
        delete _serial;
    }

    _serial = serial;
    
    //_serial = new SoftwareSerial(rxPin, txPin);
	_serial->begin(9600);
}

BluetoothHM10::~BluetoothHM10() 
{
    if (NULL != _serial)
    {
        delete _serial;
    }
}

void BluetoothHM10::initialize() {
	//sendCommand("AT+NAMEDashboard");
	//sendCommand("AT+PIN0000");
	//sendCommand("AT+BAUD0");
}

void BluetoothHM10::sendCommand(char command[]) {
    if (_debug) {
        Serial.print("BT command: ");
        Serial.println(command);
    }

	char serialData;
   	_serial->print(command);
   	
   	delay(1000);
   	while (_serial->available()) {
    	serialData = _serial->read();
    	delay(100);
  	}

  	if (_debug) {
        Serial.println();
    }

    _serial->flush();
}

void BluetoothHM10::printDouble(double value, unsigned int precision) {

    // Prints the int part
    _serial->print(int(value));  
    // Print the decimal point
    _serial->print("."); 
    
    unsigned int frac;
    
    if(value >= 0) {
        frac = (value - int(value)) * precision;
    } else {
        frac = (int(value) - value ) * precision;
    }

    int frac1 = frac;
    
    while( frac1 /= 10 ) {
        precision /= 10;
    }
    
    precision /= 10;

    while( precision /= 10) {
        _serial->print("0");
    }

    _serial->println(frac, DEC) ;
}

void BluetoothHM10::debug(bool debug) {
  _debug = debug;
}

void BluetoothHM10::printKeyValue(char key[], char value[]) {
    _serial->print(key);
    _serial->print(": ");
    _serial->println(value);
}
void BluetoothHM10::printKeyValue(char key[], int value) {
    _serial->print(key);
    _serial->print(": ");
    _serial->println(value);
}
void BluetoothHM10::printKeyValue(char key[], double value) {
    _serial->print(key);
    _serial->print(": ");
    printDouble(value, 100);
}
void BluetoothHM10::print(char string[]) {
    _serial->print(string);
}
void BluetoothHM10::println(char string[]) {
    _serial->println(string);
}
