#ifndef __BSP_INFRARED__
#define __BSP_INFRARED__
class Infrared5Channel
{
public:
    virtual ~Infrared5Channel() = default;

    enum detectedChannels {
        farLeftChannel,
        halfLeftChannel,
        centralChannel,
        halfRightChannel,
        farRightChannel,
        noChannel
    };
public:
    /**
     * @brief initialize sensor
     * */    
    virtual void init() = 0;
    /**
     * @brief read sensor values
    */
    virtual detectedChannels read() = 0;

private:
};

// Infrared5Channel::Infrared5Channel(/* args */)
// {
// }

// Infrared5Channel::~Infrared5Channel()
// {
// }

#endif
