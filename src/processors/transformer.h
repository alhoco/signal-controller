#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

template<class T>
T transform(T input, T max_temperature, T max_sensor){
    return (input * max_temperature) / max_sensor;
}

#endif