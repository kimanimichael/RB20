

add_library(mbed-stm32g070kb INTERFACE)

# set(TARGET_STMG070xB_PATH ${MBED_PATH}/targets/TARGET_STM/TARGET_STM32G0/TARGET_STM32G070xB)

# if(${MBED_TOOLCHAIN} STREQUAL "GCC_ARM")
#         set(STARTUP_FILE ${TARGET_STMG070xB_PATH}/TOOLCHAIN_GCC_ARM/startup_stm32g070xx.S CACHE INTERNAL "")
#         set(LINKER_FILE TOOLCHAIN_GCC_ARM/stm32g070xb.ld CACHE INTERNAL "")
# endif()

target_sources(mbed-stm32g070kb
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/PeripheralPins.c
        ${CMAKE_CURRENT_LIST_DIR}/system_clock.c
        # ${STARTUP_FILE}
)

target_include_directories(mbed-stm32g070kb
        INTERFACE
        ./
        # ${MBED_PATH}/targets/TARGET_STM/TARGET_STM32G0/TARGET_STM32G070xB
        ${CMAKE_CURRENT_LIST_DIR}/.

)

# mbed_set_linker_script(mbed-stm32g070kb ${CMAKE_CURRENT_SOURCE_DIR}/${LINKER_FILE})

target_link_libraries(mbed-stm32g070kb INTERFACE  mbed-stm32g070xb)
