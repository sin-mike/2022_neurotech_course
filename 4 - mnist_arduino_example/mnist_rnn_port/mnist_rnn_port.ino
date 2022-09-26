#include "model.h"
#include "data.h"
#include <avr/pgmspace.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(LED_BUILTIN, OUTPUT);
}

float input_vec[N_CHANNELS];
float y[N_CLASSES];
int stat = 0;

void loop() {
  while (!stat)
  {
    for (int i = 0; i< 10; i++) Serial.print("-"); 
    Serial.println("");

    unsigned long tick = millis();
    for (uint16_t di = 0; di < DATA_LEN; di++){
      
      for (int chi = 0; chi < N_CHANNELS; chi++){
        input_vec[chi] = ((float)pgm_read_byte(&data[chi][di]))/100.0;
      } 

      model_call(input_vec, y, Serial);
      postprocess(y);
  
      // infer labels
      int label=10;
      for (int ci=0; ci<N_CLASSES; ci++){
        if ((y[ci]>ACTIVATION_THRESH) && (y[ci] > y[label])){
          label=ci;
        }
      }
      
//      Serial.print(di);
//      Serial.print(" ");
      Serial.print(label);Serial.print(" ");
      for (int i = 0; i<10; i++){
        Serial.print(i); Serial.print(" ");
      }
    
//      Serial.print(millis() - tick);
      Serial.println();
    }
    stat=1;
  }
}
