#include "Database.h"
#include <string>
#include <fstream>
#include <iostream>

void Database :: AddInDatabase(OilCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
    } data;

    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.plate = obj.plate;
    data.engine.horsepower = obj.engine.horsepower;
    data.engine.maxSpeed = obj.engine.maxSpeed;
    data.engine.to100 = obj.engine.to100;
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
    file.open("/Users/max/Desktop/CarRent/Files/OilCars.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(OilCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/OilCars.bin", ofstream::binary);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&data, sizeof(data));
    file.close();

    obj.deleteMark = data.deleteMark;
    obj.brand = data.brand;
    obj.model = data.model;
    obj.country = data.country;
    obj.bodyType = data.bodyType;
    obj.manufacturedYear = data.manufacturedYear;
    obj.transmissionType = data.transmissionType;
    obj.numberOfSeats = data.numberOfSeats;
    obj.odometer = data.odometer;
    obj.plate = data.plate;
    obj.engine.horsepower = data.engine.horsepower;
    obj.engine.maxSpeed = data.engine.maxSpeed;
    obj.engine.to100 = data.engine.to100;
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
}

void Database :: AddInDatabase(DieselCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
    } data;

    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.plate = obj.plate;
    data.engine.horsepower = obj.engine.horsepower;
    data.engine.maxSpeed = obj.engine.maxSpeed;
    data.engine.to100 = obj.engine.to100;
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
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(DieselCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ofstream::binary);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&data, sizeof(data));
    file.close();

    obj.deleteMark = data.deleteMark;
    obj.brand = data.brand;
    obj.model = data.model;
    obj.country = data.country;
    obj.bodyType = data.bodyType;
    obj.manufacturedYear = data.manufacturedYear;
    obj.transmissionType = data.transmissionType;
    obj.numberOfSeats = data.numberOfSeats;
    obj.odometer = data.odometer;
    obj.plate = data.plate;
    obj.engine.horsepower = data.engine.horsepower;
    obj.engine.maxSpeed = data.engine.maxSpeed;
    obj.engine.to100 = data.engine.to100;
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
}

void Database :: AddInDatabase(PetrolCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int petrolType;
    } data;

    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.plate = obj.plate;
    data.engine.horsepower = obj.engine.horsepower;
    data.engine.maxSpeed = obj.engine.maxSpeed;
    data.engine.to100 = obj.engine.to100;
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
    file.open("/Users/max/Desktop/CarRent/Files/PetrolCars.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(PetrolCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int petrolType;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/DieselCars.bin", ofstream::binary);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&data, sizeof(data));
    file.close();

    obj.deleteMark = data.deleteMark;
    obj.brand = data.brand;
    obj.model = data.model;
    obj.country = data.country;
    obj.bodyType = data.bodyType;
    obj.manufacturedYear = data.manufacturedYear;
    obj.transmissionType = data.transmissionType;
    obj.numberOfSeats = data.numberOfSeats;
    obj.odometer = data.odometer;
    obj.plate = data.plate;
    obj.engine.horsepower = data.engine.horsepower;
    obj.engine.maxSpeed = data.engine.maxSpeed;
    obj.engine.to100 = data.engine.to100;
    obj.consumption = data.consumption;
    obj.volume = data.volume;
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
    obj.petrolType = data.petrolType;
}

void Database :: AddInDatabase(ElectricCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int batteryCapacity;
    } data;

    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.plate = obj.plate;
    data.engine.horsepower = obj.engine.horsepower;
    data.engine.maxSpeed = obj.engine.maxSpeed;
    data.engine.to100 = obj.engine.to100;
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
    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(ElectricCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int batteryCapacity;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/ElectricCars.bin", ofstream::binary);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&data, sizeof(data));
    file.close();

    obj.deleteMark = data.deleteMark;
    obj.brand = data.brand;
    obj.model = data.model;
    obj.country = data.country;
    obj.bodyType = data.bodyType;
    obj.manufacturedYear = data.manufacturedYear;
    obj.transmissionType = data.transmissionType;
    obj.numberOfSeats = data.numberOfSeats;
    obj.odometer = data.odometer;
    obj.plate = data.plate;
    obj.engine.horsepower = data.engine.horsepower;
    obj.engine.maxSpeed = data.engine.maxSpeed;
    obj.engine.to100 = data.engine.to100;
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
    obj.batteryCapacity = data.batteryCapacity;
}

void Database :: AddInDatabase(HybridCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int batteryCapacity;
    } data;

    data.deleteMark = obj.deleteMark;
    data.brand = obj.brand;
    data.model = obj.model;
    data.country = obj.country;
    data.bodyType = obj.bodyType;
    data.manufacturedYear = obj.manufacturedYear;
    data.transmissionType = obj.transmissionType;
    data.numberOfSeats = obj.numberOfSeats;
    data.odometer = obj.odometer;
    data.plate = obj.plate;
    data.engine.horsepower = obj.engine.horsepower;
    data.engine.maxSpeed = obj.engine.maxSpeed;
    data.engine.to100 = obj.engine.to100;
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
    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ofstream::binary | ofstream::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)&data, sizeof(data));
    file.close();
}
void Database :: GetFromDatabase(HybridCar &obj)
{
    struct Data
    {
        bool deleteMark;
        string brand;
        string model;
        string country;
        string bodyType;
        int manufacturedYear;
        string transmissionType;
        int numberOfSeats;
        int odometer;
        string plate;
        struct engine
        {
            int horsepower;
            float maxSpeed;
            float to100;
        } engine;
        float consumption;
        float volume;
        struct interior
        {
            string color;
            string material;
        } interior;
        string color;
        int costPerDay;
        int costPerWeek;
        int costPerMonth;
        bool cruiseControl;
        bool parkingAssist;
        bool music;
        bool bluetooth;
        bool climat;
        bool seatHeating;
        bool gps;
        bool sunroof;
        int batteryCapacity;
    } data;

    ifstream file;
    file.open("/Users/max/Desktop/CarRent/Files/HybridCars.bin", ofstream::binary);
    if (!file.is_open())
        cout << "Error";
    file.read((char*)&data, sizeof(data));
    file.close();

    obj.deleteMark = data.deleteMark;
    obj.brand = data.brand;
    obj.model = data.model;
    obj.country = data.country;
    obj.bodyType = data.bodyType;
    obj.manufacturedYear = data.manufacturedYear;
    obj.transmissionType = data.transmissionType;
    obj.numberOfSeats = data.numberOfSeats;
    obj.odometer = data.odometer;
    obj.plate = data.plate;
    obj.engine.horsepower = data.engine.horsepower;
    obj.engine.maxSpeed = data.engine.maxSpeed;
    obj.engine.to100 = data.engine.to100;
    obj.consumption = data.consumption;
    obj.volume = data.volume;
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
    obj.batteryCapacity = data.batteryCapacity;
}