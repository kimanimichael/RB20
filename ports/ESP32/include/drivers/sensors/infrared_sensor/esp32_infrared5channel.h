#include "bsp_infrared5channel.h"
#include "driver/gpio.h"

class ESP32Infrared5Channel : public Infrared5Channel {
public:

    ESP32Infrared5Channel(gpio_num_t farLeft, gpio_num_t closeLeft, gpio_num_t middle, gpio_num_t closeRight, gpio_num_t farRight);

    void init() override;

    detectedChannels read() override;

private:
    gpio_num_t _farLeft,_closeLeft, _middle, _closeRight, _farRight;
};