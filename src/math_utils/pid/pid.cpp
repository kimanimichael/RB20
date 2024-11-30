#include "pid.h"
#include <cstdlib>
#include <stdio.h>

PID::PID(double kp, double ki, double kd):
    _kp(kp), _ki(ki), _kd(kd)
{

}

#define MAX_PID_OUTPUT 3
#define MIN_PID_OUTPUT -3
#define MAX_PID_DIFF 2

#define MAX_INTEGRAL_VALUE 2
#define MIN_INTEGRAL_VALUE -2

double PID::calculateOutput(double setPoint, double processVariable) {
    _setPoint = setPoint;
    _processVariable = processVariable;

    _error = _setPoint - _processVariable;
    _integral += 0;
    if (_integral > MAX_INTEGRAL_VALUE) {
        _integral = MAX_INTEGRAL_VALUE;
    }
    if (_integral < MIN_INTEGRAL_VALUE) {
        _integral = MIN_INTEGRAL_VALUE;
    }
    _derivative = (_error - _previousError)/_dt;

    printf("Integral: %.2f || Derivative: %.2f\n", _integral, _derivative);

    output = _kp*_error + _ki*_integral + _kd * _derivative;
    if (abs(output - _previousOutput) > MAX_PID_DIFF) {
        output = _previousOutput;
    }
    if (output > MAX_PID_OUTPUT) {
        output = _previousOutput;
    }
    if (output < MIN_PID_OUTPUT) {
        output = _previousOutput;
    }
    _previousError = _error;
    _previousOutput = output;
    

    return output;
}