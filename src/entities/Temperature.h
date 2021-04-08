#ifndef TEMPERATURE_H
#define TEMPERATURE_H_

#include <Arduino.h>
#include <entities/Value.h>

class Temperature : public ValueABS<float> {
    public:
        Temperature():ValueABS(){};
        Temperature(float value, uint8_t source):ValueABS(value,source){};
       // float getValue();
    private:
        //float value;

};
/*
float Temperature::getValue(){
    return this->value;
}*/

#endif