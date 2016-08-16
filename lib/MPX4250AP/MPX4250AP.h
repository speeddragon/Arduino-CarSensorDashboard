/*
	MPX4250AP.h
*/
#ifndef MPX4250AP_h
#define MPX4250AP_h

#include <Arduino.h>

class MPX4250AP
{
	public: 
		MPX4250AP(int analogPin);
		double getPressure();

	private:
		int _analogPin;
};

#endif