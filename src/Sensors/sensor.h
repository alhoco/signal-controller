#ifndef SENSOR_H
#define SENSOR_H

#include <arduino.h>
#include <Sensors/read.h>

template<class T>
class SensorABS {
        public: 
            SensorABS(uint8_t id);
            Read<T> getValue();
            uint8_t getId();
            bool hasChanged();
            void execute();   
        private:
            T raw_value;
            Read<T> value;
            uint8_t id;
            virtual T read();
            bool changed;
};

template<class T>
    SensorABS<T>::SensorABS(uint8_t id){
        this->id = id;
    }

template<class T>
    Read<T> SensorABS<T>::getValue(){
        return this->value;
    }

template<class T>
    bool SensorABS<T>::hasChanged(){
        return this->changed;
}

template<class T>
    uint8_t SensorABS<T>::getId(){
        return this->id;
    }

template<class T>
void SensorABS<T>::execute(){
    T new_value = this->read();
    if (new_value != this->raw_value){
        this->raw_value = new_value;
        this->value = Read<T>(new_value, this->id);
    }
}


#endif