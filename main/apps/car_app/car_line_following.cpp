#include "car_line_following.h"
#include "steering.h"
#include "kinematics.h"
#include <stdio.h>

Infrared5Channel* infraredSensor;
Infrared5Channel::detectedChannels sensorDetectedChannels;

carSteerStates RB19Steer;
carKinematicsStates RB19Kinematics;

void carAppInit() {
    RB19Kinematics = idling;
    infraredSensor = BSP::getDefaultInfraredSensor();
    carAppRun();
}

void carAppRun() {
    sensorDetectedChannels = infraredSensor ->read();
    switch (sensorDetectedChannels)
    {
    case Infrared5Channel::detectedChannels::centralChannel:
        /* code */
        RB19Kinematics = drivingBoth;
        break;
    case Infrared5Channel::detectedChannels::farLeftChannel:
        /* code */
        RB19Kinematics = drivingRight;
        break;
    case Infrared5Channel::detectedChannels::farRightChannel:
        /* code */
        RB19Kinematics = drivingLeft;
        break;
    case Infrared5Channel::detectedChannels::noChannel:
        /* code */
        RB19Kinematics = RB19Kinematics;
        printf("Car maintaining drive \n");
        
        break;
    default:
        break;
    }
}