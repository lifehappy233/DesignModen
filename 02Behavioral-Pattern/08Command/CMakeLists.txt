CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

PROJECT(command)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src SRC)
include_directories(${PROJECT_SOURCE_DIR}/src/include)
ADD_EXECUTABLE(command ${SRC})
