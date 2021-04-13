#ifndef DIRECTION_H
#define DIRECTION_H

#include <Arduino.h>
#include <entities/value.h>

class Direction : public ValueABS<int> {
    public: 
        Direction():ValueABS(){};
        Direction(int value, uint8_t source) : ValueABS(value, source){};
};

#endif