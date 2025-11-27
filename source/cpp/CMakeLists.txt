# Modified by Vicente Lopez (voliva@uji.es). Modifications will be marked with @romOlivo.

cmake_minimum_required(VERSION 3.10)

project(cTDD)

# @romOlivo: Download Catch2 for testing
include(FetchContent)
FetchContent_Declare(
    catch2
    URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.5.3.zip
)
FetchContent_MakeAvailable(catch2)

set(CMAKE_CXX_STANDARD 20)
set(PYBIND11_PYTHON_VERSION 3.8)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")

find_package(pybind11 REQUIRED)
find_package(Eigen3 REQUIRED)

pybind11_add_module(${PROJECT_NAME} cTDD.cpp)

target_compile_definitions(${PROJECT_NAME} PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
target_include_directories(${PROJECT_NAME} PRIVATE ${PYBIND11_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)

# @romOlivo Added the test as executables
add_executable(tests
    testComplex.cpp
)

# @romOlivo Link Catch2
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# @romOlivo Discover test automatically
enable_testing()
include(Catch)
catch_discover_tests(tests)


# add the executable
# add_executable(${PROJECT_NAME} main.cpp)
# target_include_directories( ${PROJECT_NAME} PRIVATE)
# target_link_libraries(${PROJECT_NAME} PRIVATE Eigen3::Eigen)
