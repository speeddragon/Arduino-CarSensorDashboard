/*
	VDO Pressure Sender
*/
#ifndef VdoPressureSender_h
#define VdoPressureSender_h

#include <Arduino.h>

class VdoPressureSender
{
	public: 
		VdoPressureSender(int analogPin, unsigned int dataTable[11]);
		double getPressure();
		void debug(bool debug);

	private:
		int _analogPin;
		bool _debug;
		unsigned int _dataTable[11];
};

#endif