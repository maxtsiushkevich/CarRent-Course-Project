#include <iostream>
#include "Interface/Interface.h"
#include <locale>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wcout.imbue(locale("ru_RU.UTF-8"));
    wcin.imbue(locale("ru_RU.UTF-8"));
    //wchar_t tmpPassportNum[15];

    Interface menu;
    menu.FirstMenu();

//    fgetws(tmpPassportNum, 15, stdin);
//    tmpPassportNum[wcscspn(tmpPassportNum, L"\n")] = L'\0';
//    wcout << tmpPassportNum << endl;
//    cout << tmpPassportNum.length() << endl;
    return 0;
}