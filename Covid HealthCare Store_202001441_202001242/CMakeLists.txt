cmake_minimum_required(VERSION 3.19)
project(Covid_HealthCare_Store)

set(CMAKE_CXX_STANDARD 14)

add_executable(Covid_HealthCare_Store main.cpp customer.cpp customer.h vaccine.cpp vaccine.h record.cpp record.h Queue.cpp Queue.h)