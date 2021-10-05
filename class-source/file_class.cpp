#include "file_class.h"

const QList<User> &file::getMy_user() const
{
    return my_user;
}

void file::setMy_user(const QList<User> &newMy_user)
{
    my_user = newMy_user;
}

const QList<move_class> &file::getMy_imdb_class() const
{
    return my_imdb_class;
}

void file::setMy_imdb_class(const QList<move_class> &newMy_imdb_class)
{
    my_imdb_class = newMy_imdb_class;
}

void file::load()
{
    QString temp =  __FILE__  ;
    QFile imdb (temp +  "/../../data/title.akas.txt") ;
    if (!imdb.open(QIODevice::ReadOnly | QFile::Text) && imdb.exists())
    {
        qInfo() << imdb.errorString() << __LINE__ << endl ;
        return ;
    }
    QFile imdbrat (temp +  "/../../data/title.ratings.txt") ;
    if (!imdbrat.open(QIODevice::ReadOnly) && imdbrat.exists())
    {
        qInfo() << imdbrat.errorString() << __LINE__ << endl ;
        return ;
    }


    QTextStream imdbqts (&imdb) ;
    imdbqts.seek(0) ;
    imdbqts.readLine() ;
    QTextStream imdbratqts (&imdbrat) ;
    imdbratqts.seek(0) ;
    imdbratqts.readLine() ;
    //qInfo() << imdbqts.readAll() << endl ;
    //qInfo() << imdbratqts.readAll() << endl ;
    while (!imdbqts.atEnd() && !imdbratqts.atEnd() )
    {
        QString tp = imdbqts.readLine() ;
        QStringList tmp = separator(tp , "\t") ;
        QString ttp = imdbratqts.readLine() ;
        QStringList ttmp = separator(ttp , "\t") ;
        move_class newone ;
        //qInfo() << tmp.at(1) << endl ;
        newone.setID(tmp.at(0)) ;
        newone.setOrdering(tmp.at(1).toLongLong()) ;
        newone.setTitle(tmp.at(2)) ;
        newone.setRegion(tmp.at(3)) ;
        newone.setLanguage(tmp.at(4)) ;
        newone.setType(tmp.at(5)) ;
        newone.setAttributes(tmp.at(6)) ;
        newone.setIsorginaltitle(tmp.at(7).toInt()) ;
        newone.setAverageRating(ttmp.at(0).toDouble()) ;
        newone.setNumvotes(ttmp.at(1).toULongLong()) ;
        this->my_imdb_class.push_back(newone) ;
    }
    imdb.close() ;
    imdbrat.close();
    QFile user (temp +  "/../../data/user.txt") ;
    if (!user.open(QIODevice::ReadOnly | QFile::Text) && user.exists())
    {
        qInfo() << user.errorString() << __LINE__ << endl ;
        return ;
    }
    QTextStream userqts (&user) ;
    userqts.seek(0) ;
    userqts.readLine() ;
    while (!userqts.atEnd() )
    {
        QString tp = userqts.readLine() ;
        QStringList tmp = separator(tp , "\t") ;
        User newone ;
        newone.setUsername(tmp.at(0)) ;
        newone.setHpassword(tmp.at(1).toLongLong()) ;
        newone.setName(tmp.at(2)) ;
        newone.setEmail(tmp.at(3)) ;
        this->my_user.push_back(newone) ;
    }
    user.close() ;
}

void file::save()
{

}

QStringList file::separator(QString orginal, QString sep)
{
    QStringList p ;
    QString tmp ;
    int i = orginal.size() ;
    for (int j=0 ; j < i ; j++)
    {
        if (orginal[j] == sep)
        {
            p.push_back(tmp) ;
            tmp.clear();
            continue;
        }
        tmp += orginal[j] ;
    }
    p.push_back(tmp) ;
    return p;
}

file::file()
{

}

QStringList file::items(QString x)
{
    QStringList tmp ;
    if (x == "move")
    {
        for (int i=0 ; i< my_imdb_class.size() ; i++)
            tmp.push_back(my_imdb_class.at(i).getTitle() + " [" + my_imdb_class.at(i).getID() + "]" ) ;
    }
    else if (x == "user")
    {
        for (int i=0 ; i<my_user.size() ; i++)
            tmp.push_back(my_user.at(i).getUsername()) ;
    }
    return tmp;
}
