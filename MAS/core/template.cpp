#include "template.h"

float gaussian(int value, float mean, float varDis) {
    return 1. / (varDis * sqrt(2. * M_PI)) * exp(-pow(value - mean, 2) / (2 * pow(varDis, 2)));
}

