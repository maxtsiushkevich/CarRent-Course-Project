#include "IdGenerator.h"

int IdGenerator :: GetIdForCar()
{
    fstream file;
    file.open("../ID/CarId.bin", ios::binary | ios::in);
    int id = 1;
    if (!file.is_open())
    {
        ofstream file2("../ID/CarId.bin", ios::binary | ios::app);
        file2.write((char*)&id, sizeof(int));
        file2.close();
        return 1;
    }
    file.seekp(0, ios::beg);
    file.read((char*)&id, sizeof(int));
    file.close();
    id++;
    file.open("../ID/CarId.bin", ios::binary | ios::out);
    file.write((char*)&id, sizeof(int));
    file.close();
    return id;
}
int IdGenerator :: GetIdForPerson()
{
    fstream file;
    file.open("../ID/PersodID.bin", ios::binary | ios::in);
    int id = 1;
    if (!file.is_open())
    {
        ofstream file2("../ID/PersodID.bin", ios::binary | ios::app);
        file2.write((char*)&id, sizeof(int));
        file2.close();
        return 1;
    }
    file.seekp(0, ios::beg);
    file.read((char*)&id, sizeof(int));
    file.close();
    id++;
    file.open("../ID/PersodID.bin", ios::binary | ios::out);
    file.write((char*)&id, sizeof(int));
    file.close();
    return id;
}