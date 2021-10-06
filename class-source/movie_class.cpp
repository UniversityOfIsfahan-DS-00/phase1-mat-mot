#include "movie_class.h"

const QString &movie_class::getID() const
{
    return ID;
}

void movie_class::setID(const QString &newID)
{
    ID = newID;
}

long long movie_class::getOrdering() const
{
    return ordering;
}

void movie_class::setOrdering(long long newOrdering)
{
    ordering = newOrdering;
}

const QString &movie_class::getTitle() const
{
    return title;
}

void movie_class::setTitle(const QString &newTitle)
{
    title = newTitle;
}

const QString &movie_class::getRegion() const
{
    return region;
}

void movie_class::setRegion(const QString &newRegion)
{
    region = newRegion;
}

const QString &movie_class::getLanguage() const
{
    return language;
}

void movie_class::setLanguage(const QString &newLanguage)
{
    language = newLanguage;
}

const QStringList &movie_class::getType() const
{
    return type;
}

void movie_class::setType(const QStringList &newType)
{
    type = newType;
}

const QStringList &movie_class::getAttributes() const
{
    return attributes;
}

void movie_class::setAttributes(const QStringList &newAttributes)
{
    attributes = newAttributes;
}

bool movie_class::getIsorginaltitle() const
{
    return isorginaltitle;
}

void movie_class::setIsorginaltitle(bool newIsorginaltitle)
{
    isorginaltitle = newIsorginaltitle;
}

double movie_class::getAverageRating() const
{
    return averageRating;
}

void movie_class::setAverageRating(double newAverageRating)
{
    averageRating = newAverageRating;
}

long long movie_class::getNumvotes() const
{
    return numvotes;
}

void movie_class::setNumvotes(long long newNumvotes)
{
    numvotes = newNumvotes;
}

bool movie_class::contains(QString n)
{
    if (this->ID.contains(n))
        return true;
    else if (this->title.contains(n))
        return true;
    return false;
}

movie_class::movie_class()
{
    this->ordering = 0 ;
    this->numvotes = 0 ;
    this->isorginaltitle = 0 ;
    this->averageRating = 0 ;
}
