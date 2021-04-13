#ifndef LEDRGB_H
#define LEDRGB_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/Direction.h>

class LedRGB : public ActuatorABS<Direction> {
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
        void write(Direction value);
};

void LedRGB::write(Direction value){
    float R = 0;
    float G = 0;
    float B = 0;
    
    if (value.getValue() == 1){
        R = 0;
        G = 255;
        B = 0;
    }
    if(value.getValue() == 2){
        R = 255;
        G = 0;
        B = 0;
    }
    if(value.getValue() == 3){
        R = 0;
        G = 0;
        B = 0;
    }

    if(value.getValue() != 0){
        analogWrite(this->pinR, R);
        analogWrite(this->pinG, G);
        analogWrite(this->pinB, B);
    }  
}


#endif