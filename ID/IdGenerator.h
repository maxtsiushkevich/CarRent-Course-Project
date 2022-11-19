#ifndef CARRENT_IDGENERATOR_H
#define CARRENT_IDGENERATOR_H
#include <fstream>
#include <iostream>

using namespace std;

class IdGenerator
{
    friend class Car;
public:
    static int GetIdForCar();
    static int GetIdForPerson();
};


#endif //CARRENT_IDGENERATOR_H
