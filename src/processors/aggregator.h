#ifndef AGGREGATOR_H
#define AGGREGATOR_H
#include <Output/Output.h>

namespace Aggregator {
    int compressor_start_counter = 0;

    float aggregator(){

        if (output::last_compressor_state == output::compressor_state){
            compressor_start_counter = 0;
        }
        else if ((output::last_compressor_state == 0) && (output::compressor_state == 1)){
            compressor_start_counter ++;
        }

        return compressor_start_counter;
    }
}

#endif