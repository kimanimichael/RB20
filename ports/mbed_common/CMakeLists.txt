cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

add_library(rb20-mbed-common INTERFACE)

target_include_directories(rb20-mbed-common INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/actuators
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/actuators/dc_motor
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/sensors
        ${CMAKE_CURRENT_SOURCE_DIR}/include/drivers/sensors/infrared_sensor
)

target_sources(rb20-mbed-common INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/mbed_bsp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/actuators/dc_motor/mbed_dc_motor_ft_smc.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/drivers/sensors/infrared_sensor/mbed_infrared5channel.cpp
)