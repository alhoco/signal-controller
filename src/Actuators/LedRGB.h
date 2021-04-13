#ifndef LEDRGB_H
#define LEDRGB_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/Direction.h>

class LedRGB : public ActuatorABS<Signal> {
    public:
        LedRGB(uint8_t id, uint8_t pinR, uint8_t pinG, uint8_t pinB):ActuatorABS(id){
            this->pinR = pinR;
            this->pinG = pinG;
            this->pinB = pinB;
        }
    private:
        uint8_t pinR;
        uint8_t pinG;
        uint8_t pinB;
        void write(Signal value);
};

void LedRGB::write(Signal value){
    float R = 0;
    float G = value.getValue();
    float B = 0;

    if(value.getValue() != 0){
        analogWrite(this->pinR, R);
        analogWrite(this->pinG, G);
        analogWrite(this->pinB, B);
    }  
}


#endif