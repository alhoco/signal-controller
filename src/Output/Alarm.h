#ifndef ALARM_H
#define ALARM_H

#include <Arduino.h>
#include <Sensors/sensor_amperaje.h>
#include <Output/Output.h>


namespace Alarm{

    bool Alarm_state;
    void alarm(int source, int input_signal){

        if (input_signal >= 10 && (output::compressor_state == true)){
            digitalWrite(source, HIGH);
            Alarm_state = true;
        }
        else{
            digitalWrite(source, LOW);
            Alarm_state = false;
        }
    }
}

#endif