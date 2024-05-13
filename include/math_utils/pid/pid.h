#ifndef __PID__
#define __PID__
class PID
{

public:
    PID(/* args */);
    // ~pid();
public:
   
    double output;

    double calculateOutput(double setPoint, double processVariable);

private:
    /* data */
    double _dt;
    double _setPoint;
    double _processVariable;
    double error;
    double previousError;
    double integral;
    double derivative;
    double kp;
    double ki;
    double kd;

};

#endif


