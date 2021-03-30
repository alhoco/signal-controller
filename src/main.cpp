#include <Arduino.h>
#include <settings.h>
#include <processors/transformer.h>
#include <Output/Output.h>
#include <processors/aggregator.h>
//#include <Output/Alarm.h>
#include <Sensors/analog_sensor.h>
#include <processors/CircularBuffer.h>
#include <Sensors/sensor_temperatura.h>

CircularBuffer<int> circularbuffer = CircularBuffer<int>(6);
TemperatureSensor sensor = TemperatureSensor(0x7E, A0);
TemperatureSensor setpoint_signal = TemperatureSensor(0x7E, A1);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Settings::sensor,INPUT);
  pinMode(Settings::setpoint,INPUT);
  pinMode(Settings::Amp_Sensor,INPUT);
}

void loop() {

sensor.execute();
setpoint_signal.execute();

if (sensor.hasChanged()){
  int raw_read = sensor.getValue().getValue();
  circularbuffer.append(raw_read);
  float temperature = circularbuffer.mean();
  
  //float processed_signal = transform<float>(temperature, 50, 1023);

    //output::Output(processed_signal, setpoint_signal.getValue().getValue());
  //int aggregated_signal = Aggregator::aggregator();
  //Alarm::alarm(aggregated_signal);

  Serial.println("--------------- Muestreo de Variables ---------------");
  Serial.print("Temperatura: ");
  Serial.println(raw_read);
  Serial.print("Temperatura media: ");
  Serial.println(temperature);
  //Serial.print("Encendidos continuos compresor: ");
  //Serial.println(Aggregator::compressor_start_counter);
}
delay(3000);
  
}