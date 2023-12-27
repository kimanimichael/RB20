#include "bsp.h"
#include "esp32_dc_motor_l298n.h"
#include "esp32_dc_motor_ft_smc.h"
#include "esp32_infrared5channel.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

namespace BSP {

unsigned int BSPInit() {
    initSensors();
    initActuators();
    vTaskDelay(5000/portTICK_PERIOD_MS);
    getDefaultKinematicsLeftMotor()->set_speed(BSP::motorSpeeds::LOW);
    vTaskDelay(5000/portTICK_PERIOD_MS);
    getDefaultKinematicsLeftMotor()->set_speed(BSP::motorSpeeds::LOW);
    return 0;
}

void initActuators(){
    getDefaultKinematicsLeftMotor()->init();
    getDefaultKinematicsRightMotor()->init();
    getDefaultSteeringMotor()->init();
}

void initSensors(){
    getDefaultInfraredSensor() ->init();
}

DcMotor* getDefaultKinematicsLeftMotor() {
    // static ESP32DcMotorL298N kinematicsMotor(GPIO_NUM_15, GPIO_NUM_16, GPIO_NUM_4, BSP::motorDirections::FORWARD);
    static ESP32DCMotorFtSmc kinematicsMotor(GPIO_NUM_2, BSP::motorDirections::CLOCKWISE, BSP::motorSpeeds::LOW, LEDC_CHANNEL_0);
    return &kinematicsMotor;
}

DcMotor* getDefaultKinematicsRightMotor() {
    static ESP32DCMotorFtSmc kinematicsMotor(GPIO_NUM_16, BSP::motorDirections::CLOCKWISE, BSP::motorSpeeds::LOW, LEDC_CHANNEL_1);
    return &kinematicsMotor;
}

DcMotor* getDefaultSteeringMotor() {
    static ESP32DcMotorL298N steeringMotor(GPIO_NUM_27, GPIO_NUM_12, GPIO_NUM_14, BSP::motorDirections::CLOCKWISE);
    return &steeringMotor;
}

Infrared5Channel* getDefaultInfraredSensor() {
    static ESP32Infrared5Channel infraredSensor(GPIO_NUM_23, GPIO_NUM_19, GPIO_NUM_32, GPIO_NUM_35, GPIO_NUM_34);
    return &infraredSensor;
}
}
