#include "math.h"
#include "model.h"
#include <avr/pgmspace.h>


// rnn_hidden = np.zeros(N_HIDDEN)
float rnn_hidden[N_HIDDEN];

// prev_x = np.zeros(N_CLASSES) 
float prev_x [N_CLASSES];

/*def manual_relu(x):
    return max(x, 0)*/
float relu(float x){
    if (x>0) return x; else return 0;
}

/*def manual_sigmoid(x):
    return 1/(1+np.exp(-x))*/
float sigmoid(float x){
    return 1/(1+exp(-x));
}

/*
def manual_dot(x, y, shape):
    s = 0.0
    for i in range(shape):
        s = s + x[i]*y[i]
    return s
*/

float vec_dot_vec(float * vec1, float * vec2, int shape) {
    float sum = 0;
    for (int i = 0; i < shape; i++){
        sum += vec1[i] * vec2[i];
    }
    return sum;
}

/*
def model_call(x, y):   
    """assume x is input data, y are activations for classes"""
    # first layer == Input layer
    x = x
    # y = np.zeros(N_CLASSES)
    
    # second layer == SimpleRNN
    rnn_hidden_prev = np.zeros(N_HIDDEN)
    for hi in range(N_HIDDEN):
        rnn_hidden_prev[hi] = manual_dot(x, rnn_in_w[:, hi], N_CHANNELS) + manual_dot(rnn_hidden, rnn_h_w[:, hi], N_HIDDEN) + rnn_b[hi]
    
    for hi in range(N_HIDDEN):
        rnn_hidden[hi] = manual_relu(rnn_hidden_prev[hi])
        
    for ci in range(N_CLASSES):
        y[ci] = manual_dot(rnn_hidden, head_w[:, ci], N_HIDDEN) + head_b[ci]
        y[ci] = manual_sigmoid(y[ci])
*/
void model_call(float x[N_CHANNELS], float y[N_CLASSES], HardwareSerial &Serial){

    float rnn_hidden_prev[N_HIDDEN];

    // rnn layer
    for (int hi = 0; hi<N_HIDDEN; hi++){
      
        rnn_hidden_prev[hi] = pgm_read_float(&rnn_b[hi]);
        // rnn_hidden_prev[hi] = rnn_b[hi];

        float in_w[N_CHANNELS];
        for (int iw=0; iw<N_CHANNELS; iw++) {
          in_w[iw] = pgm_read_float(&rnn_in_w[iw][hi]);
        }
        
        rnn_hidden_prev[hi] += vec_dot_vec(x, in_w, N_CHANNELS);

        float hidden_w[N_HIDDEN];
        for (int ih=0; ih<N_HIDDEN; ih++) {
          hidden_w[ih] = pgm_read_float(&rnn_h_w[ih][hi]);
        }

        rnn_hidden_prev[hi] += vec_dot_vec(rnn_hidden, hidden_w, N_HIDDEN);
        
    }

    // rnn layer activation
    for (int hi = 0; hi<N_HIDDEN; hi++){
        rnn_hidden[hi] = relu(rnn_hidden_prev[hi]);
    }
    

    // head layer
    for (int ci = 0; ci < N_CLASSES; ci++){
        y[ci] = pgm_read_float(&head_b[ci]);

        float h_w[N_HIDDEN];
        for (int ihead=0; ihead<N_HIDDEN; ihead++) {
          h_w[ihead] = pgm_read_float(&head_w[ihead][ci]);
        }
        
        y[ci] += vec_dot_vec(rnn_hidden, h_w, N_HIDDEN);
        
        
    }

    // head layer activation
    for (int ci = 0; ci < N_CLASSES; ci++){
        y[ci] = sigmoid(y[ci]);
    }
}

/*
def postprocess(x, alpha):
    """assume x is an activation vec"""
    for ci in range(N_CLASSES):
        x[ci] = x[ci]*alpha + prev_x[ci]*(1-alpha) 
        prev_x[ci] = x[ci]
*/

void postprocess(float x[N_CLASSES]) {
    for (int ci = 0; ci < N_CLASSES; ci++){
        x[ci] = x[ci]*ALPHA_ACTIVATIONS + prev_x[ci]*(1-ALPHA_ACTIVATIONS);
        prev_x[ci] = x[ci];
    }
}
