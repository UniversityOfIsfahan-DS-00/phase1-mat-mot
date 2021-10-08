#include "file_class.h"

const QList<User> &file::getMy_user() const
{
    return my_user;
}

void file::setMy_user(const QList<User> &newMy_user)
{
    my_user = newMy_user;
}

const QList<movie_class> &file::getMy_imdb_class() const
{
    return my_imdb_class;
}

void file::setMy_imdb_class(const QList<movie_class> &newMy_imdb_class)
{
    my_imdb_class = newMy_imdb_class;
}

bool file::load()
{
    QString temp =  __FILE__  ;
    QFile imdb (temp +  "/../../data/title.akas.txt") ;
    if (!imdb.open(QIODevice::ReadOnly | QFile::Text) && imdb.exists())
    {
        qInfo() << imdb.errorString() << __LINE__ << endl ;
        return false ;
    }
    QFile imdbrat (temp +  "/../../data/title.ratings.txt") ;
    if (!imdbrat.open(QIODevice::ReadOnly) && imdbrat.exists())
    {
        qInfo() << imdbrat.errorString() << __LINE__ << endl ;
        return false ;
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
        movie_class newone ;
        //qInfo() << tmp.at(1) << endl ;
        newone.setID(tmp.at(0)) ;
        newone.setOrdering(tmp.at(1).toLongLong()) ;
        newone.setTitle(tmp.at(2)) ;
        newone.setRegion(tmp.at(3)) ;
        newone.setLanguage(tmp.at(4)) ;
        QString a (tmp.at(5)) ;
        QString b (tmp.at(6)) ;
        newone.setType( separator(a , " ") );
        newone.setAttributes( separator(b , " ") );
        newone.setIsorginaltitle(tmp.at(7).toInt()) ;
        newone.setAverageRating(ttmp.at(1).toDouble()) ;
        newone.setNumvotes(ttmp.at(2).toULongLong()) ;
        this->my_imdb_class.push_back(newone) ;
    }
    imdb.close() ;
    imdbrat.close();
    QFile user (temp +  "/../../data/user.txt") ;
    if (!user.open(QIODevice::ReadOnly | QFile::Text) && user.exists())
    {
        qInfo() << user.errorString() << __LINE__ << endl ;
        return false ;
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
        QString a (tmp.at(4)) ;
        newone.setVotedlist(separator(a , " ")) ;
        this->my_user.push_back(newone) ;
    }
    user.close() ;
    return true;
}

bool file::save()
{
    QString temp =  __FILE__  ;
    QFile acc (temp +  "/../../data/title.akas.txt") ;
    if (!acc.open(QIODevice::WriteOnly))
    {
        qInfo() << acc.errorString() << endl ;
        QMessageBox:: information(nullptr , "bad acces" , "file can not open and data was not saved make sure that save it again !") ;
        return false;
    }
    QFile bcc (temp +  "/../../data/title.ratings.txt") ;
    if (!bcc.open(QIODevice::WriteOnly))
    {
        qInfo() << bcc.errorString() << endl ;
        QMessageBox:: information(nullptr , "bad acces" , "file can not open and data was not saved make sure that save it again !") ;
        return false;
    }
    QTextStream streem (&acc) ;
    streem.seek(0) ;
    QTextStream bstreem (&bcc) ;
    bstreem.seek(0) ;
    streem << "titleId\tordering\ttitle\tregion\tlanguage\ttypes\tattributes\tisOriginalTitle\n" ;
    bstreem << "tconst\taverageRating\tnumVotes\n" ;
    for (auto ito = my_imdb_class.begin() ; ito != my_imdb_class.end() && my_imdb_class.size() > 0 ; ++ito )
    {
        streem << ito->getID() + "\t" ;
        streem << QString::number( ito->getOrdering()) + "\t" ;
        streem << ito->getTitle() + "\t" ;
        streem << ito->getRegion() + "\t" ;
        streem << ito->getLanguage() + "\t" ;
        streem << this->disseparaor(ito->getType() , " " ) + "\t" ;
        streem << this->disseparaor(ito->getAttributes() , " " ) + "\t" ;
        streem << QString::number(ito->getIsorginaltitle()) + "\n" ;
        bstreem << ito->getID() << "\t" << QString::number(ito->getAverageRating()) << "\t" << QString::number(ito->getNumvotes()) << "\n" ;
    }
    acc.close() ;
    bcc.close() ;
    QFile ucc (temp +  "/../../data/user.txt") ;
    if (!ucc.open(QIODevice::WriteOnly))
    {
        qInfo() << ucc.errorString() << endl ;
        QMessageBox:: information(nullptr , "bad acces" , "file can not open and data was not saved make sure that save it again !") ;
        return false;
    }
    QTextStream ustreem (&ucc) ;
    ustreem.seek(0) ;
    ustreem << "username\thashedpassword\tname\temail\tvotedmovelist\n" ;
    for (auto ito = my_user.begin() ; ito !=my_user.end() && my_user.size()>0 ;++ito)
    {
        ustreem << ito->getUsername() + "\t" ;
        ustreem << QString::number( ito->getHpassword()) + "\t" ;
        ustreem << ito->getName() + "\t" ;
        ustreem << ito->getEmail() + "\t" ;
        ustreem << this->disseparaor(ito->getVotedlist() , " ") + "\n" ;
    }
    ucc.close() ;
    return true;
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

QString file::disseparaor(QStringList list, QString sep)
{
    QString tmp ;
    for (int i=0 ; i<list.size() ; i++)
    {
        tmp += list.at(i) ;
        if (i != list.size()-1)
            tmp += sep ;
    }
//    int i=list.size()-1 ;
//    if ( i > 0 )
//    {
//        while (i-1)
//        {
//            tmp += list.at(i) + sep ;
//            i-- ;
//        }
//        tmp += list.at(i) ;
//    }
    return tmp ;
}

QList<movie_class> file::mlistcontains(QString n)
{
    QList<movie_class> tmp ;
    for (auto x = my_imdb_class.begin() ; x != my_imdb_class.end() ;++x)
    {
        if (x->contains(n))
            tmp.push_back(*x) ;
    }
    return tmp;
}

QList<User> file::ulistcontains(QString n)
{
    QList<User> tmp ;
    for (auto x = my_user.begin() ; x != my_user.end() ;++x)
    {
        if (x->contains(n))
            tmp.push_back(*x) ;
    }
    return tmp;
}

void file::remove_user(QString username)
{
    int i=0 ;
    for (auto x = my_imdb_class.begin() ; x != my_imdb_class.end() ;++x , i++)
    {
        if (x->contains(username))
            my_user.removeAt(i) ;
    }
}

void file::remove_movie(QString ID)
{
    int i=0 ;
    for (auto x = my_imdb_class.begin() ; x != my_imdb_class.end() ; ++x,i++)
    {
        if (x->contains(ID))
            my_imdb_class.removeAt(i) ;
    }
}


file::file()
{

}

void file::edit_movie(movie_class tmp)
{
    for (auto x = my_imdb_class.begin() ; x != my_imdb_class.end() ;++x)
    {
        if (x->contains(tmp.getID()))
            *x = tmp ;
    }
}

void file::edit_user(User tmp)
{
    for (auto x = my_user.begin() ; x != my_user.end() ;++x)
    {
        if (x->contains(tmp.getUsername()))
            *x = tmp ;
    }
}

QVector<movie_class> file::sort_movie()
{
    QVector<movie_class> tmp = my_imdb_class.toVector() ;
    for (int i=0 ; i<tmp.size() ; i++)
        for (int j=0 ; j<tmp.size()-i-1 ; j++)
        {
            if (  tmp.at(j).getAverageRating() > tmp.at(j+1).getAverageRating())
            {
                tmp.swapItemsAt(j , j+1) ;
            }
        }
    return tmp;
    //    auto iia=my_imdb_class.cbegin() ;
    //    for (auto ito = this->my_imdb_class.begin() ; ito  != my_imdb_class.end() ; ++ito )
    //        for ( auto itto = this->my_imdb_class.begin() ; itto  != iia ; ++itto, ++iia)
    //        {
    //            if ( *itto > *(++itto) )
    //            {
    //                movie_class x = *(++itto) ;
    //                *(++itto) = *itto ;
    //                *itto = x ;
    //            }
    //        }
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
