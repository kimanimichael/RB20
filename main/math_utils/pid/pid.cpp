#include "pid.h"

PID::PID() {

}

double PID::calculateOutput(double setPoint, double processVariable) {
    _setPoint = setPoint;
    _processVariable = processVariable;

    error = _setPoint - _processVariable;
    integral += error * _dt;
    derivative = (error - previousError)/_dt;

    output = kp*error + ki*integral + kd * derivative;
    previousError = error;

    return output;
}