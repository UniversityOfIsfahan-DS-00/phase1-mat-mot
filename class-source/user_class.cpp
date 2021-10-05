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

const QStringList &User::getVotedlist() const
{
    return votedlist;
}

void User::setVotedlist(const QStringList &newVotedlist)
{
    votedlist = newVotedlist;
}

User::User()
{
    this->hpassword = 0 ;
}

bool User::contains(QString n)
{
    if (this->username.contains(n))
        return true;
    else if (this->name.contains(n))
        return true;
    else if (this->email.contains(n))
        return true;
    return false;
}
