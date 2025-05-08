#ifndef __BSP_DCMOTOR__
#define __BSP_DCMOTOR__

#include <stdio.h>

namespace BSP{

enum motorDirections {
    CLOCKWISE,
    COUNTERCLOCKWISE
};

enum motorSpeeds {
    ZERO,
    SUPERSLOW,
    LOW,
    INTERMEDIATE,
    MEDIUM,
    HIGH
};

class DcMotor {
private:

public:
 virtual ~DcMotor() = default;

public:
    /**
     * @brief Initialize motor pins and operations
    */
    virtual void init () = 0;

    /**
     * @brief Set motor direction
     * @author @MK
    */
    virtual void set_dir(BSP::motorDirections powerUnitDir) = 0;

    /**
     * @brief Run the dc motor
     * @author @MK
    */
    virtual void run() = 0;

    /**
     * @brief Stop motor
     * @author @MK
    */
    virtual void stop() = 0;

    /**
     * @brief Set motor speed
     * @author @MK
    */
    virtual void set_speed(BSP::motorSpeeds speed) = 0;

    /**
     * @brief Sets a motor's raw speed
    */
    virtual void set_raw_speed(unsigned int speed) = 0;
};

}
#endif