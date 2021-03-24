#ifndef SETTINGS.H
#define SETTINGS.H

namespace Settings {
    const String VERSION = "0.0.0";
    const int COMPRESSOR = 13;
    const int TEMPERATURE_SENSOR =0;
    const int ALARM_LED = 23;
    const uint8_t ANALOG_SENSOR = A0;
  
  void initSettings() {
  	pinMode(COMPRESSOR, OUTPUT);
    pinMode(ALARM_LED, INPUT);
    pinMode(TEMPERATURE_SENSOR, INPUT);
    pinMode(ANALOG_SENSOR,INPUT);
	}
}

#endif