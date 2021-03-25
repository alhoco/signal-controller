#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <Arduino.h>

template<class T>
T transform(T input, T max, T min){
    return (input * max) / min;
}

#endif