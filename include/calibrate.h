#include "variables.h"
void calibrateir() // calibration
{
    digitalWrite(LED_BUILTIN, HIGH);
    _PL("calibrating");
    for (int k = 0; k < calres; k++) // take samples of ir values for calibration
    {
        for (int i = 0; i <= 7; i++)
        { // reading ir values
            irval[i] = analogRead(irarray[i]);
            if (irval[i] > irmax[i])
                irmax[i] = irval[i];
            if (irval[i] < irmin[i])
                irmin[i] = irval[i];
        }
        delay(5);
    }
    for (int j = 0; j <= 7; j++)
    {
        _PP(irmax[j]);
        _PP("\t");
    }
    _PL("");
    for (int j = 0; j <= 7; j++)
    {
        _PP(irmin[j]);
        _PP("\t");
    }
    digitalWrite(LED_BUILTIN, LOW);
    _PL("");
}
