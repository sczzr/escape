cmake_minimum_required(VERSION 3.20)
project(space)

set(CMAKE_CXX_STANDARD 11)

set(DIVISIBLE_INSTALL_INC_DIR ${PROJECT_SOURCE_DIR}/inc)
set(DIVISIBLE_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(DIVISIBLE_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(PROJECT_THIRDPARTY_DIR ${PROJECT_SOURCE_DIR}/third-party)
set(PROJECT_PLATFORM ${PROJECT_SOURCE_DIR}/platform)

include_directories(${DIVISIBLE_INSTALL_INC_DIR})

add_subdirectory(third-party)
add_subdirectory(platform)
add_subdirectory(example)
