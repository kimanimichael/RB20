#ifndef __BSP_H__
#define __BSP_H__

#include "bsp_dc_motor.h"
#include "bsp_infrared5channel.h"

namespace BSP{

/**
 * @brief Initialize board support
 * @author MK
*/
unsigned int BSPInit();

/**
 * @brief Init car actuators
 * @author MK
*/
void initActuators();

/**
 * @brief Init car sensors
 * @author MK
*/
void initSensors();

/**
 * @brief gets default instance of kinematics left motor
 * @return pointer to default kinematics left motor
 * @author MK
*/
DcMotor* getDefaultKinematicsLeftMotor();

/**
 * @brief gets default instance of kinematics right motor
 * @return pointer to default kinematics right motor
 * @author MK
*/
DcMotor* getDefaultKinematicsRightMotor();

/**
 * @brief gets default instance of steering motor
 * @return pointer to default steering motor
 * @author MK
*/
DcMotor* getDefaultSteeringMotor();

/**
 * @brief gets default instance of the 5 channel infrared sensor
 * @return pointer to default 5 channel infrared sensor
 * @author MK
*/
Infrared5Channel* getDefaultInfraredSensor();

}
#endif