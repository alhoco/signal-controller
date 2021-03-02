#ifndef OUTPUT_H
#define OUTPUT_H
#define Compressor 2

#include <Arduino.h>

void setup() {
    pinMode(Compressor, LOW);
}

namespace output{

    void Output(float input, float setpoint){
        if (input >= setpoint){
            digitalWrite(Compressor, HIGH);
        }
        else {
            digitalWrite(Compressor, LOW);
        }
    }
}

#endif