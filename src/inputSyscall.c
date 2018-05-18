#include "inputSyscall.h"
#include "input.h"

void initConfigCall(void * config){
  InputConfigSysCall * pConfig = (InputConfigSysCall*)config;
  InputConfig iConfig;

  iConfig.b1 = toPin(pConfig->b1_bank,pConfig->b1_pin, NULL);
  iConfig.b2 = toPin(pConfig->b2_bank,pConfig->b2_pin, NULL);
  iConfig.b3 = toPin(pConfig->b3_bank,pConfig->b3_pin, NULL);
  iConfig.b4 = toPin(pConfig->b4_bank,pConfig->b4_pin, NULL);

  iConfig.dUp = toPin(pConfig->dUp_bank,pConfig->dUp_pin, NULL);
  iConfig.dDown = toPin(pConfig->dDown_bank,pConfig->dDown_pin, NULL);
  iConfig.dLeft = toPin(pConfig->dLeft_bank,pConfig->dLeft_pin, NULL);
  iConfig.dRight = toPin(pConfig->dRight_bank,pConfig->dRight_pin, NULL);

  iConfig.home = toPin(pConfig->home_bank, pConfig->home_pin, NULL);
  iConfig.start = toPin(pConfig->start_bank, pConfig->start_pin, NULL);

  initConfig(&iConfig);
}

void initDefaultCall(void * nop){
  initDefault();
}


void getControlStateCall(void * iState){
  getControlState((InputState * )iState);
}
