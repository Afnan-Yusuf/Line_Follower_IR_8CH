#pragma once
#include "variables.h"
void pid_control()
{
  //_PP("pid: ");

  currenttime = millis();
  dtime = currenttime - prevt;
  if (onLine == true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    brakeFlag = 0;

    if (dtime >= T)
    {

      P = centererror;
      I = I + centererror;
      D = lasterror - centererror;
      //_PL("small error");
      pidval = ((P * Kp) + ((Ki * T) * I) + ((Kd / T) * D)); // calculater pid val
      lasterror = error;

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
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
    if (error > 0)
    {
      if (brakeFlag == 0)
      {
        ledcWrite(mrfc, 0); // write all pwmm channel 0
        ledcWrite(mrbc, 0);
        ledcWrite(mlfc, 0);
        ledcWrite(mlbc, 0);
        delay(30);
      }

      brakeFlag = 1;
      ledcWrite(mrfc, 100); 
      ledcWrite(mrbc, 0);
      ledcWrite(mlfc, 0);
      ledcWrite(mlbc, 100);
    }
    else if (error < 0)
    {
      if (brakeFlag == 0)
      {
        ledcWrite(mrfc, 0); // write all pwmm channel 0
        ledcWrite(mrbc, 0);
        ledcWrite(mlfc, 0);
        ledcWrite(mlbc, 0);
        delay(30);
      }

      brakeFlag = 1;
      ledcWrite(mrfc, 0); 
      ledcWrite(mrbc, 100);
      ledcWrite(mlfc, 100);
      ledcWrite(mlbc, 0);
    }
  }
}