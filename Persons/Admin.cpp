#include "Admin.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

void Admin :: SetInfo()
{
    Person::SetInfo();
    Userdata userdata(id);
    userdata.SetInfo(1);
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/Admin.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(Admin));
    file.close();
}