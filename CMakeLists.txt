CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(DesignedPattern)

SET(BIN_PATH ${PROJECT_SOURCE_DIR}/build/bin)
SET(EXECUTABLE_OUTPUT_PATH ${BIN_PATH})

add_subdirectory(01Creational-Pattern/01Factory-Method)
add_subdirectory(01Creational-Pattern/02Abstract-Factory)
add_subdirectory(01Creational-Pattern/03Builder)
