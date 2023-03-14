cmake_minimum_required(VERSION 3.21.1)
project(CPP3_SmartCalc_v2_0_0)

set(CMAKE_CXX_STANDARD 17)

#set(SOURCE ./view/data/data_plot.cc)
#
#set(HEADER ./view/data/data_plot.h)

add_executable(CPP3_SmartCalc_v2_0_0 main.cpp exampleModel.cpp exampleController.cpp consoleView.cpp)