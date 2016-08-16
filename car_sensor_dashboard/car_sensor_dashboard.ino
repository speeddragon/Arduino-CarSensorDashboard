#include <SoftwareSerial.h>

#include <stdlib.h> // for malloc and free
void* operator new(size_t size) { return malloc(size); } 
void operator delete(void* ptr) { free(ptr); }

#include <VdoTemperatureSender.h>
#include <VdoPressureSender.h>
#include <MPX4250AP.h>

#include <BluetoothHM10.h>

// Oil Pressure Table
unsigned int vdoPressure[] =
{
  	61,
        160,
        231,
        280,
        320,
        349,
        374,
        394,
        411,
        425,
        437
};

// Oil Temperature Table
/**
 * Ref: 60ºC - 430 Ohms |  150ºC - 33 Ohms
 */
unsigned int vdoTemp[] =
{ 
  	644,
	628,
	599,
	560,
	509,
	450,
	385,
	322,
	261,
	210,
	168,
	133,
	104,
	81,
	68,
	58
};

// Water Temperature Table
/**
 * Each line is a 10ºC increase, starting from 0ºC to 150ºC
 */
unsigned int agressiveTemp[] =
{ 
  	656,
	647,
	630,
	609,
	575,
	537,
	489,
	421,
	345,
	319,
	283,
	263,
	252,
	246,
	243,
	242
};


// Bluetooth Config
#define BT_TX 3
#define BT_RX 2
BluetoothHM10 *bluetooth;
SoftwareSerial bluetoothSerial(BT_RX, BT_TX);

MPX4250AP *turboSensor;
VdoPressureSender *oilPressureSensor;
VdoTemperatureSender *waterTemperatureSensor;
VdoTemperatureSender *oilTemperatureSensor;

void setup() {
    Serial.begin(9600);

    bluetooth = new BluetoothHM10(BT_RX, BT_TX, &bluetoothSerial);
    bluetooth->initialize();

    // Initialize car sensors
    turboSensor = new MPX4250AP(A4);
    
    oilPressureSensor = new VdoPressureSender(A3, vdoPressure);    
    waterTemperatureSensor = new VdoTemperatureSender(A1, agressiveTemp);
    oilTemperatureSensor = new VdoTemperatureSender(A2, vdoTemp);
}

void loop() {
    // Turbo
    double turboPressure = turboSensor->getPressure();
    bluetooth->print("Turbo: ");
    bluetooth->printDouble(turboPressure, 100);
    Serial.print("Turbo: ");
    Serial.println(turboPressure);

    // Oil Pressure
    double oilPressure = oilPressureSensor->getPressure();
    bluetooth->print("Oil P:");
    bluetooth->printDouble(oilPressure, 100);
    Serial.print("Oil P: ");
    Serial.println(oilPressure);

    // Oil Temperature
    int oilTemperature = oilTemperatureSensor->getTemperature();
    bluetooth->printKeyValue("Oil T", oilTemperature);
    Serial.print("Oil T: ");
    Serial.println(oilTemperature);

    // Water
    int waterTemperature = waterTemperatureSensor->getTemperature();
    bluetooth->printKeyValue("Water T", waterTemperature);
    Serial.print("Water T: ");
    Serial.println(waterTemperature);

    Serial.println("---------------");
    //bluetooth->println("--------");
    delay(3000);
}
