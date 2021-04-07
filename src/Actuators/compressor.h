#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/Signal.h>

class Compressor : public ActuatorABS<float> {
    public:
        Compressor(uint8_t id, uint8_t pin):ActuatorABS<float>(id){
            this->pin = pin;
        }
    private:
        uint8_t pin;
        void write(Signal value);
};

void Compressor::write(Signal value){
    uint8_t discrete_value = map(value.getValue(), 0, 1, 0, 255);   // Revisar voltaje/ampreaje de entrada
    analogWrite(this->pin, discrete_value);
}

#endif