#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <Arduino.h>
#include <entities/value.h>

template<class T>
class ActuatorABS {
        public: 
            ActuatorABS(uint8_t id);
            void setValue(T value);
            ValueABS<T> getValue();
            uint8_t getId();
            void execute();   
        private:
            bool hasToChange;
            T value;
            uint8_t id;
            virtual void write(T value);
};

template<class T>
ActuatorABS<T>::ActuatorABS(uint8_t id){
    this->id = id;
};

template<class T>
void ActuatorABS<T>::setValue(T value){
    this->value = value;
    this->hasToChange = true;
};

template<class T>
uint8_t ActuatorABS<T>::getId(){
    return this->id;
};

template<class T>
void ActuatorABS<T>::execute(){
    if(this->hasToChange){
        this->write(this->value);
        this->hasToChange = false;
    }
};

template<class T>
ValueABS<T> ActuatorABS<T>::getValue(){
    return this->value;
};

#endif