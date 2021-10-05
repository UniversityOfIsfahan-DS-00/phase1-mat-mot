#include "user_class.h"

const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}

const QString &User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &newUsername)
{
    username = newUsername;
}

const QString &User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &newEmail)
{
    email = newEmail;
}

long long User::getHpassword() const
{
    return hpassword;
}

void User::setHpassword(long long newHpassword)
{
    hpassword = newHpassword;
}

User::User()
{
    this->hpassword = 0 ;
}
