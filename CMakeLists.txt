# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include(cmake/app.cmake)

if (PLATFORM STREQUAL ESP32)
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    message("ESP32 port selected")
    set(CMAKE_FIND_ROOT_PATH /home/novek/.espressif/tools/xtensa-esp32-elf/esp-12.2.0_20230208/xtensa-esp32-elf)
    set(CMAKE_C_COMPILER /home/novek/.espressif/tools/xtensa-esp32-elf/esp-12.2.0_20230208/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc)
    set(CMAKE_CXX_COMPILER /home/novek/.espressif/tools/xtensa-esp32-elf/esp-12.2.0_20230208/xtensa-esp32-elf/bin/xtensa-esp32-elf-g++)
    set(CMAKE_ASM_COMPILER /home/novek/.espressif/tools/xtensa-esp32-elf/esp-12.2.0_20230208/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc)
    set(EXTRA_COMPONENT_DIRS
            ports/ESP32
    )
    idf_build_component(ports/ESP32)
endif ()

project(RB20)
