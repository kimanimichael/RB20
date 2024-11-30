#include "mbed_dc_motor_ft_smc.h"

MbedDCMotor::MbedDCMotor(const PwmOut& motor_signal, BSP::motorDirections direction, BSP::motorSpeeds speed):
    _motor_signal_pin(motor_signal),
    _direction(direction),
    _speed(speed) {
}

void MbedDCMotor::init() {
    // 50Hz frequency
    _pulse_period_us = 20000;
    _motor_signal_pin.period_us(static_cast<int>(_pulse_period_us));

    _clockWiseSpeedMap[BSP::motorSpeeds::ZERO]         = 77;
    _clockWiseSpeedMap[BSP::motorSpeeds::SUPERSLOW]    = 78;
    _clockWiseSpeedMap[BSP::motorSpeeds::LOW]          = 79;
    _clockWiseSpeedMap[BSP::motorSpeeds::INTERMEDIATE] = 80;
    _clockWiseSpeedMap[BSP::motorSpeeds::MEDIUM]       = 93;
    _clockWiseSpeedMap[BSP::motorSpeeds::HIGH]         = 101;

    _counterClockWiseSpeedMap[BSP::motorSpeeds::ZERO]         = 77;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::SUPERSLOW]    = 76;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::LOW]          = 75;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::INTERMEDIATE] = 73;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::MEDIUM]       = 61;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::HIGH]         = 53;

    _motor_signal_pin.write((static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::ZERO)) / 1024.0f));
}

void MbedDCMotor::set_dir(const BSP::motorDirections direction) {
    _direction = direction;
}

void MbedDCMotor::set_speed(const BSP::motorSpeeds speed) {
    _speed = speed;
    switch (_direction) {
        case BSP::motorDirections::CLOCKWISE:

            switch (_speed) {
                case BSP::motorSpeeds::ZERO:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::ZERO)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::SUPERSLOW:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::SUPERSLOW)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::LOW:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::LOW)) / 1024.0f;
                    printf("LOW: PWM duty updated to %.2f\n", _pwmDuty);
                    break;
                case BSP::motorSpeeds::INTERMEDIATE:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::INTERMEDIATE)) / 1024.0f;
                    printf("INTERMEDIATE: PWM duty updated to %.2f\n", _pwmDuty);
                    break;
                case BSP::motorSpeeds::MEDIUM:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::MEDIUM)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::HIGH:
                    _pwmDuty = static_cast<float>(_clockWiseSpeedMap.at(BSP::motorSpeeds::HIGH)) / 1024.0f;
                    break;
                default:
                    printf("BREAKS \n");
                    break;
            }

            break;
        case BSP::motorDirections::COUNTERCLOCKWISE:

            switch (_speed) {
                case BSP::motorSpeeds::ZERO:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::ZERO)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::SUPERSLOW:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::SUPERSLOW)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::LOW:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::LOW)) / 1024.0f;
                    printf("LOW: PWM duty updated to %.2f\n", _pwmDuty);
                    break;
                case BSP::motorSpeeds::INTERMEDIATE:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::INTERMEDIATE)) / 1024.0f;
                    printf("INTERMEDIATE: PWM duty updated to %.2f\n", _pwmDuty);
                    break;
                case BSP::motorSpeeds::MEDIUM:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::MEDIUM)) / 1024.0f;
                    break;
                case BSP::motorSpeeds::HIGH:
                    _pwmDuty = static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::HIGH)) / 1024.0f;
                    break;
                default:
                    printf("BREAKS \n");
                    break;
            }

            break;
        default:
            break;
    }
    printf("Motor speed set to %.2f\n", _pwmDuty);
}

#define MAX_CW_PWM_VALUE 88000
#define MIN_CW_PWM_VALUE 80000

#define MAX_CCW_PWM_VALUE 77
#define MIN_CCW_PWM_VALUE 73

float MbedDCMotor::validate_motor_speed(unsigned int speed) {
    float validatedSpeed;
    switch (_direction)
    {
        case BSP::motorDirections::CLOCKWISE:
            /* code */
                if(speed > MAX_CW_PWM_VALUE) {
                    validatedSpeed = MAX_CW_PWM_VALUE;
                    return validatedSpeed;
                }
                else if (speed < MIN_CW_PWM_VALUE) {
                    validatedSpeed = MIN_CW_PWM_VALUE;
                    return validatedSpeed;
                }
                else {
                    validatedSpeed = static_cast<float>(speed);
                    return validatedSpeed;
                }
        break;
        case BSP::motorDirections::COUNTERCLOCKWISE:
            /* code */
                if(speed > MAX_CCW_PWM_VALUE) {
                    validatedSpeed = MAX_CCW_PWM_VALUE;
                    return validatedSpeed;
                }
                else if (speed < MIN_CCW_PWM_VALUE) {
                    validatedSpeed = MIN_CCW_PWM_VALUE;
                    return validatedSpeed;
                }
                else {
                    validatedSpeed = static_cast<float>(speed);
                    return validatedSpeed;
                }
        break;

        default:
            validatedSpeed = 0;
        return validatedSpeed/1048576.0f;
        break;
    }
}

void MbedDCMotor::set_raw_speed(unsigned int speed) {
    _pwmDuty = validate_motor_speed(speed);
    //    printf("Motor speed set to %u\n", _pwmDuty);
}

void MbedDCMotor::run() {
    _motor_signal_pin.write(_pwmDuty);
}

void MbedDCMotor::stop() {
    _motor_signal_pin.write(static_cast<float>(_counterClockWiseSpeedMap.at(BSP::motorSpeeds::ZERO)) / 1024.0f);
}
