#include "pid.h"
#include <cstdlib>

PID::PID(double kp, double ki, double kd):
    _kp(kp), _ki(ki), _kd(kd)
{

}

#define MAX_PID_OUTPUT 40
#define MIN_PID_OUTPUT 40
#define MAX_PID_DIFF 1

double PID::calculateOutput(double setPoint, double processVariable) {
    _setPoint = setPoint;
    _processVariable = processVariable;

    _error = _setPoint - _processVariable;
    _integral += _error * _dt;
    _derivative = (_error - _previousError)/_dt;

    output = _kp*_error + _ki*_integral + _kd * _derivative;
    if (abs(output - _previousOutput) > MAX_PID_DIFF) {
        output = _previousOutput;
    }
    _previousError = _error;
    _previousOutput = output;
    

    return output;
}