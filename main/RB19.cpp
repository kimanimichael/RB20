#include <stdio.h>
#include "bsp.h"
#include "car.h"
#include "car_line_following.h"
#include "kinematics.h"
#include "steering.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
// #include "driver/gpio.h"


extern "C" void app_main(void)
{
    // front_lights_on();
    /* Put in it's own thread*/
    // handleInputs();
    /* Put in it's own thread*/
    // driveCar();
    /* Put in it's own thread*/
    // steerCar();
    // while(1) {
    //     steerCar();
    //     controlCarKinematics();
    // }
    BSP::BSPInit();
    carAppInit();
    // steerCar();
    controlCarKinematics();
    while(1) {
        carAppRun();
        // steerCar();
        controlCarKinematics();
        vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

// void test_gpio_function()
// {
//     #define TEST_GPIO GPIO_NUM_23
//     gpio_set_direction(TEST_GPIO, GPIO_MODE_INPUT);
//     printf("GPIO level is %d \n", gpio_get_level(TEST_GPIO));
//     vTaskDelay(900/portTICK_PERIOD_MS);
// }