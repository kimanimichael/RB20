#include <mbed_infrared5channel.h>

#include "bsp.h"
#include "mbed_dc_motor_ft_smc.h"
#include "pinouts.h"

namespace BSP
{
    unsigned int BSPInit() {
        return 0;
    }
    void BSP_Delay(unsigned int delay_ms) {

    }
    void initActuators() {
        getDefaultKinematicsLeftMotor()->init();
        getDefaultKinematicsRightMotor()->init();
    }
    void initSensors() {
        getDefaultKinematicsLeftMotor()->init();
    }

    DcMotor* getDefaultKinematicsLeftMotor() {
        static MbedDCMotor kinematics_motor(FT_SMC_LT_MOTOR_PWM, CLOCKWISE, LOW);
        return &kinematics_motor;
    }

    DcMotor* getDefaultKinematicsRightMotor() {
        static MbedDCMotor kinematics_motor(FT_SMC_RT_MOTOR_PWM, CLOCKWISE, LOW);
        return &kinematics_motor;
    }

    DcMotor* getDefaultSteeringMotor() {
        return nullptr;
    }

    Infrared5Channel* getDefaultInfraredSensor() {
        static MbedInfrared5Channel infrared_sensor(IR_FAR_LEFT, IR_CLOSE_LEFT, IR_MIDDLE, IR_CLOSE_RIGHT, IR_FAR_RIGHT);
        return &infrared_sensor;
    }

}