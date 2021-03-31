#ifndef OUTPUT_H
#define OUTPUT_H

#include <arduino.h>
#include <settings.h>
//#include <Output/Alarm.h>


namespace output{
/*
template<class T>
class output {
    public:
        bool getState();
        void Order(int source, bool order);
    private:
        bool compressor_state;
        bool order;
};

template<class T>
bool output<T>::getState(){
    return this->compressor_state;
}

template<class T>*/

bool compressor_state;

void Order(int source, bool order){
    if ((order == true)){
        digitalWrite(source,HIGH);
        compressor_state = true;
    }
    else {
        digitalWrite(source,LOW);
        compressor_state = false;
    }
}
}

#endif