CMAKE_MINIMUM_REQUIRED(VERSION 3.20)
SET(CMAKE_CXX_STANDARD 17)
SET(EXECUTABLE_OUTPUT_PATH bin)

PROJECT(abstractFactory)
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src abstract_factory_src)
include_directories(${PROJECT_SOURCE_DIR}/src/include)
ADD_EXECUTABLE(main ${abstract_factory_src})