#include <Arduino.h>
#include <settings.h>
#include <processors/transformer.h>
//#include <Output/Output.h>
//#include <processors/aggregator.h>
//#include <Output/Alarm.h>
#include <Sensors/analog_sensor.h>
#include <processors/CircularBuffer.h>
#include <Sensors/sensor_temperatura.h>
#include <Sensors/sensor_amperaje.h>
#include <entities/Signal.h>
#include <entities/Temperature.h>
#include <entities/Signal.h>
#include <entities/State.h>
#include <Actuators/Led.h>
#include <Serializers/Printer.h>
#include <entities/Amperage.h>
#include <processors/Validators.h>
#include <entities/Direction.h>
#include <Actuators/LedRGB.h>
#include <Actuators/compressor.h>


CircularBuffer<int> circularbuffer = CircularBuffer<int>(6);
TemperatureSensor sensor = TemperatureSensor(0x7E, A0);
TemperatureSensor setpoint_Temperature = TemperatureSensor(0x7A, A1);
AmperageSensor Amp_sensor = AmperageSensor(0x7B, A2);
Led compressor_led = Led(0xAB, 53);
Compressor compressor = Compressor(0xAD, 4, 2, 3);
Led Alarm_Led = Led(0xAC, 51);
double reference_Time = 0;
int Time = 500;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Settings::sensor,INPUT);
  pinMode(Settings::setpoint_Temperature,INPUT);
  pinMode(Settings::Amp_Sensor,INPUT);
  pinMode(Settings::compressor,OUTPUT);
  pinMode(Settings::Alarm_Led,OUTPUT);

  digitalWrite(Settings::compressor,LOW);
  

}

void loop() {

  sensor.execute();
  setpoint_Temperature.execute();
  Amp_sensor.execute();

  if (sensor.hasChanged()){
    ValueABS<float> raw_read = sensor.getValue();
    ValueABS<float> Temp_setpoint = setpoint_Temperature.getValue();
    ValueABS<float> amperage = Amp_sensor.getValue();

    circularbuffer.append(raw_read.getValue());
    float temperature = circularbuffer.mean();

    Temperature Temperature_setpoint = Temperature(Temp_setpoint.getValue(), 0);
    Temperature Temp = Temperature(temperature, 0);
    Amperage Compressor_Amperage = Amperage(amperage.getValue(), 0);
    Amperage Amperage_Setpoint = Amperage(12, 0);
    
    bool Compressor_Instruction = desitions(Temp, Temperature_setpoint);
    bool Compressor_Valid = Compressor_Validation(Compressor_Amperage, Amperage_Setpoint, Compressor_Instruction); 
    int RGBDirect = RGBDirection(Compressor_Instruction, Compressor_Valid);
    Direction RGBDir = Direction(RGBDirect, 0);
    State Compressor_State = State(Compressor_Valid, 0);

    // Cálculo de salida de amperaje al compresor
    float comp_val = PIDenvironment::PID(Temp, Temperature_setpoint);
    Signal signal = Signal(comp_val, 0);

    //Accionamiento del compresor por ahora como un LED hasta implementar PID
    compressor_led.setValue(Compressor_State);
    compressor_led.execute();
    //comp_RGB.setValue(RGBDir);
    //comp_RGB.execute();
    compressor.setValue(signal);
    compressor.execute();
    
    //Alarma
    bool Alarm_Instruction = desitions(Compressor_Amperage, Amperage_Setpoint);
    State Alarm_State = State(Alarm_Instruction, 0);
    
    Alarm_Led.setValue(Alarm_State);
    Alarm_Led.execute();

    
   /* 
    if(reference_Time == 0){
      reference_Time = millis();
    }

    double current_Time = millis();
    
    if ((current_Time - reference_Time) >= Time){
    valuePrinter(Serial, raw_read.getValue(), "Raw Temperature");
    valuePrinter(Serial, signal.getValue(), "PWM");
    valuePrinter(Serial, Temp.getValue(), "Mean Temperature");
    valuePrinter(Serial, Temperature_setpoint.getValue(), "Set point");
    valuePrinter(Serial, Compressor_Amperage.getValue(), "Compressor Ampreage");
    StatePrinter(Serial, Compressor_Valid, "Compressor State");
    StatePrinter(Serial, Alarm_Instruction, "Alarm State");
    Serial.println("");
    
    reference_Time = 0;
    }*/

    if(reference_Time == 0){
            reference_Time = millis();
        }

        double current_Time = millis();
    
        if ((current_Time - reference_Time) >= Time){
            valuePrinter(Serial, PIDenvironment::currentTime, "Tiempo Actual");
            valuePrinter(Serial, PIDenvironment::PreviousTime, "Tiempo pasado");
            valuePrinter(Serial, PIDenvironment::ElapsedTime, "Tiempo transcurrido");
            valuePrinter(Serial, PIDenvironment::Error, "Error");
            valuePrinter(Serial, PIDenvironment::SumError, "Suma error");
            valuePrinter(Serial, PIDenvironment::ErrorDif, "Derivada Error");
            valuePrinter(Serial, PIDenvironment::Signal, "señal retornada");
            Serial.println("");
    
             reference_Time = 0;
        }
  } 
  //delay(1000);
  }