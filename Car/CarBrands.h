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
    wchar_t brand[30] = {L"\0"};
    wchar_t country[30] = {L"\0"};
    CarBrands() = default;
    ~CarBrands() = default;
    void GetCarBrands();
    wstring GetCountry(int);
    wstring GetBrand(int);
    void AddNewBrand();
};

void CarBrands :: AddNewBrand()
{
    cin >> num;
    fflush(stdin);
    fgetws(brand, 30, stdin);
    brand[wcscspn(brand, L"\n")] = L'\0';
    fflush(stdin);
    fgetws(country, 30, stdin);
    country[wcscspn(country, L"\n")] = L'\0';
    ofstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(CarBrands));
    file.close();
}

void CarBrands :: GetCarBrands()
{
    ifstream file("/Users/max/Desktop/CarRent/Files/CarBrands.bin", ios::binary);
    if (!file.is_open())
        cout << "Error";
    cout << left << setw(15) << "Номер" << setw(20) << "Марка" << setw(20) << "Страна" << endl;
    while (file.read((char*)this, sizeof(CarBrands)))
    {
        wcout << left << setw(10) << this->num << setw(15) << this->brand << setw(20) << this->country << endl;
    }
    file.close();
}

wstring CarBrands :: GetBrand(int choice)
{
    ifstream file("../Files/CarBrands.bin", ios::binary);
    wstring brandTmp;
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

wstring CarBrands :: GetCountry(int choice)
{
    ifstream file("../Files/CarBrands.bin", ios::binary);
    wstring countryTmp;
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