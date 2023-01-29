cmake_minimum_required(VERSION 3.2)

project(4DRK_ODE CXX)
add_definitions("-Wall -Wextra -std=c++2a")
add_executable(exec main.cpp rk4_solver.cpp)
