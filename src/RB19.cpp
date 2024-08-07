#include <stdio.h>
#include "bsp.h"
#include "car.h"
#include "car_line_following_pid.h"
#include "kinematics_pid.h"
#include "steering.h"
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h>

#ifdef ESP32
extern "C" void app_main(void)
#else
int main()
#endif
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
    BSP::BSP_Delay(20000);
    BSP::BSPInit();
    carAppInit();
    // steerCar();
    controlCarKinematics();
    double carPIDOutput;
    while(1) {
        carAppRun();
        // steerCar();

        carPIDOutput = controlCarKinematics();
        printf("PID Output: %.2f\n", carPIDOutput);
        BSP::BSP_Delay(100);
        // vTaskDelay(500/portTICK_PERIOD_MS);
    }
}

// void test_gpio_function()
// {
//     #define TEST_GPIO GPIO_NUM_23
//     gpio_set_direction(TEST_GPIO, GPIO_MODE_INPUT);
//     printf("GPIO level is %d \n", gpio_get_level(TEST_GPIO));
//     vTaskDelay(900/portTICK_PERIOD_MS);
// }