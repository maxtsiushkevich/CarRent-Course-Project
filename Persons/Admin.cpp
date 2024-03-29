#include "Admin.h"
#include "Userdata.h"
#include <fstream>
#include <iostream>
#include "../ID/IdGenerator.h"

void Admin::SetInfo() {
    id = IdGenerator::GetIdForPerson();
    Person::SetInfo();
    Userdata userdata(id);
    userdata.SetInfo(1);
    ofstream file;
    file.open("/Users/max/Desktop/CarRent/Files/Admin.bin", ios::binary | ios::app);
    if (!file.is_open())
        cout << "Error";
    file.write((char *) this, sizeof(Admin));
    file.close();
}