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


CircularBuffer<int> circularbuffer = CircularBuffer<int>(6);
TemperatureSensor sensor = TemperatureSensor(0x7E, A0);
TemperatureSensor setpoint_Temperature = TemperatureSensor(0x7A, A1);
AmperageSensor Amp_sensor = AmperageSensor(0x7B, A2);
Led compressor = Led(0xAB, 22);
Led Alarm_Led = Led(0xAC, 30);


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
    State Compressor_State = State(Compressor_Valid, 0);
    

    //Accionamiento del compresor por ahora como un LED hasta implementar PID
    compressor.setValue(Compressor_State);
    compressor.execute();
    
    //Alarma
    bool Alarm_Instruction = desitions(Compressor_Amperage, Amperage_Setpoint);
    State Alarm_State = State(Alarm_Instruction, 0);
    
    Alarm_Led.setValue(Alarm_State);
    Alarm_Led.execute();

    valuePrinter(Serial, raw_read.getValue(), "Raw Temperature");
    valuePrinter(Serial, Temp.getValue(), "Mean Temperature");
    valuePrinter(Serial, Temperature_setpoint.getValue(), "Set point");
    valuePrinter(Serial, Compressor_Amperage.getValue(), "Compressor Ampreage");
    StatePrinter(Serial, Compressor_Valid, "Compressor State");
    StatePrinter(Serial, Alarm_Instruction, "Alarm State");
    Serial.println("");
} 
delay(1000);
  
}