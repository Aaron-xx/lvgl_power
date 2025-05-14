cmake_minimum_required(VERSION 3.12.4)

project(lv_power HOMEPAGE_URL https://github.com/lvgl/lv_power)

# Option to define LV_POWER_CONF_INCLUDE_SIMPLE, default: ON
option(LV_POWER_CONF_INCLUDE_SIMPLE "Simple include of \"lv_power_conf.h\"" ON)

# Option to set LV_POWER_CONF_PATH, if set parent path LV_POWER_CONF_DIR is added
# to includes
option(LV_POWER_CONF_PATH "Path defined for lv_power_conf.h")
get_filename_component(LV_POWER_CONF_DIR ${LV_POWER_CONF_PATH} DIRECTORY)

file(GLOB_RECURSE SOURCES src/*.c)
add_library(lv_power STATIC ${SOURCES})
add_library(lvgl::power ALIAS lv_power)

target_include_directories(lv_power SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                                  ${LV_POWER_CONF_DIR})

target_link_libraries(lv_power PUBLIC lvgl)
