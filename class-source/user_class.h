#ifndef USER_CLASS_H
#define USER_CLASS_H
#include <QString>
#define ll long long
#include <QStringList>
class User
{
    QString name ;
    QString username ;
    QString email ;
    ll hpassword ;
    QStringList votedlist ;
public:
    User();
    bool containsmovie (QString n);
    bool contains (QString n) ;
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getUsername() const;
    void setUsername(const QString &newUsername);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    long long getHpassword() const;
    void setHpassword(long long newHpassword);
    const QStringList &getVotedlist() const;
    void setVotedlist(const QStringList &newVotedlist);
};

#endif // USER_CLASS_H
