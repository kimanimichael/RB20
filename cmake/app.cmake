cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(APP_COMMON_INCLUDE_DIRS
        "${CMAKE_SOURCE_DIR}/include"

        "${CMAKE_SOURCE_DIR}/include/bsp"
        "${CMAKE_SOURCE_DIR}/include/bsp/drivers/"
        "${CMAKE_SOURCE_DIR}/include/bsp/drivers/actuators"
        "${CMAKE_SOURCE_DIR}/include/bsp/drivers/sensors"

        "${CMAKE_SOURCE_DIR}/include/math_utils/pid"

        "${CMAKE_SOURCE_DIR}/include/apps/car_app"

        "${CMAKE_SOURCE_DIR}/include/services/kinematics"
        "${CMAKE_SOURCE_DIR}/include/services/steering"
        "${CMAKE_SOURCE_DIR}/include/services/car_controller"
)

set(APP_COMMON_SOURCES
        "${CMAKE_SOURCE_DIR}/src/RB19.cpp"
        "${CMAKE_SOURCE_DIR}/src/math_utils/pid/pid.cpp"
#        "${CMAKE_SOURCE_DIR}/src/apps/car_app/car_line_following.cpp"
        "${CMAKE_SOURCE_DIR}/src/apps/car_app/car_line_following_pid.cpp"
#        "${CMAKE_SOURCE_DIR}/src/services/kinematics.cpp"
        "${CMAKE_SOURCE_DIR}/src/services/kinematics_pid.cpp"
        "${CMAKE_SOURCE_DIR}/src/services/steering.cpp"
)
