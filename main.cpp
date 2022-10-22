#include <iostream>
#include "Car/Car.h"
#include "Car/ElectricCar.h"
#include "Car/HybridCar.h"
#include "Car/OilCar.h"
#include <string>
#include <fstream>

using namespace std;

void mainMenu(int);
void authentication(int);

//void test_label(int x)
//{
//
//    if (x == 1)
//    {
//        goto label1;
//    }
//    else
//        goto label2;
//
//    label1:
//    cout << "in label1" << endl;
//    return;
//
//    label2:
//    cout << "in label2" << endl;
//    return;
//}

int main()
{
    setlocale(LC_ALL, "ru");

    HybridCar h1;

    //OilCar c1;
    //c1.writeInFile();

    //OilCar c2(0);
    //c2.printAllCars();

    //c2.writeInFile();

    //c2.readFromFile();
    //c2.printAllInfo();

    //int main()
    //{
    //    test_label(2);  // in label1
    //    test_label(2);  // in label2
    //}

    //Car c2(0);

    //ifstream carsFile("/Users/max/Desktop/CarRent/AllCars.bin", ios::binary);
    //if (!carsFile.is_open())
    //    cout << "Error";
    //carsFile.read((char*)&c2, sizeof(Car));
    //carsFile.close();
    //c2.printAll();

    //cout << "Car" << sizeof(Car) << endl;
    //cout << "GasCar" << sizeof(GasCar) << endl;
    //cout << "ElectricCar" << sizeof(ElectricCar) << endl;
    //cout << "OilCar" << sizeof(OilCar) << endl;
    //cout << "HybridCar" << sizeof(HybridCar) << endl;

}


void firstMenu()
{
    int choice;
    cout << "1 - Войти как администатор"
            "2 - Войти как пользователь";
    cin >> choice;
    while (choice != 1 || choice == 2)
    {
        cout << "Не верный ввод. Введите еще раз: ";
        cin >> choice;
    }
    if (choice == 1)
        authentication(1);
    else
        authentication(2);

}

void authentication (int mode) // mode 1 - админ; mode 2 - юзер
{
    string login, password;
    cout << "Введите логин: ";
    cin >> login;
    cout << "Введите логин: ";
    cin >> password;
    //if (mode == 1)
    //{
        //ifstream file("/Users/max/Desktop/CarRent/admin.bin", ios::binary);
        //file.seekg(0, ios::beg);
        //if (!file.is_open())
        //    cout << "Error";
        //file.read((char*)this, sizeof(OilCar));
        //file.close();
    //}

    //if (mode == 2)
    //{
        //ifstream file("/Users/max/Desktop/CarRent/user.bin", ios::binary);
        //file.seekg(0, ios::beg);
        //if (!file.is_open())
        //    cout << "Error";
        //file.read((char*)this, sizeof(OilCar));
        //file.close();
    //}

    // поиск аккаунта по логину и паролю
    // файл admin.bin для админа
    // файл user.bin для юзера
}

void MainMenu (int mode)
{
    cout << "1 - Все автомобили"
            "2 - Доступные автомобили"
            "3 - История аккаунта";

    cout << "1 - Все автомобиля"
            "2 - Редактировать инофрмацию об автомобилях"
            "3 - Все пользователи"
            "4 - Редактировать информацию о пользователях";
}

