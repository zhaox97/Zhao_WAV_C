cmake_minimum_required(VERSION 3.15)
project(WAV_C C)

set(CMAKE_C_STANDARD 99)

add_executable(WAV_C main.c mywav.c file.h file.c)