#include "kinematics_pid.h"
#include <stdio.h>
#include "bsp.h"

BSP::DcMotor* kinematicsLeftMotor = BSP::getDefaultKinematicsLeftMotor();
BSP::DcMotor* kinematicsRightMotor = BSP::getDefaultKinematicsRightMotor();

#define LEFT_MOTOR_BASE_SPEED 83200
#define RIGHT_MOTOR_BASE_SPEED 82700
// #define RIGHT_MOTOR_MAX_SPEED 79


unsigned int leftMotorSpeed;
unsigned int rightMotorSpeed;

double controlCarKinematics() {

    leftMotorSpeed = int((LEFT_MOTOR_BASE_SPEED - cornerSpeedDiff) - (PIDOutput*700));
    rightMotorSpeed = int((RIGHT_MOTOR_BASE_SPEED- (float (cornerSpeedDiff)*(float (82700)/float (83200)))) + (PIDOutput*700));
    // if (rightMotorSpeed > RIGHT_MOTOR_MAX_SPEED) {
    //     rightMotorSpeed = RIGHT_MOTOR_MAX_SPEED;
    // }

     printf("Left Motor: %u || Right Motor: %u\n", leftMotorSpeed, rightMotorSpeed);

    kinematicsLeftMotor->set_dir(BSP::CLOCKWISE);
    kinematicsLeftMotor->set_raw_speed(leftMotorSpeed);

    kinematicsRightMotor->set_dir(BSP::CLOCKWISE);
    kinematicsRightMotor->set_raw_speed(rightMotorSpeed);
    return PIDOutput;
}