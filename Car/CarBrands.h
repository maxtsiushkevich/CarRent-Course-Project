#ifndef CARRENT_CARBRANDS_H
#define CARRENT_CARBRANDS_H
#include <fstream>
#include <iostream>
using namespace std;

struct CarBrands
{
    int num;
    char brand[30];
    char country[30];

    void GetCarBrands();
    string GetCountry(int);
    string GetBrand(int);
};

void CarBrands :: GetCarBrands() // оформить вывод в виде красивой таблицы
{
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
    int i = 1;
    if (!file.is_open())
        cout << "Error";
    else
    {
        while (file.read((char*)this, sizeof(CarBrands)))
        {
            cout << this->num << ' ' << this->brand << ' ' << this->country << "\t\t\t";
            i++;
            if (i == 4)
            {
                cout << endl;
                i=1;
            }
        }
    }
    file.close();
}

string CarBrands :: GetBrand(int choice)
{
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
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
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
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
