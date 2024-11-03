cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

idf_component_register(
        INCLUDE_DIRS
        ${APP_COMMON_INCLUDE_DIRS}
        "."
        "./include"
        "./include/drivers"
        "./include/drivers/actuators"
        "./include/drivers/actuators/dc_motor"
        "./include/drivers/sensors"
        "./include/drivers/sensors/infrared_sensor"

        SRCS
        ${APP_COMMON_SOURCES}
        "src/esp32_bsp.cpp"
        "src/drivers/actuators/dc_motor/esp32_dc_motor_ft_smc.cpp"
        "src/drivers/actuators/dc_motor/esp32_dc_motor_l298n.cpp"
        "src/drivers/sensors/infrared_sensor/esp32_infrared5channel.cpp"
        "src/services/car.cpp"
        REQUIRES
        "driver"
)