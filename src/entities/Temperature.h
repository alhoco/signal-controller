#ifndef TEMPERATURE_H
#define TEMPERATURE_H_

#include <Arduino.h>
#include <entities/Value.h>

class Temperature : public ValueABS<float> {
    public:
        Temperature():ValueABS(){};
        Temperature(float value, uint8_t source):ValueABS(value,source){};
};

#endif