#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <arduino.h>
#include <entities/value.h>

template<class T>
class SensorABS {
        public: 
            ActuatorABS(uint8_t id);
            void setValue(ValueABS<T> value);
            ValueABS<T> getValue();
            uint8_t getId();
            void execute();   
        private:
            bool hasToChange;
            ValueABS<T> value;
            virtual void write(ValueABS<T> value);
};

template<class T>
ActuatorABS<T>::ActuatorABS(uint8_t id){
    this->id = id;
};

template<class T>
void ActuatorABS<T>::setValue(ValueABS<T> value){
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
        this->write(this->Value);
        this->hasToChange = false;
    }
};

template<class T>
ValueABS<T> ActuatorABS<T>::getValue(){
    return this->value;
};

#endif