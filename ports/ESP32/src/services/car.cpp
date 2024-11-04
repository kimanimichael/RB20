#include "car.h"
#include "esp32_dc_motor_l298n.h"

// carStates fwHwComp;

ESP32DcMotorL298N frontMotor(GPIO_NUM_10, GPIO_NUM_11, GPIO_NUM_2, BSP::motorDirections::CLOCKWISE);
ESP32DcMotorL298N steerMotor(GPIO_NUM_13, GPIO_NUM_14, GPIO_NUM_15, BSP::motorDirections::CLOCKWISE);

void front_lights_on() {
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_NUM_2, 1);
}

void front_lights_off() {
    gpio_set_level(GPIO_NUM_2, 0);
}

// void carIdling() {

// }

// void carIdling() {

// }



// void carDriving() {
//     switch ()
//     {
//     case :
        
//         break;
    
//     default:
//         break;
//     }
// }

void carIdling() {

}

void car_braking() {
    frontMotor.stop();
    steerMotor.stop();
}

// void car_accelerating() {
//     frontMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::forward;
//     frontMotor.set_dir(0);
//     frontMotor.run();

//     steerMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::forward;
//     steerMotor.set_dir(1);
//     steerMotor.run();
// }

// void car_reversing() {
//     frontMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::reverse;
//     frontMotor.set_dir(1);
//     frontMotor.run();

//     steerMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::reverse;
//     steerMotor.set_dir(0);
//     steerMotor.run();
// }

// void car_steering_right() {
//     steerMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::forward;
//     steerMotor.set_dir(1);
//     steerMotor.run();
// }

// void car_steering_left() {
//     steerMotor.driveMotorDir = ESP32DcMotorL298N::motorDireciton::reverse;
//     steerMotor.set_dir(0);
//     steerMotor.run();
// }