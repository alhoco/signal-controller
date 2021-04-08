#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <Arduino.h>

bool Compressor_Validation(bool Alarm_value, bool Compressor_Instruction){
    bool validation = false;

    if(Alarm_value){
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