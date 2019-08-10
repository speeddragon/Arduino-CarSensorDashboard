# Arduino - Car Sensor Dashboard

This repository contains C/C++ code to read and display (via Bluetooth) car sensor values. The code was create to get information from:

- Pressure Sender
- Temperature Sender
- MPX4250AP (Pressure sensor)

## Diagram

Sender Diagram

![Circuit diagram](/diagram.png)

This is just a simple voltage divider circuit with a 0.1 uF capacitor to help stabilize the signal.

10K Ohms is used in both senders.

On the water temperature sender, I used 4.7 k ohms.
On the oil temperature sender, I used 330 ohms.
On the oil pressure sender, I used 100 ohms.

This values can change to match the sender resistor range for the values you want more precision.

## Sensors

I have bought 3 eBay senders, two temperature sender and one pressure sender.

* 1/8 NPT Oil/Water TEMPERATURE TEMP Sender Sensor fits Autometer VDO Smiths Gauge (**hosefittingsuk**)
* Oil Pressure Electronic Sensor/Sender Replacement Universal Fit Gauge 1/8" NPT (**mcgillmotorsports**)
* Aftermarket Gauge Universal 1/8 NPT Oil / Water Temp Temperature Sensor Sender (**aggressive_gauges_ltd**)

All the calculations with voltage divider and sensor mapping is done in this google drive sheet: https://docs.google.com/spreadsheets/d/1dIEgK2CFQV0UKZFhlpiRPlZvceNms4iL4nMmq7J9Fz0

## Installation

* Copy the folders inside folder **lib** to your arduino libraries.
* Open **car_sensor_dashboard.ino** inside car_sensor_dashboard folder.
