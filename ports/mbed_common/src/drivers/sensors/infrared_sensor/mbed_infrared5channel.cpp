#include "mbed_infrared5channel.h"

MbedInfrared5Channel::MbedInfrared5Channel(const DigitalIn& farLeft, const DigitalIn& closeLeft,
                                           const DigitalIn& middle,
                                           const DigitalIn& closeRight, const DigitalIn& farRight):
    _farLeft(farLeft), _closeLeft(closeLeft), _middle(middle), _closeRight(closeRight), _farRight(farRight) {
}

void MbedInfrared5Channel::init() {

}

enum pinLineDetection {
    detected,
    notDetected
};

MbedInfrared5Channel::detectedChannels detectedChannel;
Infrared5Channel::detectedChannels MbedInfrared5Channel::read() {
    detectedChannel = MbedInfrared5Channel::detectedChannels::noChannel;
    if (_farLeft.read() == detected) {
        printf("Detected: far left\n");
        detectedChannel =  MbedInfrared5Channel::detectedChannels::farLeftChannel;
    }
    if (_closeLeft.read() == detected) {
        printf("Detected: close left\n");
        detectedChannel = MbedInfrared5Channel::detectedChannels::halfLeftChannel;
    }
    if (_middle.read() == detected) {
        printf("Detected: Middle\n");
        detectedChannel = MbedInfrared5Channel::detectedChannels::centralChannel;
    }
    if (_closeRight.read() == detected) {
        printf("Detected: close right\n");
        detectedChannel = MbedInfrared5Channel::detectedChannels::halfRightChannel;
    }
    if ((_farRight.read() == detected)) {
        printf("Detected: far right\n");
        detectedChannel = MbedInfrared5Channel::detectedChannels::farRightChannel;
    }
    return detectedChannel;
}
