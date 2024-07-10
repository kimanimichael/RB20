#include "car_line_following_pid.h"

Infrared5Channel* infraredSensor;
Infrared5Channel::detectedChannels sensorDetectedChannels;

double lineError;
PID lineFollowingPid(0.5, 3.80, 1.10);
double PIDOutput;

void carAppInit() {
    infraredSensor = BSP::getDefaultInfraredSensor();
    carAppRun();
}

void carAppRun() {
    sensorDetectedChannels = infraredSensor->read();
    switch (sensorDetectedChannels)
    {
    case Infrared5Channel::detectedChannels::centralChannel:
        lineError = 0.0;
        break;
    case Infrared5Channel::detectedChannels::halfLeftChannel:
        lineError = -1.0;
        break;
    case Infrared5Channel::detectedChannels::farLeftChannel:
        lineError = -2.0;
        break;
    case Infrared5Channel::detectedChannels::halfRightChannel:
        lineError = 1.0;
        break;
    case Infrared5Channel::detectedChannels::farRightChannel:
        lineError = 2.0;
        break;
    default:
        break;
    }

    lineFollowingPid._dt = 0.025;
    PIDOutput = lineFollowingPid.calculateOutput(0, lineError);


}