#include <Arduino.h>
#include <settings.h>
#include <processors/transformer.h>
#include <Output/Output.h>
//#include <processors/aggregator.h>
//#include <Output/Alarm.h>
#include <Sensors/analog_sensor.h>
#include <processors/CircularBuffer.h>
#include <Sensors/sensor_temperatura.h>
#include <processors/CompressorDesitions.h>

CircularBuffer<int> circularbuffer = CircularBuffer<int>(6);
TemperatureSensor sensor = TemperatureSensor(0x7E, A0);
TemperatureSensor setpoint_signal = TemperatureSensor(0x7E, A1);

int compressor = Settings::COMPRESSOR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Settings::sensor,INPUT);
  pinMode(Settings::setpoint,INPUT);
  //pinMode(Settings::Amp_Sensor,INPUT);
  pinMode(Settings::COMPRESSOR,OUTPUT);

  digitalWrite(Settings::COMPRESSOR,LOW);
}

void loop() {

  sensor.execute();
  setpoint_signal.execute();

  if (sensor.hasChanged()){
    int raw_read = sensor.getValue().getValue();
    circularbuffer.append(raw_read);
    float temperature = circularbuffer.mean();
  
    bool order = CompressorDesitions<bool>(temperature, setpoint_signal.getValue().getValue());
    output::Order(compressor, order);
    //float processed_signal = transform<float>(temperature, 50, 1023);

    //output::Output(processed_signal, setpoint_signal.getValue().getValue());
    //int aggregated_signal = Aggregator::aggregator();
    //Alarm::alarm(aggregated_signal);

    Serial.println("--------------- Muestreo de Variables ---------------");
    Serial.print("Temperatura: ");
    Serial.println(raw_read);
    Serial.print("Temperatura media: ");
    Serial.println(temperature);
    Serial.print("Temperatura setpoint: ");
    Serial.println(setpoint_signal.getValue().getValue());
    Serial.print("Temperatura setpoint: ");
    Serial.println(order);
    //Serial.print("Encendidos continuos compresor: ");
  //Serial.println(Aggregator::compressor_start_counter);
} 
delay(3000);
  
}