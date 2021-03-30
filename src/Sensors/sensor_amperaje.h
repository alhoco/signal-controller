#ifndef SENSOR_AMPERAJE_H
#define SENSOR_AMPERAJE_H

#include <Arduino.h>
#include <Sensors/analog_sensor.h>

class AmperageSensor : public AnalogSensor {
    public:
        AmperageSensor(uint8_t id, uint8_t pin):AnalogSensor(id, pin, 0.01466){}
};

#endif 