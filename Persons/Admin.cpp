#include "Admin.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>

Admin :: Admin()
{
    Userdata user(id, 1);
    ofstream file;
    file.open("../Files/Admin.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char*)this, sizeof(Admin));
    file.close();
}