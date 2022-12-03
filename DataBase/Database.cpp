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
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;

    wcscpy(data.brand, obj.brand);
    wcscpy(data.model, obj.model);
    wcscpy(data.country, obj.country);
    wcscpy(data.bodyType, obj.bodyType);

    data.manufacturedYear = obj.manufacturedYear;

    wcscpy(data.transmissionType, obj.transmissionType);

    data.numberOfSeats = obj.numberOfSeats;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;

    wcscpy(data.interior.color, obj.interior.color);
    wcscpy(data.interior.material, obj.interior.material);
    wcscpy(data.color, obj.color);

    data.costPerDay = obj.costPerDay;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCar.bin", ios::binary | ios::app);
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
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCar.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&data, sizeof(data)))
    {
        obj.deleteMark = data.deleteMark;

        //if (obj.deleteMark == true) // если объект считается удаленным, то пропускается
        //    continue;

        obj.id = data.id;
        wcscpy(obj.brand, data.brand);
        wcscpy(obj.model, data.model);
        wcscpy(obj.country, data.country);
        wcscpy(obj.bodyType, data.bodyType);
        obj.manufacturedYear = data.manufacturedYear;
        wcscpy(obj.transmissionType, data.transmissionType);
        obj.numberOfSeats = data.numberOfSeats;
        obj.horsepower = data.horsepower;
        obj.maxSpeed = data.maxSpeed;
        obj.to100 = data.to100;
        obj.consumption = data.consumption;
        obj.volume = data.volume ;
        wcscpy(obj.interior.color, data.interior.color);
        wcscpy(obj.interior.material, data.interior.material);
        wcscpy(obj.color, data.color);
        obj.costPerDay = data.costPerDay;
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
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int petrolType;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    wcscpy(data.brand, obj.brand);
    wcscpy(data.model, obj.model);
    wcscpy(data.country, obj.country);
    wcscpy(data.bodyType, obj.bodyType);
    data.manufacturedYear = obj.manufacturedYear;
    wcscpy(data.transmissionType, obj.transmissionType);
    data.numberOfSeats = obj.numberOfSeats;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;
    wcscpy(data.interior.color, obj.interior.color);
    wcscpy(data.interior.material, obj.interior.material);
    wcscpy(data.color, obj.color);
    data.costPerDay = obj.costPerDay;
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
    file.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(vector<PetrolCar>&petrolCars)
{
    PetrolCar obj(0);
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int petrolType;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while (file.read((char*)&data, sizeof(data)))
    {
        obj.deleteMark = data.deleteMark;

        //if (obj.deleteMark == true) // если объект считается удаленным, то пропускается
        //    continue;

        obj.id = data.id;
        wcscpy(obj.brand, data.brand);
        wcscpy(obj.model, data.model);
        wcscpy(obj.country, data.country);
        wcscpy(obj.bodyType, data.bodyType);
        obj.manufacturedYear = data.manufacturedYear;
        wcscpy(obj.transmissionType, data.transmissionType);
        obj.numberOfSeats = data.numberOfSeats;
        obj.horsepower = data.horsepower;
        obj.maxSpeed = data.maxSpeed;
        obj.to100 = data.to100;
        obj.consumption = data.consumption;
        obj.volume = data.volume;
        wcscpy(obj.interior.color, data.interior.color);
        wcscpy(obj.interior.material, data.interior.material);
        wcscpy(obj.color, data.color);
        obj.costPerDay = data.costPerDay;
        obj.cruiseControl = data.cruiseControl;
        obj.parkingAssist = data.parkingAssist;
        obj.music = data.music;
        obj.bluetooth = data.bluetooth;
        obj.climat = data.climat;
        obj.seatHeating = data.seatHeating;
        obj.gps = data.gps;
        obj.sunroof = data.sunroof;
        obj.petrolType = data.petrolType;

        petrolCars.emplace_back(obj);
    }
    file.close();
}

void Database :: AddInDatabase(ElectricCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    wcscpy(data.brand, obj.brand);
    wcscpy(data.model, obj.model);
    wcscpy(data.country, obj.country);
    wcscpy(data.bodyType, obj.bodyType);
    data.manufacturedYear = obj.manufacturedYear;
    wcscpy(data.transmissionType, obj.transmissionType);
    data.numberOfSeats = obj.numberOfSeats;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    wcscpy(data.interior.color, obj.interior.color);
    wcscpy(data.interior.material, obj.interior.material);
    wcscpy(data.color, obj.color);
    data.costPerDay = obj.costPerDay;
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
    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(vector<ElectricCar>&electricCars)
{
    ElectricCar obj(0);
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&data, sizeof(data)))
    {

        obj.deleteMark = data.deleteMark;

        //if (obj.deleteMark == true) // если объект считается удаленным, то пропускается
        //    continue;

        obj.id = data.id;
        wcscpy(obj.brand, data.brand);
        wcscpy(obj.model, data.model);
        wcscpy(obj.country, data.country);
        wcscpy(obj.bodyType, data.bodyType);
        obj.manufacturedYear = data.manufacturedYear;
        wcscpy(obj.transmissionType, data.transmissionType);
        obj.numberOfSeats = data.numberOfSeats;
        obj.horsepower = data.horsepower;
        obj.maxSpeed = data.maxSpeed;
        obj.to100 = data.to100;
        wcscpy(obj.interior.color, data.interior.color);
        wcscpy(obj.interior.material, data.interior.material);
        wcscpy(obj.color, data.color);
        obj.costPerDay = data.costPerDay;
        obj.cruiseControl = data.cruiseControl;
        obj.parkingAssist = data.parkingAssist;
        obj.music = data.music;
        obj.bluetooth = data.bluetooth;
        obj.climat = data.climat;
        obj.seatHeating = data.seatHeating;
        obj.gps = data.gps;
        obj.sunroof = data.sunroof;
        obj.batteryCapacity = data.batteryCapacity;

        electricCars.emplace_back(obj);
    }

    file.close();
}

void Database :: AddInDatabase(HybridCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
        wchar_t fuelType[6];
    } data;

    data.id = obj.id;
    data.deleteMark = obj.deleteMark;
    wcscpy(data.brand, obj.brand);
    wcscpy(data.model, obj.model);
    wcscpy(data.country, obj.country);
    wcscpy(data.bodyType, obj.bodyType);
    data.manufacturedYear = obj.manufacturedYear;
    wcscpy(data.transmissionType, obj.transmissionType);
    data.numberOfSeats = obj.numberOfSeats;
    data.horsepower = obj.horsepower;
    data.maxSpeed = obj.maxSpeed;
    data.to100 = obj.to100;
    data.consumption = obj.consumption;
    data.volume = obj.volume;
    wcscpy(data.interior.color, obj.interior.color);
    wcscpy(data.interior.material, obj.interior.material);
    wcscpy(data.color, obj.color);
    data.costPerDay = obj.costPerDay;
    data.cruiseControl = obj.cruiseControl;
    data.parkingAssist = obj.parkingAssist;
    data.music = obj.music;
    data.bluetooth = obj.bluetooth;
    data.climat = obj.climat;
    data.seatHeating = obj.seatHeating;
    data.gps = obj.gps;
    data.sunroof = obj.sunroof;
    data.batteryCapacity = obj.batteryCapacity;
    wcscpy(data.fuelType, obj.fuelType);

    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(vector<HybridCar>&hybridCars)
{
    HybridCar obj(0);
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
        wchar_t fuelType[6];
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    while(file.read((char*)&data, sizeof(data)))
    {
        obj.deleteMark = data.deleteMark;

        //if (obj.deleteMark == true) // если объект считается удаленным, то пропускается
        //    continue;

        obj.id = data.id;

        wcscpy(obj.brand, data.brand);
        wcscpy(obj.model, data.model);
        wcscpy(obj.country, data.country);
        wcscpy(obj.bodyType, data.bodyType);

        obj.manufacturedYear = data.manufacturedYear;
        wcscpy(obj.transmissionType, data.transmissionType);
        obj.numberOfSeats = data.numberOfSeats;
        obj.horsepower = data.horsepower;
        obj.maxSpeed = data.maxSpeed;
        obj.to100 = data.to100;
        obj.consumption = data.consumption;
        obj.volume = data.volume;

        wcscpy(obj.interior.color, data.interior.color);
        wcscpy(obj.interior.material, data.interior.material);
        wcscpy(obj.color, data.color);

        obj.costPerDay = data.costPerDay;
        obj.cruiseControl = data.cruiseControl;
        obj.parkingAssist = data.parkingAssist;
        obj.music = data.music;
        obj.bluetooth = data.bluetooth;
        obj.climat = data.climat;
        obj.seatHeating = data.seatHeating;
        obj.gps = data.gps;
        obj.sunroof = data.sunroof;
        obj.batteryCapacity = data.batteryCapacity;

        wcscpy(obj.fuelType, data.fuelType);

        hybridCars.emplace_back(obj);
    }
    file.close();
}

void Database :: DeleteFromDatabase(DieselCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        char color[60];
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
    } data;

    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/DieselCar.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);

    while(file1.read((char*)&data, sizeof(data)))
    {
        if (obj.id == data.id)
        {
            data.deleteMark = obj.deleteMark = true;
            file2.write((char*)&data, sizeof(data));
        }
        else
            file2.write((char*)&data, sizeof(data));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/DieselCar.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/DieselCar.bin");
}
void Database :: DeleteFromDatabase(PetrolCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        wchar_t color[30];
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int petrolType;
    } data;

    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);

    while(file1.read((char*)&data, sizeof(data)))
    {
        if (obj.id == data.id)
        {
            data.deleteMark = obj.deleteMark = true;
            file2.write((char*)&data, sizeof(data));
        }
        else
            file2.write((char*)&data, sizeof(data));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/PetrolCars.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/PetrolCars.bin");
}
void Database :: DeleteFromDatabase(ElectricCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        char color[60];
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
    } data;

    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);

    while(file1.read((char*)&data, sizeof(data)))
    {
        if (obj.id == data.id)
        {
            data.deleteMark = obj.deleteMark = true;
            file2.write((char*)&data, sizeof(data));
        }
        else
            file2.write((char*)&data, sizeof(data));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/ElectricCars.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/ElectricCars.bin");
}
void Database :: DeleteFromDatabase(HybridCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[4];
        int numberOfSeats;
        int horsepower;
        float maxSpeed;
        float to100;
        float consumption;
        float volume;
        struct interior
        {
            wchar_t color[30], material[30];
        } interior;
        char color[60];
        int costPerDay, costPerWeek, costPerMonth;
        bool cruiseControl, parkingAssist, music, bluetooth, climat, seatHeating, gps, sunroof;
        int batteryCapacity;
        char fuelType[60];
    } data;

    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ios::binary);
    if (!file1.is_open())
        cout << "Error";
    file2.open("/Users/max/Desktop/CarRent/Files/tmp.bin", ios::binary | ios::app);

    while(file1.read((char*)&data, sizeof(data)))
    {
        if (obj.id == data.id)
        {
            data.deleteMark = obj.deleteMark = true;
            file2.write((char*)&data, sizeof(data));
        }
        else
            file2.write((char*)&data, sizeof(data));
    }
    file1.close();
    remove("/Users/max/Desktop/CarRent/Files/HybridCars.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/HybridCars.bin");
}
