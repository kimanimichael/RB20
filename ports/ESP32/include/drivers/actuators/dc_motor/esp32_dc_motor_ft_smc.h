#include "bsp_dc_motor.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include <map>

class ESP32DCMotorFtSmc : public BSP::DcMotor {
public:
    ESP32DCMotorFtSmc(gpio_num_t signal, BSP::motorDirections direction, BSP::motorSpeeds speed, ledc_channel_t motorChannel);

    void init() override;

    /**
     * @brief Configure a pin to use LEDC_PWM
    */
    void configure_pwm(gpio_num_t signal);

    void set_dir(BSP::motorDirections direction) override;
    /**
     * @brief sets motor speed
     * @attention must call set_dir() before this for well defined behaviour
    */
    void set_speed(BSP::motorSpeeds speed) override;

    void run() override;

    void stop() override;

    /**
     * @brief Sets a motor's raw speed
    */
    void set_raw_speed(unsigned int speed) override;

    /**
     * @brief Validate the set motor speed value
    */
    unsigned int validate_motor_speed(unsigned int speed);
private:
    gpio_num_t _signal;
    unsigned int _pwmDuty;
    BSP::motorDirections _direction;
    BSP::motorSpeeds _speed;
    ledc_channel_t _motorChannel;
    std::map<BSP::motorSpeeds, int> _clockWiseSpeedMap;
    std::map<BSP::motorSpeeds, int> _counterClockWiseSpeedMap;
};  