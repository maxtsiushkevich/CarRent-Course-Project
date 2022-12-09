#include <iostream>
#include "Interface/Interface.h"
#include <locale>
#include "Database/Database.h"
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));

    Interface menu;
    menu.FirstMenu();

    return 0;
}