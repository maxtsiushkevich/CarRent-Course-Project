#include "Car.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Car :: Car()
{
    odometer = 0;
    cout << "Марка автомобиля: " << endl; // выбор
    // открывается файл с марками
    cout << "Модель автомобиля: " << endl; // выбор
    cout << "Год выпуска автомобиля: " << endl;
    cin >> manufacturedYear; // 2000 <= year <= 2022
    cout << "Тип кузова: " << endl;
    cin >> bodyType; // выбор седан универсал хэтчбек лимузин пикап минивен купе кабриолет кроссовер внедорожник
    cout << "Коробка передач: " << endl; // выбор из АКПП или МКПП
    cout << "Государственный номер автомобиля: " << endl;
    cin >> carPlate; // должно соответствовать формату 9999АА-9
    cout << "Стоимость аренды на день: " << endl;
    cin >> costPerDay; // >0
    costPerWeek = costPerDay * 6;
    costPerMonth = costPerDay * 25;

}