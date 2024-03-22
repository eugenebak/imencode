cmake_minimum_required(VERSION 3.12)
project(imencode_ext)

set(CMAKE_CXX_STANDARD 14)

include_directories(
  /opt/conda/lib/python3.8/site-packages/pybind11/include
)

set(pybind11_DIR "/opt/conda/lib/python3.8/site-packages/pybind11/include")

find_package(OpenCV REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(imencode_ext imencode_wrapper.cpp)

target_link_libraries(imencode_ext PRIVATE ${OpenCV_LIBS})
target_include_directories(imencode_ext PRIVATE ${OpenCV_INCLUDE_DIRS})
