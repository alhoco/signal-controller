#ifndef TRANSFORMER_H
#define TRANSFORMER_H

namespace OffsetTransformer {
    float max_bin = 1023;
    float max_temp = 50;

    float transform(float input) {
        return (input * max_temp) / max_bin;
    }
}

#endif