#ifndef __PID__
#define __PID__
class PID
{

public:
    PID(double kp, double ki, double kd);
    // ~pid();
public:
   
    double output;
    double _dt;

    double calculateOutput(double setPoint, double processVariable);

private:
    /* data */
    double _setPoint;
    double _processVariable;
    double _error;
    double _previousError;
    double _integral;
    double _derivative;
    double _kp;
    double _ki;
    double _kd;
    double _previousOutput;

};

#endif


