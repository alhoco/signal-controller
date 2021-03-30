#ifndef SETTINGS.H
#define SETTINGS.H

namespace Settings {
    const String VERSION = "0.0.0";
    const int COMPRESSOR = 13;
    const int setpoint = A1;
    const int ALARM_LED = 23;
    const uint8_t sensor = A0;
    const uint8_t Amp_Sensor = A2;
  
  void initSettings() {
  	pinMode(COMPRESSOR, OUTPUT);
    pinMode(ALARM_LED, INPUT);
    pinMode(setpoint, INPUT);
    pinMode(sensor,INPUT);
	}
}

#endif