#ifndef SENSOR_H
#define SENSOR_H

#include <arduino.h>

template<class T>
class SensorABS {
        public: 
            SensorABS(uint8_t id);
            Read<T> getValue();
            uint8_t getId();
            void execute();
        private:
            T last_value;
            Read <T> value;
            uint8_t Id;
            virtual T read();
};



#endif