#include "esp32_infrared5channel.h"
#include <stdio.h>

ESP32Infrared5Channel::ESP32Infrared5Channel(gpio_num_t farLeft, gpio_num_t closeLeft, gpio_num_t middle, gpio_num_t closeRight, gpio_num_t farRight) 
:_farLeft(farLeft), _closeLeft(closeLeft), _middle(middle), _closeRight(closeRight), _farRight(farRight)
{

}

void ESP32Infrared5Channel::init() {
    gpio_set_direction(_farLeft, GPIO_MODE_INPUT);
    gpio_set_direction(_closeLeft, GPIO_MODE_INPUT);
    gpio_set_direction(_middle, GPIO_MODE_INPUT);
    gpio_set_direction(_closeRight, GPIO_MODE_INPUT);
    gpio_set_direction(_farRight, GPIO_MODE_INPUT);

}

enum pinLineDetection {
    detected,
    notDetected
};

ESP32Infrared5Channel::detectedChannels _detectedChannel;
ESP32Infrared5Channel::detectedChannels ESP32Infrared5Channel::read() {
    _detectedChannel = ESP32Infrared5Channel::detectedChannels::noChannel;
    if (gpio_get_level(_farLeft) == detected) {
        printf("Detected: far left\n");
        _detectedChannel =  ESP32Infrared5Channel::detectedChannels::farLeftChannel;
    }
    if (gpio_get_level(_closeLeft) == detected) {
        printf("Detected: close left\n");
        _detectedChannel = ESP32Infrared5Channel::detectedChannels::halfLeftChannel;
    }
    if (gpio_get_level(_middle) == detected) {
        printf("Detected: Middle\n");
        _detectedChannel = ESP32Infrared5Channel::detectedChannels::centralChannel;
    }
    if (gpio_get_level(_closeRight) == detected) {
        printf("Detected: close right\n");
        _detectedChannel = ESP32Infrared5Channel::detectedChannels::halfRightChannel;
    }
    if ((gpio_get_level(_farRight) == detected)) {
        printf("Detected: far right\n");
        _detectedChannel = ESP32Infrared5Channel::detectedChannels::farRightChannel;
    }
    return _detectedChannel;
}