#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/Temperature.h>
#include <processors/transformer.h>
#include <Actuators/LedRGB.h>
#include <entities/Signal.h>

class Compressor : public ActuatorABS<Temperature> {
    public:
        Compressor(uint8_t id, uint8_t pinR, uint8_t pinG, uint8_t pinB):ActuatorABS(id){
            this->pinR = pinR;
            this->pinG = pinG;
            this->pinB = pinB;
        }
    private:
        uint8_t pinR;
        uint8_t pinG;
        uint8_t pinB;
        void write(Temperature value);
};

void Compressor::write(Temperature value){
    uint8_t discrete_value = map(value.getValue(), 0, 15, 0, 255);   // Revisar voltaje/ampreaje de entrada
    Signal Output_value = Signal(discrete_value, 0);
    //analogWrite(this->pin, discrete_value);
    // LLama a la funcion del led RGB
    LedRGB State = LedRGB(0xAC, this->pinR, this->pinG, this->pinB);

    State.setValue(Output_value);
}

#endif