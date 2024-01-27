#pragma once
#include "variables.h"
void readerrorb()
{
  onlinval = analogRead(onlinesensor);
  onlinval > 150 ? onLine = true : onLine = false;
  for (int i = 0; i <= 7; i++)
  {
    irval[i] = analogRead(irarray[i]);
    irout[i] = map(irval[i], irmin[i], irmax[i], 0, irrange);
    if (irout[i] > threshold)
    {
      bitWrite(irdig, i, 1);
    }
    else
    {
      bitWrite(irdig, i, 0);
    }
  }
  switch (irdig)
  {
  // calculating errors based on ir array outputs
  case B00011000:
    error = 0;
    break;
  case B11111111:
    error = 0;
  case B00010000:
    error = 1;
    break;
  case B00110000:
    error = 2;
    break;
  case B00100000:
    error = 3;
    break;
  case B01100000:
    error = 4;
    break;
  case B01000000:
    error = 5;
    break;
  case B11000000:
    error = 6;
    break;
  case B10000000:
    error = 7;
    break;

  case B00001000:
    error = (-1);
    break;
  case B00001100:
    error = (-2);
    break;
  case B00000100:
    error = (-3);
    break;
  case B00000110:
    error = (-4);
    break;
  case B00000010:
    error = (-5);
    break;
  case B00000011:
    error = (-6);
    break;
  case B00000001:
    error = (-7);
    break;

  case B00000000:
    error = lasterror1;
  }
  centererror = (irout[4] - irout[3])/10;
}