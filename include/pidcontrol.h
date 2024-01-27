#pragma once
#include "variables.h"
void pid_control()
{
  //_PP("pid: ");
  if (onLine == true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  currenttime = millis();
  dtime = currenttime - prevt;
  if (dtime >= T)
  {

    if (onLine == true)
    {
      P = centererror;
      I = I + centererror;
      D = lasterror - centererror;
      _PL("small error");
      pidval = ((P * Kp) + ((Ki * T) * I) + ((Kd / T) * D)); // calculater pid val
    lasterror = centererror;
    }
    else if (onLine == false)
    {
      P1 = error;
      I1 = I + error;
      D1 = lasterror1 - error;
      _PL("large error");
      pidval = ((P1 * Kpp) + ((Kii * T) * I1) + ((Kdd / T) * D1)); // calculater pid val
      lasterror1 = error;
    }
    
    prevt = currenttime;
  }

  int lmspeed = basespeed + pidval; // get motor speed difference from pid val
  int rmspeed = basespeed - pidval; // get motor speed difference from pid val

  if (lmspeed > maxspeed)
  { // if motor speed is greater than max speed set motor speed tot max speed
    lmspeed = maxspeed;
  }
  if (rmspeed > maxspeed)
  { // if motor speed is greater than max speed set motor speed tot max speed
    rmspeed = maxspeed;
  }
  if (lmspeed < minspeed)
  { // if mot speed less  than min speed set mot speed to min speed
    lmspeed = minspeed;
  }
  if (rmspeed < minspeed)
  { // if mot speed less  than min speed set mot speed to min speed
    rmspeed = minspeed;
  }

  rpwm = abs(rmspeed); // pwm value to write to motor
  lpwm = abs(lmspeed);

  if (rmspeed > 0)
  { // if right mot speed is > 0 turn in forward direction else in backward
    ledcWrite(mrfc, rpwm);
    ledcWrite(mrbc, 0);
  }
  else
  {
    ledcWrite(mrfc, 0);
    ledcWrite(mrbc, rpwm);
  }
  if (lmspeed > 0)
  { // if left mot speed is > 0 turn in forward direction else in backward
    ledcWrite(mlfc, lpwm);
    ledcWrite(mlbc, 0);
  }
  else
  {
    ledcWrite(mlfc, 0);
    ledcWrite(mlbc, lpwm);
  }
}