
#include "variables.h"
#include "calibrate.h"
#include "pidcontrol.h"
#include "error.h"
#include "recievebt.h"
#include "ui.h"
void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  ledcSetup(mrfc, freqm, mpwmr); // pwm channel and frequency and resolution setup
  ledcSetup(mrbc, freqm, mpwmr);
  ledcSetup(mlfc, freqm, mpwmr);
  ledcSetup(mlbc, freqm, mpwmr);
  ledcAttachPin(motrf, mrfc); // attach motor pins pwm channels
  ledcAttachPin(motrb, mrbc);
  ledcAttachPin(motlf, mlfc);
  ledcAttachPin(motlb, mlbc);
  ledcWrite(mrfc, 0); // write all pwmm channel 0
  ledcWrite(mrbc, 0);
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, 0);
  pinMode(encl, INPUT_PULLUP);
  pinMode(encr, INPUT_PULLUP);
  pinMode(onlinesensor, INPUT);
  // attachInterrupt(digitalPinToInterrupt(encl), encoder1_isr, CHANGE);
  // attachInterrupt(digitalPinToInterrupt(encr), encoder2_isr, CHANGE);
  for (int i = 0; i <= 7; i++)
  {
    pinMode(irarray[i], INPUT);
  }
  BT.begin("LFIR");
  starbutton.setActiveLogic(HIGH);
  calbutton.setActiveLogic(HIGH);
  ts.addTask(readirb);
  ts.addTask(pid);
  ts.addTask(readsw);
  ts.addTask(btread);
  ts.addTask(logTask);
  readirb.enable();
  readsw.enable();
#ifdef _DEBUG_
  Serial.begin(115200);
  logTask.enable();
#endif
}

void loop()
{
  ts.execute();
}
