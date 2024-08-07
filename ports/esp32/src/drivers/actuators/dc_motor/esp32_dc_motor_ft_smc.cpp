#include "esp32_dc_motor_ft_smc.h"
#include "stdio.h"

ESP32DCMotorFtSmc::ESP32DCMotorFtSmc(gpio_num_t signal, BSP::motorDirections direction, BSP::motorSpeeds speed, ledc_channel_t motorChannel)
    :_signal(signal), _direction(direction), _speed(speed), _motorChannel(motorChannel)
    {
        
    }
void ESP32DCMotorFtSmc::init() {
    gpio_set_direction(_signal, GPIO_MODE_OUTPUT);
    configure_pwm(_signal);

    _clockWiseSpeedMap[BSP::motorSpeeds::ZERO] = 77;
    _clockWiseSpeedMap[BSP::motorSpeeds::SUPERSLOW] = 78;
    _clockWiseSpeedMap[BSP::motorSpeeds::LOW] = 79;
    _clockWiseSpeedMap[BSP::motorSpeeds::INTERMEDIATE] = 81;
    _clockWiseSpeedMap[BSP::motorSpeeds::MEDIUM] = 93;
    _clockWiseSpeedMap[BSP::motorSpeeds::HIGH] = 101;

    _counterClockWiseSpeedMap[BSP::motorSpeeds::ZERO] = 77;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::SUPERSLOW] = 76;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::LOW] = 75;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::INTERMEDIATE] = 73;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::MEDIUM] = 61;
    _counterClockWiseSpeedMap[BSP::motorSpeeds::HIGH] = 53;

    _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::ZERO);
}

void ESP32DCMotorFtSmc::configure_pwm(gpio_num_t signal) {
    ledc_timer_config_t pwmTimer = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_20_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = 50,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&pwmTimer);

    ledc_channel_config_t pwmChannel = {
        .gpio_num = signal,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = _motorChannel,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER_0,
        .duty = _pwmDuty
    };
    ledc_channel_config(&pwmChannel);
}

void ESP32DCMotorFtSmc::set_dir(BSP::motorDirections direction) {
    _direction = direction;
}

void ESP32DCMotorFtSmc::set_speed(BSP::motorSpeeds speed) {
    _speed = speed;
    switch (_direction)
    {
    case BSP::motorDirections::CLOCKWISE:

        switch (_speed)
        {
        case BSP::motorSpeeds::ZERO:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::ZERO);
            break;
        case BSP::motorSpeeds::SUPERSLOW:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::SUPERSLOW);
            break;
        case BSP::motorSpeeds::LOW:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::LOW);
            printf("LOW: PWM duty updated to %u\n", _pwmDuty);
            break;
        case BSP::motorSpeeds::INTERMEDIATE:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::INTERMEDIATE);
            printf("INTERMEDIATE: PWM duty updated to %u\n", _pwmDuty);
            break;
        case BSP::motorSpeeds::MEDIUM:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::MEDIUM);
            break;
        case BSP::motorSpeeds::HIGH:
            _pwmDuty = _clockWiseSpeedMap.at(BSP::motorSpeeds::HIGH);
            break;
        default:
            printf("BREAKS \n");
            break;
        }
        
        break;
    case BSP::motorDirections::COUNTERCLOCKWISE:

        switch (_speed)
        {
        case BSP::motorSpeeds::ZERO:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::ZERO);
            break;
        case BSP::motorSpeeds::SUPERSLOW:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::SUPERSLOW);
            break;
        case BSP::motorSpeeds::LOW:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::LOW);
            break;
        case BSP::motorSpeeds::INTERMEDIATE:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::INTERMEDIATE);
            break;
        case BSP::motorSpeeds::MEDIUM:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::MEDIUM);
            break;
        case BSP::motorSpeeds::HIGH:
            _pwmDuty = _counterClockWiseSpeedMap.at(BSP::motorSpeeds::HIGH);
            break;
        default:
            break;
        }

        break;
    default:
        break;
    }
    ledc_set_duty(LEDC_LOW_SPEED_MODE, _motorChannel, _pwmDuty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, _motorChannel);
    printf("Motor speed set to %u\n", _pwmDuty);
}

void ESP32DCMotorFtSmc::set_raw_speed(unsigned int speed) {
    _pwmDuty = validate_motor_speed(speed);
    ledc_set_duty(LEDC_LOW_SPEED_MODE, _motorChannel, _pwmDuty);
    ledc_update_duty(LEDC_LOW_SPEED_MODE, _motorChannel);
//    printf("Motor speed set to %u\n", _pwmDuty);
}
#define MAX_CW_PWM_VALUE 88000
#define MIN_CW_PWM_VALUE 80000

#define MAX_CCW_PWM_VALUE 77
#define MIN_CCW_PWM_VALUE 73

unsigned int ESP32DCMotorFtSmc::validate_motor_speed(unsigned int speed) {
    unsigned int validatedSpeed;
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
            validatedSpeed = speed;
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
            validatedSpeed = speed;
            return validatedSpeed;
        }
        break;
    
    default:
        validatedSpeed = 0; 
        return validatedSpeed;
        break;
    }
}

void ESP32DCMotorFtSmc::run() {
    
}

void ESP32DCMotorFtSmc::stop() {
    ledc_set_duty(LEDC_LOW_SPEED_MODE, _motorChannel, _clockWiseSpeedMap.at(BSP::motorSpeeds::ZERO));
    ledc_update_duty(LEDC_LOW_SPEED_MODE, _motorChannel);
}