#include "kinematics_pid.h"
#include "bsp.h"

BSP::DcMotor* kinematicsLeftMotor = BSP::getDefaultKinematicsLeftMotor();
BSP::DcMotor* kinematicsRightMotor = BSP::getDefaultKinematicsRightMotor();

unsigned int leftMotorSpeed;
unsigned int RightMotorSpeed;

void controlCarKinematics() {
    leftMotorSpeed = PIDOutput * 2;
    RightMotorSpeed = PIDOutput / 2;

    kinematicsLeftMotor->set_raw_speed(leftMotorSpeed);
    kinematicsRightMotor->set_raw_speed(RightMotorSpeed);
}