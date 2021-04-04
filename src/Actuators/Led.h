#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/signal.h>

class Led : public ActuatorABS<Signal> {
    public:
        Led(uint8_t id, uint8_t pin):ActuatorABS(id){
            this->pin = pin;
        }
    private:
        uint8_t pin;
        void write(Signal value);
};

void Led::write(Signal value){
    bool bool_value = 0.5 > value.getValue();   // Revisar voltaje/ampreaje de entrada
    digitalWrite(this->pin, bool_value);
}

#endif