#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include <entities/value.h>

class State : public ValueABS<bool> {
    public: 
        State():ValueABS(){};
        State(bool value, uint8_t source) : ValueABS(value, source){};
};

#endif