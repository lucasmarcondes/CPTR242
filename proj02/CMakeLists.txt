cmake_minimum_required(VERSION 3.10)
project(proj02)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(proj02
        applicant.cpp
        applicant.h
        priority_list.cpp
        priority_list.h
        QueType.cpp
        QueType.h
        test_driver.cpp
        test_driver.h
        main.cpp)
