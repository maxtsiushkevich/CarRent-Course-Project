#ifndef CARRENT_EXCEPTION_H
#define CARRENT_EXCEPTION_H
#include <string>
#include <iostream>
using namespace std;

class Exception
{
protected:
    string message;
public:
    Exception() = default;
    Exception(string message)
    {
        this->message = message;
    }
    void Show()
    {
        cout << message << endl;
    }
};
class BadInputException : public Exception
{
public:
    BadInputException(string message) : Exception()
    {
        this->message = message;
    }
};

class OverflowException : public Exception
{
public:
    OverflowException(string message) : Exception()
    {
        this->message = message;
    }
};
class EmptyInputException : public Exception
{
public:
    EmptyInputException(string message) : Exception()
    {
        this->message = message;
    }
};
class SpaceException : public Exception
{
public:
    SpaceException(string message) : Exception()
    {
        this->message = message;
    }
};

#endif
