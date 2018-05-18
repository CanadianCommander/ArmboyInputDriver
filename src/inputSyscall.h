#ifndef INPUT_SYSCALL_H_
#define INPUT_SYSCALL_H_
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

/**
  input configuration structure for system call interface.
*/
typedef struct {
  uint8_t b1_bank, b2_bank, b3_bank, b4_bank;
  uint32_t b1_pin,  b2_pin,  b3_pin,  b4_pin;

  uint8_t dUp_bank, dDown_bank, dLeft_bank, dRight_bank;
  uint32_t dUp_pin, dDown_pin, dLeft_pin, dRight_pin;

  uint8_t home_bank, start_bank;
  uint32_t home_pin, start_pin;

} InputConfigSysCall;

/**
  initialize input pins with the given config
*/
void initConfigCall(void * config);

/**
  initialize input pins whit default config
*/
void initDefaultCall(void * nop);

void getControlStateCall(void * iState);

#endif /* INPUT_SYSCALL_H_ */
