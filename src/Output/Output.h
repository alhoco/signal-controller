#ifndef OUTPUT_H
#define OUTPUT_H
#define Compressor 2
#define Amperage A1

#include <Arduino.h>

void setup() {
    pinMode(Compressor, LOW);
}

namespace output{
    int compressor_state = 0;
    int last_compressor_state = 0;

    void Output(float input, float setpoint){
        
        if (input >= setpoint){
            digitalWrite(Compressor, HIGH);
            compressor_state = 1;
        }
        else {
            digitalWrite(Compressor, LOW);
            compressor_state = 0;
        }
        delay(3000);

        float compressor_amperage = analogRead(A1);
        if (compressor_amperage < 0){
            last_compressor_state = compressor_state;
            compressor_state = 0;
        }
        else {
            last_compressor_state = compressor_state;
        }
        
    }
}

#endif