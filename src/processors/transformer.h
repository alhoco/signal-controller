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
    float dT = 1;    //Revisar (Aqui esta con FPS)
    float Kp = 10;
    float Ki = 2;
    float Kd = 0.1;
    float Error;
    float SumError;
    float ErrorDif;
    
    template<class T>
    float PID(T value, T Reference){
        Error = abs(Reference.getValue() - value.getValue());
        SumError = SumError + (Error * dT);
        ErrorDif = (Error - oldError) / dT;
        oldError = Error;

        return (Kp * Error) + (Ki * SumError) + (Kd * ErrorDif); 
    }
}
#endif