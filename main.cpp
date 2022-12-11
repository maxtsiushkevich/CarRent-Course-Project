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

    //Interface menu;
    //menu.FirstMenu();

    wchar_t a[10];
    scanf("%ls", a);
    //wcin >> a;
    wcout << a;
    //wchar_t b = L'а';

    //int a1 = a;
    //int b1 = b;
//    a[0] = towupper(a[0]);

    //cout << b1 << endl;

    return 0;
}