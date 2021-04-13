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

int RGBDirection(bool CompressorDirection, bool Validation){
    int Direction = 0;
    if(CompressorDirection){
        if(Validation){
            Direction = 1;
        }
        else{
            Direction = 2;
        }
    }
    else{
        Direction = 0;
    }
    return Direction;
}

#endif