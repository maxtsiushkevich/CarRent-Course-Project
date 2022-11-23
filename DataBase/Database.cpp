#include "Database.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

void Database :: AddInDatabase(DieselCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;
    data.interior.color = obj.interior.color;
    data.interior.material = obj.interior.material;
    data.color = obj.color;
    data.costPerDay = obj.costPerDay;
    data.costPerWeek = obj.costPerWeek;
    data.costPerMonth = obj.costPerMonth;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;

    ofstream file;
    file.open("../Files/DieselCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(vector<DieselCar>&dieselCars)
{
    DieselCar obj(0);
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;

    ifstream file;
    file.open("../Files/DieselCars.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&data, sizeof(data)))
    {
        obj.deleteMark = data.deleteMark;

        if (obj.deleteMark == true) // если объект считается удаленным, то пропускается
            continue;

        obj.id = data.id;
        obj.brand = data.brand;
        obj.model = data.model;
        obj.country = data.country;
        obj.bodyType = data.bodyType;
        obj.manufacturedYear = data.manufacturedYear;
        obj.transmissionType = data.transmissionType;
        obj.numberOfSeats = data.numberOfSeats;
        obj.odometer = data.odometer;
        obj.horsepower = data.horsepower;
        obj.maxSpeed = data.maxSpeed;
        obj.to100 = data.to100;
        obj.consumption = data.consumption;
        obj.volume = data.volume ;
        obj.interior.color = data.interior.color;
        obj.interior.material = data.interior.material;
        obj.color = data.color;
        obj.costPerDay = data.costPerDay;
        obj.costPerWeek = data.costPerWeek;
        obj.costPerMonth = data.costPerMonth;
        obj.cruiseControl = data.cruiseControl;
        obj.parkingAssist = data.parkingAssist;
        obj.music = data.music;
        obj.bluetooth = data.bluetooth;
        obj.climat = data.climat;
        obj.seatHeating = data.seatHeating;
        obj.gps = data.gps;
        obj.sunroof = data.sunroof;

        dieselCars.emplace_back(obj);
    }
    file.close();

}

void Database :: AddInDatabase(PetrolCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int petrolType;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;
    data.interior.color = obj.interior.color;
    data.interior.material = obj.interior.material;
    data.color = obj.color;
    data.costPerDay = obj.costPerDay;
    data.costPerWeek = obj.costPerWeek;
    data.costPerMonth = obj.costPerMonth;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;
    data.petrolType = obj.petrolType;

    ofstream file;
    file.open("../Files/PetrolCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
//void Database :: GetFromDatabase(PetrolCar &obj)
//{
//    struct Data
//    {
//        int id;
//        bool deleteMark;
//        string brand, model, country, bodyType;
//        int manufacturedYear;
//        string transmissionType;
//        int numberOfSeats;
//        int odometer;
//        int horsepower;
//        float maxSpeed;
//        float to100;
//        float consumption;
//        float volume;
//        struct interior
//        {
//            string color, material;
//        } interior;
//        string color;
//        int costPerDay, costPerWeek, costPerMonth;
//        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
//        int petrolType;
//    } data;
//
//    ifstream file;
//    file.open("../Files/PetrolCars.bin", ios::binary);
//    if (!file.is_open())
//        cout << "Error";
//    file.read((char*)&data, sizeof(data));
//    file.close();
//
//    obj.id = data.id;
//    obj.deleteMark = data.deleteMark;
//    obj.brand = data.brand;
//    obj.model = data.model;
//    obj.country = data.country;
//    obj.bodyType = data.bodyType;
//    obj.manufacturedYear = data.manufacturedYear;
//    obj.transmissionType = data.transmissionType;
//    obj.numberOfSeats = data.numberOfSeats;
//    obj.odometer = data.odometer;
//    obj.horsepower = data.horsepower;
//    obj.maxSpeed = data.maxSpeed;
//    obj.to100 = data.to100;
//    obj.consumption = data.consumption;
//    obj.volume = data.volume;
//    obj.interior.color = data.interior.color;
//    obj.interior.material = data.interior.material;
//    obj.color = data.color;
//    obj.costPerDay = data.costPerDay;
//    obj.costPerWeek = data.costPerWeek;
//    obj.costPerMonth = data.costPerMonth;
//    obj.cruiseControl = data.cruiseControl;
//    obj.parkingAssist = data.parkingAssist;
//    obj.music = data.music;
//    obj.bluetooth = data.bluetooth;
//    obj.climat = data.climat;
//    obj.seatHeating = data.seatHeating;
//    obj.gps = data.gps;
//    obj.sunroof = data.sunroof;
//    obj.petrolType = data.petrolType;
//}

void Database :: AddInDatabase(ElectricCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.interior.color = obj.interior.color;
    data.interior.material = obj.interior.material;
    data.color = obj.color;
    data.costPerDay = obj.costPerDay;
    data.costPerWeek = obj.costPerWeek;
    data.costPerMonth = obj.costPerMonth;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;
    data.batteryCapacity = obj.batteryCapacity;

    ofstream file;
    file.open("../Files/ElectricCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
//void Database :: GetFromDatabase(ElectricCar &obj)
//{
//    struct Data
//    {
//        int id;
//        bool deleteMark;
//        string brand, model, country, bodyType;
//        int manufacturedYear;
//        string transmissionType;
//        int numberOfSeats;
//        int odometer;
//        int horsepower;
//        float maxSpeed;
//        float to100;
//        struct interior
//        {
//            string color, material;
//        } interior;
//        string color;
//        int costPerDay, costPerWeek, costPerMonth;
//        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
//        int batteryCapacity;
//    } data;
//
//    ifstream file;
//    file.open("../Files/ElectricCars.bin", ios::binary);
//    if (!file.is_open())
//        cout << "Error";
//    file.read((char*)&data, sizeof(data));
//    file.close();
//
//    obj.id = data.id;
//    obj.deleteMark = data.deleteMark;
//    obj.brand = data.brand;
//    obj.model = data.model;
//    obj.country = data.country;
//    obj.bodyType = data.bodyType;
//    obj.manufacturedYear = data.manufacturedYear;
//    obj.transmissionType = data.transmissionType;
//    obj.numberOfSeats = data.numberOfSeats;
//    obj.odometer = data.odometer;
//    obj.horsepower = data.horsepower;
//    obj.maxSpeed = data.maxSpeed;
//    obj.to100 = data.to100;
//    obj.interior.color = data.interior.color;
//    obj.interior.material = data.interior.material;
//    obj.color = data.color;
//    obj.costPerDay = data.costPerDay;
//    obj.costPerWeek = data.costPerWeek;
//    obj.costPerMonth = data.costPerMonth;
//    obj.cruiseControl = data.cruiseControl;
//    obj.parkingAssist = data.parkingAssist;
//    obj.music = data.music;
//    obj.bluetooth = data.bluetooth;
//    obj.climat = data.climat;
//    obj.seatHeating = data.seatHeating;
//    obj.gps = data.gps;
//    obj.sunroof = data.sunroof;
//    obj.batteryCapacity = data.batteryCapacity;
//}

void Database :: AddInDatabase(HybridCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;
    data.interior.color = obj.interior.color;
    data.interior.material = obj.interior.material;
    data.color = obj.color;
    data.costPerDay = obj.costPerDay;
    data.costPerWeek = obj.costPerWeek;
    data.costPerMonth = obj.costPerMonth;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;
    data.batteryCapacity = obj.batteryCapacity;

    ofstream file;
    file.open("../Files/HybridCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
//void Database :: GetFromDatabase(HybridCar &obj)
//{
//    struct Data
//    {
//        int id;
//        bool deleteMark;
//        string brand, model, country, bodyType;
//        int manufacturedYear;
//        string transmissionType;
//        int numberOfSeats;
//        int odometer;
//        int horsepower;
//        float maxSpeed;
//        float to100;
//        float consumption;
//        float volume;
//        struct interior
//        {
//            string color, material;
//        } interior;
//        string color;
//        int costPerDay, costPerWeek, costPerMonth;
//        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
//        int batteryCapacity;
//    } data;
//
//    ifstream file;
//    file.open("../Files/HybridCars.bin", ios::binary);
//    if (!file.is_open())
//        cout << "Error";
//    file.read((char*)&data, sizeof(data));
//    file.close();
//
//    obj.id = data.id;
//    obj.deleteMark = data.deleteMark;
//    obj.brand = data.brand;
//    obj.model = data.model;
//    obj.country = data.country;
//    obj.bodyType = data.bodyType;
//    obj.manufacturedYear = data.manufacturedYear;
//    obj.transmissionType = data.transmissionType;
//    obj.numberOfSeats = data.numberOfSeats;
//    obj.odometer = data.odometer;
//    obj.horsepower = data.horsepower;
//    obj.maxSpeed = data.maxSpeed;
//    obj.to100 = data.to100;
//    obj.consumption = data.consumption;
//    obj.volume = data.volume;
//    obj.interior.color = data.interior.color;
//    obj.interior.material = data.interior.material;
//    obj.color = data.color;
//    obj.costPerDay = data.costPerDay;
//    obj.costPerWeek = data.costPerWeek;
//    obj.costPerMonth = data.costPerMonth;
//    obj.cruiseControl = data.cruiseControl;
//    obj.parkingAssist = data.parkingAssist;
//    obj.music = data.music;
//    obj.bluetooth = data.bluetooth;
//    obj.climat = data.climat;
//    obj.seatHeating = data.seatHeating;
//    obj.gps = data.gps;
//    obj.sunroof = data.sunroof;
//    obj.batteryCapacity = data.batteryCapacity;
//}

void Database :: DeleteFromDatabase(DieselCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        string brand, model, country, bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            string color, material;
        } interior;
        string color;
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;
    fstream file;
    file.open("../Files/DieselCars.bin", ios::binary | ios::in);
    if (!file.is_open())
        cout << "Error";

    int pos = 0;

    while(file.read((char*)&data, sizeof(data)))
    {
        if (obj.id == data.id)
       {
            data.deleteMark = true;
            file.close();
            file.open("../Files/DieselCars.bin", ios::binary | ios::app);
            if (!file.is_open())
               cout << "Error";
            file.seekg(pos * sizeof(data), ios::beg);
            file.write((char*)&data, sizeof(data));
            file.close();
            return;
        }
        pos++;
    }
} // удаление из файла, не работает