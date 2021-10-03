#include "user_class.h"

const QString &user::getName() const
{
    return name;
}

void user::setName(const QString &newName)
{
    name = newName;
}

const QString &user::getUsername() const
{
    return username;
}

void user::setUsername(const QString &newUsername)
{
    username = newUsername;
}

const QString &user::getEmail() const
{
    return email;
}

void user::setEmail(const QString &newEmail)
{
    email = newEmail;
}

long long user::getHpassword() const
{
    return hpassword;
}

void user::setHpassword(long long newHpassword)
{
    hpassword = newHpassword;
}

user::user()
{
    this->hpassword = 0 ;
}
