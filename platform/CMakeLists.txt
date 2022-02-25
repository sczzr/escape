cmake_minimum_required(VERSION 3.20)
project(platform C CXX)

set(JS_PORT_FILES
    js-port/js_port.cpp
    js-port/js_port.h)

set(SOURCE_FILES ${JS_PORT_FILES})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
add_library(lib::platform ALIAS ${PROJECT_NAME})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}
)

include_directories(
        ${PROJECT_THIRDPARTY_DIR}/jerryscript/jerry-core/include
        ${PROJECT_THIRDPARTY_DIR}/jerryscript/jerry-ext/include
)