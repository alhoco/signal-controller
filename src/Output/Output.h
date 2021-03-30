#ifndef OUTPUT_H
#define OUTPUT_H
#define Compressor 2
#define Amperage A1

#include <arduino.h>
#include <Sensors/analog_sensor.h>
#include <settings.h>

AnalogSensor Amp_Sensor = AnalogSensor(0x7E, A2);

void setup() {
    pinMode(Compressor, LOW);
}

namespace output{
    int compressor_state = 0;
    int last_compressor_state = 0;

template<class T>
class Outputrole{
public:
    void Output(uint8_t input_signal, uint8_t setpoint);
private:
    uint8_t last_compressor_state;
    uint8_t compressor_state;
};

template<class T>
void Outputrole<T>::Output(uint8_t input_signal, uint8_t setpoint){
        // Aqui voy

     if (input >= setpoint){
        digitalWrite(Compressor, HIGH);
        compressor_state = 1;
    }
    else {
        digitalWrite(Compressor, LOW);
        compressor_state = 0;
    }
    delay(3000);

    ampsensor.execute();
    circularbufferamp.append(ampsensor);

    if (ampsensor.getValue().getValue() < 0){
        last_compressor_state = compressor_state;
        compressor_state = 0;
    }
    else {
        last_compressor_state = compressor_state;
    }
        
}
}

#endif