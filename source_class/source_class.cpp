#include "source_class.h"

const QList<user> &source::getMy_user() const
{
    return my_user;
}

void source::setMy_user(const QList<user> &newMy_user)
{
    my_user = newMy_user;
}

const QList<imdb_class> &source::getMy_imdb_class() const
{
    return my_imdb_class;
}

void source::setMy_imdb_class(const QList<imdb_class> &newMy_imdb_class)
{
    my_imdb_class = newMy_imdb_class;
}

source::source()
{

}
