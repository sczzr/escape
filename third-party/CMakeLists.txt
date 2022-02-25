cmake_minimum_required(VERSION 3.20)
project(third-party)

add_subdirectory(jerryscript)

add_library(${PROJECT_NAME} INTERFACE)
add_library(lib::third-party ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} INTERFACE jerry-core jerry-ext jerry-port)