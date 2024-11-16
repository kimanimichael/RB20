cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

set(MBED_PATH ${CMAKE_CURRENT_LIST_DIR}/../../mbed_common/mbed-os CACHE INTERNAL "")
set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")

SET(CMAKE_COLOR_MAKEFILE ON)
add_compile_options(-fdiagnostics-color=always)

include(${MBED_PATH}/tools/cmake/app.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/../../../cmake/app.cmake)
add_subdirectory(${MBED_PATH})
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/STM32G070KB)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../../mbed_common ${CMAKE_CURRENT_BINARY_DIR}/canister-mbed-common)

add_executable(${APP_TARGET})
mbed_configure_app_target(${APP_TARGET})

target_link_libraries(${APP_TARGET}
        rb20-mbed-common
)

target_include_directories(${APP_TARGET}
        PRIVATE
        ${APP_COMMON_INCLUDE_DIRS}
)

target_sources(${APP_TARGET}
        PRIVATE
        ${APP_COMMON_SOURCES}
)

mbed_set_post_build(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")

if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()



