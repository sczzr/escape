cmake_minimum_required(VERSION 3.20)
project(example)

include_directories(${PROJECT_SOURCE_DIR}/platform)

set(SOURCE_FILE main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})

target_link_libraries(
        ${PROJECT_NAME}
        lib::platform
        lib::third-party
)