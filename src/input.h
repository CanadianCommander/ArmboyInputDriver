#ifndef INPUT_H_
#define INPUT_H_
#include <stdint.h>

/**
  user input state structure 
*/
typedef struct {
  // push buttons
  uint8_t b1,b2,b3,b4;
  /*
  #### physical button layout ####
        b1
    b2      b3
        b4
  */

  // D-pad
  uint8_t dUp, dDown, dLeft, dRight;

  //home | start
  uint8_t home, start;
} InputState;



#endif /*INPUT_H_*/
