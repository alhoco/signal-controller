#ifndef VALUE_H
#define VALUE_H

#include <Arduino.h>

template<class T>
class ValueABS {
    public:
        ValueABS();
        ValueABS(T value, uint8_t source);
        uint8_t getSource();
        T getValue();
    private: 
        T value;
        uint8_t source;
};

template<class T>
ValueABS<T>::ValueABS(T value, uint8_t source) {
    this->value = value;
    this->source = source;
}

template<class T> 
ValueABS<T>::ValueABS() {};

template<class T>
T ValueABS<T>::getValue(){
    return this->value;
}

template<class T>
uint8_t ValueABS<T>::getSource() {
    return this->source;
}

#endif