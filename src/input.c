#include "input.h"
#include "config.h"
#include "hardware/hardware.h"

static InputConfig currentConfig;

//setup PIO controller for the configured input pins
static void initPins(void);

void initConfig(InputConfig * iCon){
  currentConfig = *iCon;
  initPins();
}

/**
  like initConfig but uses the default pin mapping
  @see initConfig
*/
void initDefault(void){
  currentConfig.b1 = toPin(PIO_BANK_C,PIO_PC22,     NULL);
  currentConfig.b2 = toPin(PIO_BANK_C,PIO_PC21,     NULL);
  currentConfig.b3 = toPin(PIO_BANK_A,PIO_PC28,     NULL);
  currentConfig.b4 = toPin(PIO_BANK_D,PIO_PD7,      NULL);

  currentConfig.dUp = toPin(PIO_BANK_A,PIO_PA16,    NULL);
  currentConfig.dDown = toPin(PIO_BANK_A,PIO_PA24,  NULL);
  currentConfig.dLeft = toPin(PIO_BANK_A,PIO_PA23,  NULL);
  currentConfig.dRight = toPin(PIO_BANK_A,PIO_PA22, NULL);

  currentConfig.home = toPin(PIO_BANK_A,PIO_PA6,    NULL);
  currentConfig.start = toPin(PIO_BANK_A,PIO_PA6,   NULL);

  initPins();
}

static void initPins(void){
  enableAllIOBanks();

  enablePin(currentConfig.b1.bank, currentConfig.b1.pin, PIO_IN);
  enablePin(currentConfig.b2.bank, currentConfig.b2.pin, PIO_IN);
  enablePin(currentConfig.b3.bank, currentConfig.b3.pin, PIO_IN);
  enablePin(currentConfig.b4.bank, currentConfig.b4.pin, PIO_IN);

  enablePin(currentConfig.dUp.bank, currentConfig.dUp.pin,        PIO_IN);
  enablePin(currentConfig.dDown.bank, currentConfig.dDown.pin,    PIO_IN);
  enablePin(currentConfig.dLeft.bank, currentConfig.dLeft.pin,    PIO_IN);
  enablePin(currentConfig.dRight.bank, currentConfig.dRight.pin,  PIO_IN);

  enablePin(currentConfig.home.bank, currentConfig.home.pin, PIO_IN);
  enablePin(currentConfig.start.bank, currentConfig.start.pin, PIO_IN);

  setPullup(currentConfig.b1.bank, currentConfig.b1.pin, false);
  setPullup(currentConfig.b2.bank, currentConfig.b2.pin, false);
  setPullup(currentConfig.b3.bank, currentConfig.b3.pin, false);
  setPullup(currentConfig.b4.bank, currentConfig.b4.pin, false);

  setPullup(currentConfig.dUp.bank, currentConfig.dUp.pin,        false);
  setPullup(currentConfig.dDown.bank, currentConfig.dDown.pin,    false);
  setPullup(currentConfig.dLeft.bank, currentConfig.dLeft.pin,    false);
  setPullup(currentConfig.dRight.bank, currentConfig.dRight.pin,  false);

  setPullup(currentConfig.home.bank, currentConfig.home.pin, false);
  setPullup(currentConfig.start.bank, currentConfig.start.pin, false);
}

void getControlState(InputState * iState){
  iState->b1 = READ_PIN(currentConfig.b1);
  iState->b2 = READ_PIN(currentConfig.b2);
  iState->b3 = READ_PIN(currentConfig.b3);
  iState->b4 = READ_PIN(currentConfig.b4);

  iState->dUp   = READ_PIN(currentConfig.dUp);
  iState->dDown = READ_PIN(currentConfig.dDown);
  iState->dLeft = READ_PIN(currentConfig.dLeft);
  iState->dRight= READ_PIN(currentConfig.dRight);

  iState->home = READ_PIN(currentConfig.home);
  iState->start = READ_PIN(currentConfig.start);
}
