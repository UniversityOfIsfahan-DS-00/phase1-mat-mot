#ifndef MOVIE_CLASS_H
#define MOVIE_CLASS_H
#include <QString>
#define ll long long
#include <QStringList>
class movie_class
{
    QString ID ;
    ll ordering ;
    QString title ;
    QString region ;
    QString language ;
    QStringList type ;
    QStringList attributes ;
    bool isorginaltitle ;
    double averageRating ;
    ll numvotes ;
public:
    movie_class();
    bool operator > (movie_class tmp) ;
    const QString &getID() const;
    void setID(const QString &newID);
    long long getOrdering() const;
    void setOrdering(long long newOrdering);
    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
    const QString &getRegion() const;
    void setRegion(const QString &newRegion);
    const QString &getLanguage() const;
    void setLanguage(const QString &newLanguage);
    const QStringList &getType() const;
    void setType(const QStringList &newType);
    const QStringList &getAttributes() const;
    void setAttributes(const QStringList &newAttributes);
    bool getIsorginaltitle() const;
    void setIsorginaltitle(bool newIsorginaltitle);
    double getAverageRating() const;
    void setAverageRating(double newAverageRating);
    long long getNumvotes() const;
    void setNumvotes(long long newNumvotes);
    bool contains (QString n) ;
};

#endif // MOVIE_CLASS_H
