#include "file_class.h"

const QList<user> &file::getMy_user() const
{
    return my_user;
}

void file::setMy_user(const QList<user> &newMy_user)
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
    QFile imdb ("C:/Users/Matin/Desktop/prj/phase1-mat-mot/source_info/title.akas.txt") ;
    if (!imdb.open(QIODevice::ReadOnly | QFile::Text) && imdb.exists())
    {
        qInfo() << imdb.errorString() << __LINE__ << endl ;
        return ;
    }
    QFile imdbrat ("C:/Users/Matin/Desktop/prj/phase1-mat-mot/source_info/title.ratings.txt") ;
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
    while (imdbqts.atEnd() && imdbratqts.atEnd() )
    {
        QString tp = imdbqts.readLine() ;
        QStringList tmp = separator(tp , "\r") ;
        QString ttp = imdbratqts.readLine() ;
        QStringList ttmp = separator(ttp , "\r") ;
        move_class newone ;
        newone.setID(tmp.at(0)) ;
        newone.setOrdering(tmp.at(1).toLongLong()) ;
        newone.setTitle(tmp.at(2)) ;
        newone.setRegion(tmp.at(3)) ;
        newone.setLanguage(tmp.at(4)) ;
        newone.setType(tmp.at(5)) ;
        newone.setAttributes(tmp.at(6)) ;
        newone.setIsorginaltitle(tmp.at(7).toInt()) ;
        newone.setAverageRating(ttmp.at(1).toDouble()) ;
        newone.setNumvotes(ttmp.at(2).toULongLong()) ;
        this->my_imdb_class.push_back(newone) ;
    }
    imdb.close() ;
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
    return p;
}

file::file()
{

}
