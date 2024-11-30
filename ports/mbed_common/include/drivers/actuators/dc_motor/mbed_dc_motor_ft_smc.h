#ifndef MBED_DC_MOTOR_FT_SMC_H
#define MBED_DC_MOTOR_FT_SMC_H

#include "bsp_dc_motor.h"
#include "mbed.h"
#include "map"

class MbedDCMotor: public BSP::DcMotor {
public:

    MbedDCMotor(const PwmOut& motor_signal, BSP::motorDirections direction, BSP::motorSpeeds speed);

    void init() override;
    /**
     * @brief sets motor direction
     * @attention must call set_speed() after to take effect
    */
    void set_dir(BSP::motorDirections direction) override;
    /*!
    @
     */
    void set_speed(BSP::motorSpeeds speed) override;

    void run() override;

    void stop() override;

    /**
    * @brief Validate the set motor speed value
    */
    float validate_motor_speed(unsigned int speed);

    /**
    * @brief Sets a motor's raw speed
    */
    void set_raw_speed(unsigned int speed) override;

private:
    PwmOut _motor_signal_pin;
    BSP::motorDirections _direction;
    BSP::motorSpeeds _speed;
    std::map<BSP::motorSpeeds, int> _clockWiseSpeedMap;
    std::map<BSP::motorSpeeds, int> _counterClockWiseSpeedMap;
    unsigned int _pulse_period_us{};
    float _pwmDuty{};
};

#endif

