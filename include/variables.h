#pragma once
#include <Arduino.h>
#include <PushButton.h>
#include <TaskScheduler.h>
#include "BluetoothSerial.h"
#include "macros.h"
// #define _DEBUG_

int position;
void btpidv(const String &data);
BluetoothSerial BT;
const byte numChars = 10;
char receivedChars[numChars]; // an array to store the received data
boolean newData = false;

int a, b, m, n, x, y;
char e, f, g;

float Kp = 30;
float Ki = 0.00;
float Kd = 0;

float Kpp = 10;
float Kii = 0.00;
float Kdd = 0;
int basespeed = 150;  // base speed of motor
int minspeed = (-50); // min speed of motor
int maxspeed = 235;   // max speed of motor
int tunrspeed = 400;
int T = 2; // sample time for pid calculation

#define motlf 5 // motor pins
#define motlb 18
#define motrf 21
#define motrb 19
#define encr 17
#define encl 16

const int freqm = 5000; // motor pwm frequency
const int mrfc = 0;     // Motor Right Forward Channel (mrfc)
const int mrbc = 2;     // Motor Right Backward Channel (mrbc)
const int mlfc = 4;     // Motor Left Forward Channel (mlfc)
const int mlbc = 6;     //
const int mpwmr = 8;    // motor pwm resolution(8bit)
int rpwm = 0;           // pwm value to right motor
int lpwm = 0;           // pwm value to left motor

int onlinval = 0;
int threshold = 100;
const int irarray[8] = {13, 12, 14, 27, 26, 25, 33, 32};
const int centerarray[2] = {27, 26};      // ir array pins
uint16_t irval[8] = {0, 0, 0, 0, 0, 0, 0, 0};                    // ir raw value
int irmin[8] = {5000, 5000, 5000, 5000, 5000, 5000, 5000, 5000}; // stores ir minim value after calib
int irmax[8] = {0, 0, 0, 0, 0, 0, 0, 0};                         // stores ir maximum value after calib
int irout[8] = {0, 0, 0, 0, 0, 0, 0, 0};                         // mapped ir values to usable range from min max range
const int irrange = 2000;                                         // maximum value for mapping ir value
int irbin[8] = {0, 0, 0, 0, 0, 0, 0, 0};                         // stores ir value in binary
bool calibsts = false;                                           // calib status
const int calres = 1600;                                          // no of samples to be taken for calibration
int center = 0;
int irdig = B00000000;
int error = 0; // position on the line from ir
float centererror = 0;
#define onlinesensor 35
float P; // pid variables
float I;
float D;
float pidval = 0;
float lasterror;
float P1; // pid variables
float I1;
float D1;
float lasterror1;

unsigned long currenttime = 0;
int dtime = 0;
unsigned long prevt = 0;

bool brakeFlag = 0;
bool onLine = true; // on line variable
unsigned long times;
unsigned long prev = 0;
int t;

PushButton starbutton(15); // start button pin
PushButton calbutton(2);   // calibrate button pin

void log();
void calibrateir();
void readerrorb();        // read error in binary
void readbutton();        // read buttons
void pid_control();       // pid control
void recvWithEndMarker(); // bluetooth receiving
void btpidv();            // assinging pid values
volatile int encoder1_value = 0;
volatile int encoder2_value = 0; // Global variable for storing the encoder position

void encoder1_isr()
{
  int A = digitalRead(encl);
  if (A == HIGH)
  {
    encoder1_value++;
  }
}
void encoder2_isr()
{
  int B = digitalRead(encr);
  if (B == HIGH)
  {
    encoder2_value++;
  }
}
Scheduler ts;                                                              // task scheduler object
Task readirb(TASK_IMMEDIATE, TASK_FOREVER, &readerrorb, &ts, false);       // task for reading ir in binary
Task pid(TASK_IMMEDIATE, TASK_FOREVER, &pid_control, &ts, false);          // task for pid calculations
Task readsw(TASK_IMMEDIATE, TASK_FOREVER, &readbutton, &ts, false);        // task for reading buttons
Task btread(TASK_IMMEDIATE, TASK_FOREVER, &recvWithEndMarker, &ts, false); // task for bluetooth receiving
Task logTask(500, TASK_FOREVER, &log, &ts, false);
