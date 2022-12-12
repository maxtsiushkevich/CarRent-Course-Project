#include "Database.h"
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
        wchar_t transmissionType[5];
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
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(vector<DieselCar>&dieselCars)
{
    DieselCar obj;
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[5];
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
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ios::binary);
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
        wchar_t transmissionType[5];
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
    PetrolCar obj;
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[5];
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
        wchar_t transmissionType[5];
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
    ElectricCar obj;
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[5];
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
        //     continue;

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
        wchar_t transmissionType[5];
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
        int batteryCapacity;
        wchar_t fuelType[8];
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
    HybridCar obj;
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[5];
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
        int batteryCapacity;
        wchar_t fuelType[8];
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
        wchar_t transmissionType[5];
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
    } data;

    ifstream file1; // для чтения
    ofstream file2; // для записи
    file1.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ios::binary);
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
    remove("/Users/max/Desktop/CarRent/Files/DieselCars.bin");
    file2.close();
    rename("/Users/max/Desktop/CarRent/Files/tmp.bin","/Users/max/Desktop/CarRent/Files/DieselCars.bin");
}
void Database :: DeleteFromDatabase(PetrolCar &obj)
{
    struct Data
    {
        int id;
        bool deleteMark;
        wchar_t brand[30], model[30], country[30], bodyType[30];
        int manufacturedYear;
        wchar_t transmissionType[5];
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
        wchar_t transmissionType[5];
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
        wchar_t transmissionType[5];
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
