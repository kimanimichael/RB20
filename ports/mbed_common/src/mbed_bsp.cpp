#include "bsp.h"

namespace BSP
{
    unsigned int BSPInit() {
        return 0;
    }
    void BSP_Delay(unsigned int delay_ms) {

    }
    void initActuators() {

    }
    void initSensors() {

    }

    DcMotor* getDefaultKinematicsLeftMotor() {
        return nullptr;
    }

    DcMotor* getDefaultKinematicsRightMotor() {
        return nullptr;
    }

    DcMotor* getDefaultSteeringMotor() {
        return nullptr;
    }

    Infrared5Channel* getDefaultInfraredSensor() {
        return nullptr;
    }

}