#ifndef TRANSFORMER_H
#define TRANSFORMER_H

namespace OffsetTransformer {
    float offset = -1.0;
    float scale = 0.5;

    float transform(float input) {
        return (input - offset) * scale;
    }
}

#endif