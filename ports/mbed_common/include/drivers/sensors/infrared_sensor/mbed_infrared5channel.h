#ifndef MBED_INFRARED5CHANNEL_H
#define MBED_INFRARED5CHANNEL_H

#include "bsp_infrared5channel.h"
#include "mbed.h"

class MbedInfrared5Channel :public Infrared5Channel {
public:
    MbedInfrared5Channel(const DigitalIn& farLeft, const DigitalIn& closeLeft, const DigitalIn& middle, const DigitalIn& closeRight, const DigitalIn& farRight);
    /**
     * @brief initialize sensor
     * */
    void init() override;
    /**
     * @brief read sensor values
    */
    detectedChannels read() override;
private:
    DigitalIn _farLeft;
    DigitalIn _closeLeft;
    DigitalIn _middle;
    DigitalIn _closeRight;
    DigitalIn _farRight;

};

#endif