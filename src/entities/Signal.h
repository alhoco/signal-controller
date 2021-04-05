#ifndef SIGNAL_H
#define SIGNAL_H

#include <Arduino.h>
#include <entities/Value.h>

class Signal : public ValueABS<float> {
    public:
        Signal():ValueABS(){};
        Signal(float value, uint8_t source):ValueABS(value,source){};
};

#endif
