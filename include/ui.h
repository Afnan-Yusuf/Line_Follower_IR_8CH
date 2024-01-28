#pragma once
#include "variables.h"
void log()
{
  _PP(onlinval);
  _PP("\t");
  // Print SensorValues array
  _PP(error);
  _PP("\t");
  _PP(lpwm);
  _PP("\t");
  _PP(rpwm);
  _PP("\t");
  _PP(centererror);
  _PL();
}


void readbutton()
{
  starbutton.update();
  if (starbutton.isDoubleClicked())
  {
    if (pid.isEnabled() == false)
    {
      pid.enable();
    }
    else
    {
      pid.disable();
      ledcWrite(mrfc, 0); // write all pwmm channel 0
      ledcWrite(mrbc, 0);
      ledcWrite(mlfc, 0);
      ledcWrite(mlbc, 0);
      P = 0;
      I = 0;
      D = 0;
    }
  }
  if (starbutton.isHeld())
  {
    calibrateir();
  }
  pid.isEnabled() ? btread.disable() : btread.enable();
}