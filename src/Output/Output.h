#ifndef OUTPUT_H
#define OUTPUT_H

#include <arduino.h>
#include <settings.h>


namespace output{

void Output(bool order){
    if (order == true){
    digitalWrite(Settings::COMPRESSOR,HIGH);
    }
    else {
        digitalWrite(Settings::COMPRESSOR,LOW);
    }
}
}

#endif