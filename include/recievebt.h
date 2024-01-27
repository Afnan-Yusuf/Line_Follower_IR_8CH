#pragma once
#include "variables.h"
String incomingData;
void recvWithEndMarker()
{
    if (BT.available() > 0)
    {
        incomingData = BT.readStringUntil('/');
        btpidv(incomingData);
    }
    // BT.println(irdig,BIN);
}

void btpidv(const String &data)
{
    _PM("Incoming Value: ");
    _PL(data);

    for (int cnt = 0; cnt <= data.length(); cnt++)
    {
        switch (data.charAt(cnt))
        {
        case 'P':
            Kp = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed P value to ");
            _PL(Kp);
            BT.println(Kp);
            cnt += 5;
            break;
        case 'I':
            Ki = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed I value to ");
            _PL(Ki);
            BT.println(Ki);
            cnt += 5;
            break;
        case 'T':
            T = data.substring(cnt + 1, cnt + 6).toInt();
            _PM("Changed T value to ");
            _PL(T);
            BT.println(T);
            cnt += 5;
            break;
        case 'D':
            Kd = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed D value to ");
            _PL(Kd);
            BT.println(Kd);
            cnt += 5;
            break;

        case 'p':
            Kpp = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed P value to ");
            _PL(Kp);
            BT.println(Kpp);
            cnt += 5;
            break;
        case 'i':
            Kii = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed I value to ");
            BT.println(Kii);
            cnt += 5;
            break;
        case 'd':
            Kdd = data.substring(cnt + 1, cnt + 6).toFloat();
            _PM("Changed D value to ");
            _PL(Kdd);
            BT.println(Kdd);
            cnt += 5;
            break;

        case 'N':
            minspeed = data.substring(cnt + 1, cnt + 6).toInt();
            _PM("Changed MinSpeed value to ");
            _PL(minspeed);
            BT.println(minspeed);
            cnt += 5;
            break;
        case 'X':
            maxspeed = data.substring(cnt + 1, cnt + 6).toInt();
            _PM("Changed MaxSpeed value to ");
            _PL(maxspeed);
            BT.println(maxspeed);
            cnt += 5;
            break;
        case 'S':
            basespeed = data.substring(cnt + 1, cnt + 6).toInt();
            _PM("Changed Base Speed to ");
            _PL(basespeed);
            BT.println(basespeed);
            cnt += 5;
            break;

        case 'C':
            tunrspeed = data.substring(cnt + 1, cnt + 6).toInt();
            _PM("Changed Base turnspeed to ");
            _PL(tunrspeed);
            BT.println(tunrspeed);
            cnt += 5;
            break;
        default:
            break;
        }
    }
    P = I = D = 0;
}