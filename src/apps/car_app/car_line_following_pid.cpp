#include "car_line_following_pid.h"

Infrared5Channel* infraredSensor;
Infrared5Channel::detectedChannels sensorDetectedChannels;

double lineError;
PID lineFollowingPid(0.9, 3.80, 1.5);
double PIDOutput;

int cornerSpeedDiff;

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
        cornerSpeedDiff = 2000;
        break;
    case Infrared5Channel::detectedChannels::halfLeftChannel:
        lineError = -0.7;
        cornerSpeedDiff = 2000;
        break;
    case Infrared5Channel::detectedChannels::farLeftChannel:
        lineError = -1.4;
        cornerSpeedDiff = 2000;
        break;
    case Infrared5Channel::detectedChannels::halfRightChannel:
        lineError = 0.7;
        cornerSpeedDiff = 2000;
        break;
    case Infrared5Channel::detectedChannels::farRightChannel:
        lineError = 1.4;
        cornerSpeedDiff = 2000;
        break;
    default:
        break;
    }

    lineFollowingPid._dt = 0.25;
    PIDOutput = lineFollowingPid.calculateOutput(0, lineError);


}