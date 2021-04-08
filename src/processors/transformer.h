#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>
#include <entities/value.h>

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


#endif