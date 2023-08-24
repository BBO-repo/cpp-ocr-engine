cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project("tuatara"
    VERSION 0.0.1
    DESCRIPTION "ocr engine"
)

set(BUILD_SHARED_LIBS ON CACHE BOOL "Build Shared Libraries")

add_library(${PROJECT_NAME})
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

target_sources(${PROJECT_NAME}
    PRIVATE
        src/libtuatara/tuatara.cpp
        src/libtuatara/utils.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${OpenCV_INCLUDE_DIRS}
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME} ${TORCH_LIBRARIES} ${OpenCV_LIBS})
