#include <Arduino.h>
#include <settings.h>
#include <processors/transformer.h>
#include <Output/Output.h>
#include <processors/aggregator.h>


void setup() {
  // put your setup code here, to run once:
}


void loop() {
  Settings::initSettings();

  int setpoint_signal = analogRead(A1);
  int input_signal = analogRead(A0);
  float processed_signal = OffsetTransformer::transform(input_signal);
  output::Output(processed_signal, setpoint_signal);
  int aggregated_singal = Aggregator::aggregator();
  
}