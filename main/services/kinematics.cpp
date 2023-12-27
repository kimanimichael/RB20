#include <stdio.h>
#include "kinematics.h"
#include "bsp.h"

#define MOTOR_FORWARD_DIR BSP::motorDirections::CLOCKWISE
#define MOTOR_REVERSE_DIR BSP::motorDirections::COUNTERCLOCKWISE

#define MOTOR_LOW_SPEED BSP::motorSpeeds:: LOW
#define MOTOR_MEDIUM_SPEED BSP::motorSpeeds::MEDIUM
#define MOTOR_HIGH_SPEED BSP::motorSpeeds::HIGH


BSP::DcMotor* kinematicsLeftMotor;
BSP::DcMotor* kinematicsRightMotor;
extern carKinematicsStates RB19Kinematics;


void controlCarKinematics() {

    kinematicsLeftMotor = BSP::getDefaultKinematicsLeftMotor();
    kinematicsRightMotor = BSP::getDefaultKinematicsRightMotor();

    switch (RB19Kinematics)
    {
    case idling:
        /* code */
        kinematicsLeftMotor->stop();
        break;
    case drivingLeft:
        kinematicsRightMotor->stop();
        kinematicsLeftMotor->set_dir(MOTOR_FORWARD_DIR);
        kinematicsLeftMotor->set_speed(MOTOR_LOW_SPEED);
        printf("Driving Left motor \n");
        break;
    case drivingRight:
        kinematicsLeftMotor->stop();
        kinematicsRightMotor->set_dir(MOTOR_FORWARD_DIR);
        kinematicsRightMotor->set_speed(MOTOR_LOW_SPEED);
        printf("Driving Right motor \n");
        break;
    case drivingBoth:
        kinematicsRightMotor->set_dir(MOTOR_FORWARD_DIR);
        kinematicsRightMotor->set_speed(MOTOR_LOW_SPEED);
        kinematicsLeftMotor->set_dir(MOTOR_FORWARD_DIR);
        kinematicsLeftMotor->set_speed(MOTOR_LOW_SPEED);
        printf("Driving both motors \n");
        break;
    case braking:
        kinematicsLeftMotor->stop();
        kinematicsRightMotor->stop();
        printf("Braking \n");
        break;
    case reversingLeft:
        kinematicsRightMotor->stop();
        kinematicsLeftMotor->set_dir(MOTOR_REVERSE_DIR);
        kinematicsLeftMotor->run();
        printf("Reversing Left motor \n");
        break;
    case reversingRight:
        kinematicsLeftMotor->stop();
        kinematicsRightMotor->set_dir(MOTOR_REVERSE_DIR);
        kinematicsRightMotor->run();
        printf("Reversing right motor \n");
        break;
    default:
        break;
    }
}