#include "imdb_class.h"

const QString &imdb_class::getID() const
{
    return ID;
}

void imdb_class::setID(const QString &newID)
{
    ID = newID;
}

long long imdb_class::getOrdering() const
{
    return ordering;
}

void imdb_class::setOrdering(long long newOrdering)
{
    ordering = newOrdering;
}

const QString &imdb_class::getTitle() const
{
    return title;
}

void imdb_class::setTitle(const QString &newTitle)
{
    title = newTitle;
}

const QString &imdb_class::getRegion() const
{
    return region;
}

void imdb_class::setRegion(const QString &newRegion)
{
    region = newRegion;
}

const QString &imdb_class::getLanguage() const
{
    return language;
}

void imdb_class::setLanguage(const QString &newLanguage)
{
    language = newLanguage;
}

const QString &imdb_class::getType() const
{
    return type;
}

void imdb_class::setType(const QString &newType)
{
    type = newType;
}

const QString &imdb_class::getAttributes() const
{
    return attributes;
}

void imdb_class::setAttributes(const QString &newAttributes)
{
    attributes = newAttributes;
}

bool imdb_class::getIsorginaltitle() const
{
    return isorginaltitle;
}

void imdb_class::setIsorginaltitle(bool newIsorginaltitle)
{
    isorginaltitle = newIsorginaltitle;
}

double imdb_class::getAverageRating() const
{
    return averageRating;
}

void imdb_class::setAverageRating(double newAverageRating)
{
    averageRating = newAverageRating;
}

long long imdb_class::getNumvotes() const
{
    return numvotes;
}

void imdb_class::setNumvotes(long long newNumvotes)
{
    numvotes = newNumvotes;
}

imdb_class::imdb_class()
{
    this->ordering = 0 ;
    this->numvotes = 0 ;
    this->isorginaltitle = 0 ;
    this->averageRating = 0 ;
}
