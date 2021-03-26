#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include <Arduino.h>
#include <Sensors/analog_sensor.h>

class TemperatureSensor : public AnalogSensor { 
    public:
        TemperatureSensor(uint8_t id, uint8_t pin):AnalogSensor(id, pin, 0.05){}
};

#endif