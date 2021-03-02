#ifndef OUTPUT_H
#define OUTPUT_H
#define Compressor 2

#include <Arduino.h>

void setup() {
    pinMode(Compressor, LOW);
}

namespace output{
    int compressor_state = 0;
    int last_compressor_state = 0;

    void Output(float input, float setpoint){
        
        last_compressor_state = compressor_state;
        
        if (input >= setpoint){
            digitalWrite(Compressor, HIGH);
            compressor_state = 1;
        }
        else {
            digitalWrite(Compressor, LOW);
            compressor_state = 0;
        }
    }
}

#endif