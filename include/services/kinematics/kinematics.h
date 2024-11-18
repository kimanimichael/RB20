#ifndef __KINEMATICS__
#define __KINEMATICS__


#include "bsp_dc_motor.h"

enum carKinematicsStates {
    idling,
    drivingLeft,
    drivingSlowLeft,
    drivingRight,
    drivingSlowRight,
    drivingBoth,
    braking,
    reversingLeft,
    reversingRight
};

extern carKinematicsStates RB19Kinematics;


/**
 * @brief Control vehicular kinematics: braking and accelerating
*/
void controlCarKinematics();

#endif