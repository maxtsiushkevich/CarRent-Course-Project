#ifndef CARRENT_AUTHENTICATION_H
#define CARRENT_AUTHENTICATION_H

#include "Interface.h"

class Authentication {
    friend class Interface;

private:
    Userdata account;

    Authentication() = default;

    ~Authentication() = default;

    bool AdminAuthentication(Admin &); // аутентификация администратора
    bool UserAuthentication(User &); // аутентификация пользователя
};


#endif //CARRENT_AUTHENTICATION_H
