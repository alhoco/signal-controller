#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>
#include <entities/value.h>
#include <stdlib.h>

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
    float Kp = 10;
    float Ki = 2;
    float Kd = 0.5;
    float Error;
    float SumError;
    float ErrorDif;
    float currentTime;
    float ElapsedTime;
    float PreviousTime;
    
    template<class T>
    float PID(T value, T Reference){
        currentTime = millis();
        ElapsedTime = currentTime - PreviousTime;


        Error = abs(Reference.getValue() - value.getValue());
        SumError = SumError + (Error * ElapsedTime);
        ErrorDif = (Error - oldError) / ElapsedTime;
        oldError = Error;
        
        return (Kp * Error) + (Ki * SumError) + (Kd * ErrorDif); 

        PreviousTime = currentTime;
    }
}
#endif