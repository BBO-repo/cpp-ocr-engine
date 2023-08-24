cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project("ocr-engine"
    VERSION 0.0.1
    DESCRIPTION "ocr engine"
)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
list(APPEND CMAKE_PREFIX_PATH ${PARENT_DIR}/thirdparty/libtorch)
find_package(Torch REQUIRED)
find_package(OpenCV 4 REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(libtuatara)
add_subdirectory(application)
add_subdirectory(bindings)