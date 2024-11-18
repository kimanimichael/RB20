# RB20
This repository holds the vehicle software for a self-driving car.

## Prerequisites
The following are required to build this project:
1. [CMake](https://cmake.org/download/)
2. [Python](https://www.python.org/downloads/)
3. [Ninja](https://github.com/ninja-build/ninja)

## Build
The following platforms are supported for this project:
1. ESP-IDF
2. Mbed OS


### ESP-IDF platform prerequisites
This platform implements all the BSP requirements for various ports that use ESP-IDF.
#### ESP-IDF installation requirements
* [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/index.html)(version 5.2.3)

### Mbed-OS platform prerequisites
This platform implements all the BSP requirements for various ports that use Mbed OS.
#### Mbed OS installation requirements
* [Mbed OS](https://os.mbed.com/docs/mbed-os/v6.16/build-tools/install-and-set-up.html)(version 6.15.1)
* [GNU Arm Embedded Toolchain](https://developer.arm.com/downloads/-/gnu-rm)(version 10.3-2021.10 )

The following ports are supported:
1. ESP32
2. STM32G070

### ESP32
Using ESP-IDF
#### Build
For the first time, at the root of the project, run:

``
chmod +x ./build_cmake_esp32.sh
``

``
. $HOME/esp/esp-idf/export.sh
``

``
./build_cmake_esp32.sh
``

For successive builds in a new terminal, run:

``
. $HOME/esp/esp-idf/export.sh
``

``
./build_cmake_esp32.sh
``

For successive builds in the same terminal instance, run:

``
./build_cmake_esp32.sh
``
#### Flashing instructions
Connect the ESP32 to your computer and run:

``
ninja -C cmake_build/ESP32/ flash
``

### STM32G070
Using Mbed OS
#### Build instructions
For the first time, at the root of the project, run:

``
chmod +x ./build_cmake_g070.sh
``

``
./build_cmake_g070.sh
``

For successive builds, run:

``
./build_cmake_g070.sh
``

#### Flashing requirements
1. [stlink](https://github.com/stlink-org/stlink)(version 1.6.0)
#### Flashing instructions
Connect the STM32G070 to your computer and run:

``
st-flash write cmake_build/STM32G070X/RB20.bin 0x8000000
``

## Documentation
The documentation will be found [here](https://example.com/)


