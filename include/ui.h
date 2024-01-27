#pragma once
#include "variables.h"
void log()
{
  _PP(centererror);
  _PP("\t");
  // Print SensorValues array
  for (int va = 0; va < 8; va++)
  {
    _PP(irout[va]);
    _PP("\t");
  }
  _PP(error);
  _PP("\t");
  _PP(lpwm);
  _PP("\t");
  _PP(rpwm);
  _PP("\t");
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