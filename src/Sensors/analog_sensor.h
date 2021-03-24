#ifndef ANALOG_SENSOR_H
#define aNALOG_SENSOR_H

#include <Arduino.h>
#include <Sensors/sensor.h>

class analogsensor : public SensorABS<int> {
    public:
        analogsensor(uint8_t id, uint8_t pin):SensorABS<int>(id){
            this->pin = pin;
        }
    private: 
        uint8_t pin;
        int read();
};

int analogsensor::read(){
    return analogRead(this->pin);
}

#endif
