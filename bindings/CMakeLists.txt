cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project("tuatara-python"
    VERSION 0.0.1
    DESCRIPTION "python binding of the tuatara ocr library"
)

find_package(pybind11 CONFIG REQUIRED)
pybind11_add_module(pytuatara python.cpp)

target_link_libraries(pytuatara
    PRIVATE
        tuatara
)