#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>
#include <entities/value.h>
#include <stdlib.h>
#include <Serializers/Printer.h>


template<class T>
T transform(T input, T max_temperature, T max_sensor){
    return (input * max_temperature) / max_sensor;
}

template<class T>
bool desitions(T value, T reference){
    bool desition;
    
    if (value.getValue() > reference.getValue()){
        desition = true;
    }
    else{
        desition = false;
    }
    return bool(desition); 
}


namespace PIDenvironment {
    float oldError = 0;
    float Kp = 1;
    float Ki = 0.3;
    float Kd = 0.01;
    float Error;
    float SumError = 0;
    float ErrorDif = 0;
    float currentTime;
    float ElapsedTime;
    float PreviousTime;
    float Signal;

    template<class T>
    float PID(T value, T Reference){
        currentTime = millis();
        ElapsedTime = currentTime - PreviousTime;


        Error = value.getValue() - Reference.getValue();
        SumError = SumError + (Error * ElapsedTime);
        ErrorDif = (Error - oldError) / ElapsedTime;
        oldError = Error;
        
        Signal = (Kp * Error) + (Ki * SumError) + (Kd * ErrorDif);
        PreviousTime = currentTime;

        return Signal; 
    }
}
#endif