mbed-tools configure -m NUCLEO_G071RB -t GCC_ARM -o cmake_build/STM32G070X/ --mbed-os-path ports/mbed_common/mbed-os --app-config ports/STM32G070X/mbed/mbed_app.json
cmake -S .  -B cmake_build/STM32G070X/ -G Ninja -DPLATFORM=STM32G070X
cmake --build cmake_build/STM32G070X
