cmake_minimum_required(VERSION 3.23)
project(Projekt_Aizo)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

add_executable(Projekt_Aizo main.cpp shellSort.h quickSort.h insertionSort.h heapSort.h Menu.h dataGenerator.h currentArray.h)
