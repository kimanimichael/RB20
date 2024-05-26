#include "pid.h"

PID::PID(double kp, double ki, double kd):
    _kp(kp), _ki(ki), _kd(kd)
{

}

double PID::calculateOutput(double setPoint, double processVariable) {
    _setPoint = setPoint;
    _processVariable = processVariable;

    _error = _setPoint - _processVariable;
    _integral += _error * _dt;
    _derivative = (_error - _previousError)/_dt;

    output = _kp*_error + _ki*_integral + _kd * _derivative;
    _previousError = _error;

    return output;
}