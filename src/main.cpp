#include <Arduino.h>
#include <settings.h>
#include <processors/transformer.h>
#include <Output/Output.h>
#include <processors/aggregator.h>
#include <Output/Alarm.h>
#include <Sensors/analog_sensor.h>

CircularBuffer<int> circularbuffer = CircularBuffer<int>(6);
analogsensor sensor = analogsensor(0x7E, A0);
analogsensor setpoint_signal = analogsensor(0x7E, A1);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}


void loop() {

Settings::initSettings();

sensor.execute();
setpoint_signal.execute();

if (sensor.hasChanged()){
  int raw_read = sensor.getValue().getValue();
  circularbuffer.append(raw_read);
  int temperature = circularbuffer.mean();
}

  float processed_signal = OffsetTransformer::transform(temperature);
  
  output::Output(processed_signal, setpoint_signal.getValue().getValue());
  int aggregated_signal = Aggregator::aggregator();
  Alarm::alarm(aggregated_signal);

  Serial.println("--------------- Muestreo de Variables ---------------");
  Serial.print("Temperatura: ");
  Serial.println(processed_signal);
  Serial.print("Estado compresor: ");
  Serial.println(output::compressor_state);
  Serial.print("Encendidos continuos compresor: ");
  Serial.println(Aggregator::compressor_start_counter);
  
}