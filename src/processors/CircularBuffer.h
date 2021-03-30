#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <Arduino.h>

template<class T>
class CircularBuffer {
public: 
    CircularBuffer(int);
    void append(T value);
    uint8_t getsize(){
            return this->size;
    };
    float mean();
private:
    T *buffer;
    uint8_t size;   
};

template<class T>
CircularBuffer<T>::CircularBuffer(int s){
    this->size = s;
    buffer = new T[size];
}

template<class T>
void CircularBuffer<T>::append(T value){
    for(int i = this->size -1; i > 0; i--){
        this->buffer[i] = this->buffer[i - 1]; 
    }
    this->buffer[0] = value;
}

template<class T>
float CircularBuffer<T>::mean(){
    T sum = 0;
    for (int j= 0; j < this->size; j++){
        sum += this->buffer[j];
    };
    return float(sum) / this->size;
}

#endif