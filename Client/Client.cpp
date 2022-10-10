#include "Client.h"
#include <iostream>

using namespace std;

Client :: Client ()
{
    balance = 0;
    cout << "Введите фамилию: ";
    cin >> surname;
    cout << "Введите имя: ";
    cin >> name;
}

Client :: ~Client() { }

 string Client :: getName() {
    return name; }

string Client :: getSurname () {
    return surname; }

void Client :: addBalance (double price) {
    balance += price; }