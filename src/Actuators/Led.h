#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <Actuators/Actuators.h>
#include <entities/State.h>

class Led : public ActuatorABS<State> {
    public:
        Led(uint8_t id, uint8_t pin):ActuatorABS(id){
            this->pin = pin;
        }
    private:
        uint8_t pin;
        void write(State value);
};

void Led::write(State value){
    bool bool_value = 0.5 < value.getValue();   // Revisar voltaje/ampreaje de entrada
    digitalWrite(this->pin, bool_value);
}

#endif