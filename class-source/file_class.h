#ifndef FILE_CLASS_H
#define FILE_CLASS_H
#include "class-source/movie_class.h"
#include "class-source/user_class.h"
#include <QList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <string.h>
#include <QDebug>
#include <QMessageBox>
#include <list>
#include <QVector>
#define endl "\n"
class file
{
public:
    file();
    void edit_movie (movie_class tmp) ;
    void edit_user (User tmp );
    QVector<movie_class> sort_movie () ;
    QStringList items (QString x) ;
    QList<movie_class> my_imdb_class ;
    QList<User> my_user ;
    const QList<User> &getMy_user() const;
    void setMy_user(const QList<User> &newMy_user);
    const QList<movie_class> &getMy_imdb_class() const;
    void setMy_imdb_class(const QList<movie_class> &newMy_imdb_class);
    bool load () ;
    bool save () ;
    QStringList separator (QString orginal , QString sep ) ;
    QString disseparaor (QStringList list , QString sep ) ;
    QList<movie_class> mlistcontains (QString n) ;
    QList<User> ulistcontains (QString n) ;
    void remove_user (QString username);
    void remove_movie (QString ID) ;
};

#endif // FILE_CLASS_H
