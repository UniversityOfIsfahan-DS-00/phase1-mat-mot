#ifndef SOURCE_CLASS_H
#define SOURCE_CLASS_H
#include "imdb_class/imdb_class.h"
#include "user_class/user_class.h"
#include <QList>
#include <QString>
class source
{
    QList<user> my_user ;
    QList<imdb_class> my_imdb_class ;
public:
    source();
    const QList<user> &getMy_user() const;
    void setMy_user(const QList<user> &newMy_user);
    const QList<imdb_class> &getMy_imdb_class() const;
    void setMy_imdb_class(const QList<imdb_class> &newMy_imdb_class);
};

#endif // SOURCE_CLASS_H
