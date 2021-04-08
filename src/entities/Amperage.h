#ifndef AMPERAGE_H
#define AMPERAGE_H

#include <Arduino.h>
#include <entities/value.h>

class Amperage : public ValueABS<float> {
    public:
        Amperage():ValueABS(){};
        Amperage(float value, uint8_t source):ValueABS<float>(value, source){}
};

#endif