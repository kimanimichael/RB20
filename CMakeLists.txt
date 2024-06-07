# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
set(CMAKE_FIND_ROOT_PATH /home/mrx/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf)
set(CMAKE_C_COMPILER /home/mrx/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32s2-elf-gcc)
set(CMAKE_CXX_COMPILER /home/mrx/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32s2-elf-g++)
set(CMAKE_ASM_COMPILER /home/mrx/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/xtensa-esp32s2-elf-gcc)
project(RB19)
