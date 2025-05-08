#include "esp32_dc_motor_l298n.h"

ESP32DcMotorL298N::ESP32DcMotorL298N(gpio_num_t enable, gpio_num_t dir1, gpio_num_t dir2, BSP::motorDirections powerUnitDir = BSP::motorDirections::CLOCKWISE)
: _en(enable), _in1(dir1), _in2(dir2), driveMotorDir(powerUnitDir)
{

}

void ESP32DcMotorL298N::init() {
    gpio_set_direction(_en, GPIO_MODE_OUTPUT);
    gpio_reset_pin(_en);
    gpio_set_direction(_in1, GPIO_MODE_OUTPUT);
    gpio_set_direction(_in2, GPIO_MODE_OUTPUT);

}
/**
 * @todo Remove repetitive checks lol
*/
void ESP32DcMotorL298N::set_dir(BSP::motorDirections powerUnitDir) {
    switch (powerUnitDir)
    {
    case BSP::motorDirections::CLOCKWISE:
        gpio_set_level(_in1, 1);
        gpio_set_level(_in2, 0);
        break;
    case BSP::motorDirections::COUNTERCLOCKWISE:
        gpio_set_level(_in1, 0);
        gpio_set_level(_in2, 1);
        break;
    default:
        break;
    }

}

void ESP32DcMotorL298N::run() {
    gpio_set_level(_en, 1);
}

void ESP32DcMotorL298N::stop() {
    gpio_set_level(_en,0);
    gpio_set_level(_in1, 1);
    gpio_set_level(_in2, 1);
}

void ESP32DcMotorL298N::set_speed(BSP::motorSpeeds speed) {

}

void ESP32DcMotorL298N::set_raw_speed(unsigned int speed) {

}