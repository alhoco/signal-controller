#ifndef READ.H
#define READ.H

#include <Arduino.h>

template<class T>
class Read {
    public:
        Read();
        Read(T value, uint8_t source);
        uint8_t getSource();
        T getValue();
    private: 
        T value;
        uint8_t source;
};

template<class T>
Read<T>::Read(T value, uint8_t source) {
    this->value = value;
    this->source = source;
}

template<class T> 
Read<T>::Read() {};

template<class T>
T Read<T>::getValue(){
    return this->value;
}

template<class T>
uint8_t Read<T>::getSource() {
    return this->source;
}

#endif