#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/signal.h>

class Compressor : public ActuatorABS<Signal> {
    public:
        Compressor(uint8_t id, uint8_t pin):ActuatorABS(id){
            this->pin = pin;
        }
    private:
        uint8_t pin;
        void write(Signal value);
};

void Compressor::write(Signal value){
    uint_8t discrete_value = map(value.getValue(), 0, 1, 0, 255);   // Revisar voltaje/ampreaje de entrada
    analogWrite(this->pin, descrete_value);
}

#endif