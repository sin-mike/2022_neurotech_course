#ifndef W_H
#define W_H

#define N_CHANNELS 28
#define N_CLASSES 11
#define N_HIDDEN 50
#define ACTIVATION_THRESH 0.3053713265536183
#define ALPHA_ACTIVATIONS 0.5

extern const float rnn_in_w[N_CHANNELS][N_HIDDEN];

extern const float rnn_h_w[N_HIDDEN][N_HIDDEN] ;

extern const float rnn_b[N_HIDDEN] ;

extern const float head_w[N_HIDDEN][N_CLASSES] ;

extern const float head_b[N_CLASSES] ;

#endif