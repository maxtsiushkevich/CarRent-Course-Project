cmake_minimum_required(VERSION 3.22)
project(CarRent)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

include_directories(Admin)
include_directories(Car)
include_directories(Client)
include_directories(Interface)

add_executable(CarRent
        Car/Car.cpp
        Car/Car.h
        Car/ElectricCar.cpp
        Car/ElectricCar.h
        Car/HybridCar.cpp
        Car/HybridCar.h
        Car/OilCar.cpp
        Car/OilCar.h
        Interface/Interface.cpp
        Interface/Interface.h
        main.cpp Persons/Person.cpp Persons/Person.h Persons/User.cpp Persons/User.h Persons/Admin.cpp Persons/Admin.h Interface/Interface.cpp Interface/Interface.h Car/PetrolCar.cpp Car/PetrolCar.h Car/DieselCar.cpp Car/DieselCar.h Car/CarBrands.h DataBase/Database.cpp DataBase/Database.h ID/IdGenerator.cpp ID/IdGenerator.h Persons/Userdata.cpp Persons/Userdata.h Exeption/Exeption.cpp Exeption/Exeption.h)
