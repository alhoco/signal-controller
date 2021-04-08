#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <Arduino.h>
#include <entities/Amperage.h>

bool Compressor_Validation(Amperage Amp, Amperage Amperage_Setpoint, bool Compressor_Instruction){
    bool validation = false;

    if(Amp.getValue() >= Amperage_Setpoint.getValue()){
       validation = false;  
    }
    else{
        if(Compressor_Instruction){
            validation = true;
        }
    }
    return validation;
}

bool Alarm_Validation(bool Compressor_value){
    bool validation = false;

    if(Compressor_value){
        validation = true;
    }
    else{
        validation = false;
    }
    return validation;

}

#endif