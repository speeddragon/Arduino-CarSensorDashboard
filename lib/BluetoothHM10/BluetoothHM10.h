/*
	HM10.h

	AC-BT-V4 -> PIN must be 0 digit, BAUD0 = 9600
	blue/green -> BAUD4 = 9600
*/
#ifndef BluetoothHM10_h
#define BluetoothHM10_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class BluetoothHM10
{
	public: 
		BluetoothHM10(int rxPin, int txPin, SoftwareSerial* serial);
		~BluetoothHM10();
		void initialize();
		void sendCommand(char command[]);
		void print(char string[]);
		void println(char string[]);
		void printDouble(double value, unsigned int precision);
		void printKeyValue(char key[], char value[]);
		void printKeyValue(char key[], int value);
		void printKeyValue(char key[], double value);
		void debug(bool debug);

	private:
		SoftwareSerial* _serial;
		bool _debug;
};

#endif