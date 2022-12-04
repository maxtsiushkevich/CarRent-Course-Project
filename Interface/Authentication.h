#ifndef CARRENT_AUTHENTICATION_H
#define CARRENT_AUTHENTICATION_H
#include "Interface.h"

class Authentication : public Interface
{
    friend class Interface;
private:
    Authentication() = default;
    ~Authentication() = default;
    bool AdminAuthentication(); // аутентификация администратора
    bool UserAuthentication(); // аутентификация пользователя
};


#endif //CARRENT_AUTHENTICATION_H
