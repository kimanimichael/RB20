#include "bsp.h"
#include "steering.h"

#define MOTOR_LEFT_DIR BSP::motorDirections::CLOCKWISE
#define MOTOR_RIGHT_DIR BSP::motorDirections::COUNTERCLOCKWISE

BSP::DcMotor* steeringMotor;
extern carSteerStates RB19Steer;


void steerCar () {

    steeringMotor = BSP::getDefaultSteeringMotor();
    
    switch (RB19Steer)
    {
    case steerIdling:
        steeringMotor->stop();
        break;
    case left:
        steeringMotor->set_dir(MOTOR_LEFT_DIR);
        steeringMotor->run();
        break;
    case right:
        steeringMotor->set_dir(MOTOR_RIGHT_DIR);
        steeringMotor->run();
        break;
    default:
        break;
    }
}



