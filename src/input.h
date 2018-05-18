#ifndef INPUT_H_
#define INPUT_H_
#include <stdint.h>
#include <config.h>
#include <hardware/hardware.h>
#include "inputSyscall.h"

#define NULL 0

/**
  input pin configuration
*/
typedef struct {
  //pins for each button @see InputState
  Pin b1, b2, b3, b4;
  Pin dUp, dDown, dLeft, dRight;
  Pin home, start;
} InputConfig;

/**
  setup the input module wit the passed input pin mapping.
  @param iCon configuration structure that maps pins to user inputs.
*/
void initConfig(InputConfig * iCon);

/**
  like initConfig but uses the default pin mapping
  @see initConfig
*/
void initDefault(void);

/**
  fills out the passed input state structure with the current input state.
*/
void getControlState(InputState * iState);


#endif /*INPUT_H_*/
