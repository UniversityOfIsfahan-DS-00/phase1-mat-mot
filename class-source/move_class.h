#ifndef MOVE_CLASS_H
#define MOVE_CLASS_H
#include <QString>
#define ll long long

class move_class
{
    QString ID ;
    ll ordering ;
    QString title ;
    QString region ;
    QString language ;
    QString type ;
    QString attributes ;
    bool isorginaltitle ;
    double averageRating ;
    ll numvotes ;
public:
    move_class();
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
    const QString &getType() const;
    void setType(const QString &newType);
    const QString &getAttributes() const;
    void setAttributes(const QString &newAttributes);
    bool getIsorginaltitle() const;
    void setIsorginaltitle(bool newIsorginaltitle);
    double getAverageRating() const;
    void setAverageRating(double newAverageRating);
    long long getNumvotes() const;
    void setNumvotes(long long newNumvotes);
};

#endif // MOVE_CLASS_H
