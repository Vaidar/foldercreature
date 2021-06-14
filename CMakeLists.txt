cmake_minimum_required(VERSION 3.10)

# set the project name
project(folderecosystem)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Test src/life.cpp src/creature.cpp src/grass.cpp src/grassfield.cpp src/ecosystem.cpp src/living.cpp)