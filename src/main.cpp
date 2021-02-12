#include <Arduino.h>
#include <processors/transformer.h>


void setup() {
  // put your setup code here, to run once:
}


void loop() {
  int setpoint_signal = analogRead(A1);
  int input_signal = analogRead(A0);
  float processed_signal = OffsetTransformer::transform(input_signal);
  
}