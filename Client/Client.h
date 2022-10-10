#ifndef CARRENT_CLIENT_H
#define CARRENT_CLIENT_H
#pragma once
#include <string>

using namespace std;

class Client
{
private:
    string name;
    string surname;
    double balance;
public:
    Client();
    ~Client();
    void addBalance (double);
    string getName ();
    string getSurname();
    void getBalance();

};


#endif
