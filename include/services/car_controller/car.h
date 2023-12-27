#ifndef __CAR__H
#define __CAR__H

// enum carStates{
//     idle,
//     braking,
//     accelerating,
//     reversing
// };

// extern carStates RB19;

enum carDriveStates{
    carIdle,
    driving
};

// extern carDriveStates RB19Drive;

// enum carSteerStates{
//     idling,
//     left,
//     right,
// };

// extern carSteerStates RB19Steer;


/**
 * @brief Switch on the front car lights
*/
void front_lights_on();

/**
 * @brief Switch off the front car lights
*/
void front_lights_off();


/**
 * @brief car in idle state
*/
void carIdling();

/**
 * @brief car in driving state
*/
void carDriving();

/**
 * @brief car braking
*/
void car_braking();

/**
 * @brief car accelerating
*/
void car_accelerating();

/**
 * @brief car reversing
*/
void car_reversing();

/**
 * @brief car steering left
*/
void car_steering_left();

/**
 * @brief car steering right
*/
void car_steering_right();

#endif
