cmake_minimum_required(VERSION 3.6)

project(individuals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(PROJECT_SOURCES Covid19State.hpp  Person.hpp PersonProperty.hpp Population.hpp Rng.hpp)

add_executable(sim sim.cpp ${PROJECT_SOURCES})

target_include_directories(sim PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}"
                          )
