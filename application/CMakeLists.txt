cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project("ocrize"
    VERSION 0.0.1
    DESCRIPTION "Example application consuming the tuatara ocr library"
)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ocrize.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tuatara)
