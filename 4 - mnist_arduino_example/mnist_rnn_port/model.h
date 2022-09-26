#ifndef MODEL_H

#define MODEL_H

#include "w.h"
#include <Arduino.h>

extern float rnn_hidden[N_HIDDEN];
extern float prev_x [N_CLASSES];

void model_call(float * x, float * y, HardwareSerial &Serial);
void postprocess(float x[N_CLASSES]) ;

#endif
