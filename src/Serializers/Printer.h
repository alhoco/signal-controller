#ifndef PRINTER_H
#define PRINTER_H

#include <Arduino.h>

void valuePrinter(Stream &uart, float value, char* label){
    char output[64];
    sprintf(output, "%s -> %d", label, int(value));
    uart.println(output);
}

void StatePrinter(Stream &uart, bool value, char* label){
    char output[64];
    if(value){
       sprintf(output, "%s -> ON", label);
    }
    else{
        sprintf(output, "%s -> OFF", label);
    }
    uart.println(output);
}

#endif