#ifndef CARRENT_CARBRANDS_H
#define CARRENT_CARBRANDS_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

struct CarBrands
{
    friend class Car;
private:
    int num;
    char brand[30];
    char country[30];
    CarBrands() = default;
    ~CarBrands() = default;
    void GetCarBrands();
    string GetCountry(int);
    string GetBrand(int);
};

void CarBrands :: GetCarBrands()
{
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    cout << setw(10) << right << "Номер" << setw(15) << "Марка" << setw(15) << "Страна" << endl;
    while (file.read((char*)this, sizeof(CarBrands)))
    {
        cout << setw(10) << left << this->num << setw(15) << this->brand << setw(15) << this->country << endl;
    }
    file.close();
}

string CarBrands :: GetBrand(int choice)
{
    ifstream file("../Files/CarBrands.bin", ios::binary);
    string brandTmp;
    if (!file.is_open())
        cout << "Error";
    else
    {
        while (file.read((char*)this, sizeof(CarBrands)))
        {
            if (this->num == choice)
            {
                brandTmp = this->brand;
                return brandTmp;
            }
        }
    }
}

string CarBrands :: GetCountry(int choice)
{
    ifstream file("../Files/CarBrands.bin", ios::binary);
    string countryTmp;
    if (!file.is_open())
        cout << "Error";
    else
    {
        while (file.read((char*)this, sizeof(CarBrands)))
        {
            if (this->num == choice)
            {
                countryTmp = this->country;
                return countryTmp;
            }
        }
    }
}

#endif