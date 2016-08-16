# Arduino - Car Sensor Dashboard

This repository contains C/C++ code to read and display (via Bluetooth) car sensor values. The code was create to get information from:

- Pressure Sender
- Temperature Sender
- MPX4250AP (Pressure sensor)

## Diagram

The layout of the components can be seen here: https://circuits.io/circuits/2527463-car-sensor-controller/

A more detail diagram with all connections, including bluetooth and MPX4250AP will be added latter.

## Sensors

I have bought 3 eBay senders, two temperature sender and one pressure sender.

* 1/8 NPT Oil/Water TEMPERATURE TEMP Sender Sensor fits Autometer VDO Smiths Gauge (**hosefittingsuk**)
* Oil Pressure Electronic Sensor/Sender Replacement Universal Fit Gauge 1/8" NPT (**mcgillmotorsports**)
* Aftermarket Gauge Universal 1/8 NPT Oil / Water Temp Temperature Sensor Sender (**aggressive_gauges_ltd**)

All the calculations with voltage divider and sensor mapping is done in this google drive sheet: https://docs.google.com/spreadsheets/d/1dIEgK2CFQV0UKZFhlpiRPlZvceNms4iL4nMmq7J9Fz0

## Installation

* Copy the folders inside folder **lib** to your arduino libraries.
* Open **car_sensor_dashboard.ino** inside car_sensor_dashboard folder.
