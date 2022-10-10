cmake_minimum_required(VERSION 3.22)
project(CarRent)

set(CMAKE_CXX_STANDARD 14)

include_directories(Admin)
include_directories(Car)
include_directories(Client)

add_executable(CarRent
        Admin/Admin.cpp
        Admin/Admin.h
        Car/Car.cpp
        Car/Car.h
        Car/ElectricCar.cpp
        Car/ElectricCar.h
        Car/GasCar.cpp
        Car/GasCar.h
        Car/HybridCar.cpp
        Car/HybridCar.h
        Car/OilCar.cpp
        Car/OilCar.h
        Client/Client.cpp
        Client/Client.h
        main.cpp)
