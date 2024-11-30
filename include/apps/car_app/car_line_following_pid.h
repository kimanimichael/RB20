#ifndef __CAR_LF__PID
#define __CAR_LF__PID

#include "pid.h"
#include "bsp.h"

extern double PIDOutput;

extern int cornerSpeedDiff;

void carAppInit();

void carAppRun();

#endif