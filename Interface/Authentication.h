#ifndef CARRENT_AUTHENTICATION_H
#define CARRENT_AUTHENTICATION_H
#include "Interface.h"

class Authentication : public Interface
{
private:
    Authentication() = default;
    ~Authentication() = default;
    void AdminAuthentication(); // аутентификация администратора
    void UserAuthentication(); // аутентификация пользователя
};


#endif //CARRENT_AUTHENTICATION_H
