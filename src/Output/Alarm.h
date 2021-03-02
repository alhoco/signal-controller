#ifndef ALARM_H
#define ALARM_H
#define Led 3
#include <Arduino.h>

void setup (){
    pinMode(Led,OUTPUT);
    digitalWrite(Led,LOW);
}

namespace Alarm{

    void alarm(int input_signal){

        if (input_signal >= 3){
            digitalWrite(Led, HIGH);
        }
        else{
            digitalWrite(Led, LOW);
        }
    }
}

#endif