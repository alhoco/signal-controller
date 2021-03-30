#ifndef COMPRESSORDESITIONS_H
#define COMPRESSORDESITIONS_H

#include <arduino.h>
#include <Sensors/sensor_amperaje.h>

AmperageSensor Amp_Sensor = AmperageSensor(0x7E, A2);

template<class T>
T CompressorDesitions(uint8_t input_signal, uint8_t setpoint){

     if (input_signal >= setpoint){
        this->order = true; 
    }
    else {
        this->order = false;
    }
    return bool(this->order);
    delay(3000);

    //Amp_Sensor.execute();

    //if (Amp_Sensor.getValue().getValue() <= 0){
      //  last_compressor_state = compressor_state;
        //compressor_state = false;
    //}
    //else {
       // last_compressor_state = compressor_state;
     //   compressor_state = true;
    //}
        
}

#endif