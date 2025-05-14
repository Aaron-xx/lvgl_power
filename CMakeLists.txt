cmake_minimum_required(VERSION 3.10)
project(lvgl)

set(CMAKE_C_STANDARD 11)#C11
set(CMAKE_CXX_STANDARD 17)#C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SDK_ROOT "$ENV{SDKPATH}")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${SDK_ROOT}/sysroots/cortexa7t2hf-neon-vfpv4-ostl-linux-gnueabi/usr/include/libdrm)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
add_subdirectory(lv_power)

add_executable(main
    main.c
)

option(STM32MP_LVGL_DIRECT_DRM_KMS_NOGPU BOOLEAN ON)

if (${STM32MP_LVGL_DIRECT_DRM_KMS_NOGPU})
        target_compile_definitions(lvgl
        PUBLIC
        LV_CONF_INCLUDE_SIMPLE
        STM32MP_LVGL_DIRECT_DRM_KMS_NOGPU
        STM32MP135F-DK
    )
        target_compile_definitions(lv_drivers
        PUBLIC
        LV_CONF_INCLUDE_SIMPLE
        STM32MP_LVGL_DIRECT_DRM_KMS_NOGPU
        STM32MP135F-DK
    )
        target_compile_definitions(lv_power
        PUBLIC
        LV_CONF_INCLUDE_SIMPLE
        STM32MP_LVGL_DIRECT_DRM_KMS_NOGPU
        STM32MP135F-DK
    )
endif()


target_link_libraries(main
    lvgl
    lv_drivers
    lv_power
)
target_link_libraries(main libdrm.so)
target_link_libraries(main libSDL2-2.0.so)

add_custom_target(run COMMAND main DEPENDS main)


