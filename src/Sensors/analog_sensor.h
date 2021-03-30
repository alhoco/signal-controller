#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include <Arduino.h>
#include <Sensors/sensor.h>


class AnalogSensor : public SensorABS<float> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin, float scale=1):SensorABS<float>(id){
            this->pin = pin;
            this->scale = scale;
        }

    private: 
        uint8_t pin;
        float read();
        float transform(uint16_t value);
        float scale;
};


float AnalogSensor::transform(uint16_t value){
    return (value)*this->scale;
}

float AnalogSensor::read(){
    uint16_t value = analogRead(this->pin);
    return this->transform(value);
}

#endif
