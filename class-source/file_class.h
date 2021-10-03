#ifndef FILE_CLASS_H
#define FILE_CLASS_H
#include "class-source/move_class.h"
#include "class-source/user_class.h"
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <string.h>
#include <QDebug>
#define endl "\n"
class file
{
    QList<user> my_user ;
    QList<move_class> my_imdb_class ;
public:
    file();
    const QList<user> &getMy_user() const;
    void setMy_user(const QList<user> &newMy_user);
    const QList<move_class> &getMy_imdb_class() const;
    void setMy_imdb_class(const QList<move_class> &newMy_imdb_class);
    void load () ;
    void save () ;
    QStringList separator (QString orginal , QString sep ) ;
};

#endif // FILE_CLASS_H
