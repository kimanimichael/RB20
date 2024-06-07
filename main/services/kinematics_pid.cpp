#include "kinematics_pid.h"
#include <stdio.h>
#include "bsp.h"

BSP::DcMotor* kinematicsLeftMotor = BSP::getDefaultKinematicsLeftMotor();
BSP::DcMotor* kinematicsRightMotor = BSP::getDefaultKinematicsRightMotor();

#define LEFT_MOTOR_BASE_SPEED 79
#define RIGHT_MOTOR_BASE_SPEED 78
// #define RIGHT_MOTOR_MAX_SPEED 79


unsigned int leftMotorSpeed;
unsigned int rightMotorSpeed;

double controlCarKinematics() {

    leftMotorSpeed = LEFT_MOTOR_BASE_SPEED - PIDOutput;
    rightMotorSpeed = RIGHT_MOTOR_BASE_SPEED + PIDOutput;
    // if (rightMotorSpeed > RIGHT_MOTOR_MAX_SPEED) {
    //     rightMotorSpeed = RIGHT_MOTOR_MAX_SPEED;
    // }

    // printf("Left Motor: %u || Right Motor: %u\n", leftMotorSpeed, rightMotorSpeed);

    kinematicsLeftMotor->set_dir(BSP::CLOCKWISE);
    kinematicsLeftMotor->set_raw_speed(leftMotorSpeed);

    kinematicsRightMotor->set_dir(BSP::CLOCKWISE);
    kinematicsRightMotor->set_raw_speed(rightMotorSpeed);
    return PIDOutput;
}