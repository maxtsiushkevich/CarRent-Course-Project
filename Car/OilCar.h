#ifndef CARRENT_OILCAR_H
#define CARRENT_OILCAR_H
#include "Car.h"
#include <string>

class OilCar : virtual protected Car
{
protected:
    struct engine
    {
        float consumption; // расход
        float engineVolume; // объем
    } engine;
public:
    OilCar();
    OilCar(int);
    virtual ~OilCar();
    void writeInFile(); // записывает в файл объект
    void readFromFile(); // читает из файла объект
    void printAllInfo(); // печатает информацию об авто
    void printAllCars(); // печатает информацию обо всех авто в файлах

    //void printByCriteria(string);
    //void printByCriteria(int);
    //void printByCriteria(float);
};

#endif
