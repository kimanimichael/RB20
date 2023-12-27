#ifndef __STEERING__
#define __STEERING__

#include "bsp.h"

enum carSteerStates{
    steerIdling,
    left,
    right,
};


/**
 * @brief Initializes and carries out car steering
*/
void steerCar();

#endif