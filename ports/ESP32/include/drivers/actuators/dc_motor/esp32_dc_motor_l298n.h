#ifndef __ESPDCMOTOR__
#define __ESPDCMOTOR__

#include "bsp_dc_motor.h"
#include "driver/gpio.h"

class ESP32DcMotorL298N: public BSP::DcMotor {

public:
    enum motorDireciton {
        forward,
        reverse
    };
    int testy;

private:
    gpio_num_t _en;
    gpio_num_t _in1;
    gpio_num_t _in2;
    BSP::motorDirections driveMotorDir;
    int _dir;

public:
    ESP32DcMotorL298N(gpio_num_t enableFront, gpio_num_t dir1, gpio_num_t dir2, BSP::motorDirections powerUnitDir);

    /**
     * @brief Initialize motor control pins
    */
    void init() override;
    /**
     * @brief Set motor direction
    */
    void set_dir(BSP::motorDirections powerUnitDir) override;
    /**
     * @brief Run motor
    */
    void run() override;
    /**
     * @brief Stop motor
    */
    void stop() override;

    /**
     * @brief Set motor speed
    */
    void set_speed(BSP::motorSpeeds speed) override;

    /**
     * @brief Sets a motor's raw speed
    */
    void set_raw_speed(unsigned int speed) override;



};


#endif