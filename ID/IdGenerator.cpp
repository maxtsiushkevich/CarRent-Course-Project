#include "IdGenerator.h"

// ID определяется исходя из ID прошлого элмента, который записывается в файл

int IdGenerator :: GetIdForCar()
{
    fstream file; // файл для записи и чтения
    file.open("/Users/max/Desktop/CarRent/ID/CarId.bin", ios::binary | ios::in); // открытие файла
    int id = 1;
    if (!file.is_open()) // если файла несуществует, то ID = 1
    {
        ofstream file2("/Users/max/Desktop/CarRent/ID/CarId.bin", ios::binary | ios::app);
        file2.write((char*)&id, sizeof(int));
        file2.close();
        return id;
    }
    file.seekp(0, ios::beg); // если существует
    file.read((char*)&id, sizeof(int)); // то считываем значение
    file.close(); // закрываем
    id++; // прибавляем 1
    file.open("/Users/max/Desktop/CarRent/ID/CarId.bin", ios::binary | ios::out);
    file.write((char*)&id, sizeof(int)); // открываем файл для записи и перезаписываем новое значение
    file.close();
    return id; // возвращаем значение
}

int IdGenerator :: GetIdForPerson() // все абсолютно аналогично
{
    fstream file;
    file.open("/Users/max/Desktop/CarRent/ID/PersonID.bin", ios::binary | ios::in);
    int id = 1;
    if (!file.is_open())
    {
        ofstream file2("/Users/max/Desktop/CarRent/ID/PersonID.bin", ios::binary | ios::app);
        file2.write((char*)&id, sizeof(int));
        file2.close();
        return 1;
    }
    file.seekp(0, ios::beg);
    file.read((char*)&id, sizeof(int));
    file.close();
    id++;
    file.open("/Users/max/Desktop/CarRent/ID/PersonID.bin", ios::binary | ios::out);
    file.write((char*)&id, sizeof(int));
    file.close();
    return id;
}