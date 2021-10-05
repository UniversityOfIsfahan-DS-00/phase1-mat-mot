#include "move_class.h"

const QString &move_class::getID() const
{
    return ID;
}

void move_class::setID(const QString &newID)
{
    ID = newID;
}

long long move_class::getOrdering() const
{
    return ordering;
}

void move_class::setOrdering(long long newOrdering)
{
    ordering = newOrdering;
}

const QString &move_class::getTitle() const
{
    return title;
}

void move_class::setTitle(const QString &newTitle)
{
    title = newTitle;
}

const QString &move_class::getRegion() const
{
    return region;
}

void move_class::setRegion(const QString &newRegion)
{
    region = newRegion;
}

const QString &move_class::getLanguage() const
{
    return language;
}

void move_class::setLanguage(const QString &newLanguage)
{
    language = newLanguage;
}

const QStringList &move_class::getType() const
{
    return type;
}

void move_class::setType(const QStringList &newType)
{
    type = newType;
}

const QStringList &move_class::getAttributes() const
{
    return attributes;
}

void move_class::setAttributes(const QStringList &newAttributes)
{
    attributes = newAttributes;
}

bool move_class::getIsorginaltitle() const
{
    return isorginaltitle;
}

void move_class::setIsorginaltitle(bool newIsorginaltitle)
{
    isorginaltitle = newIsorginaltitle;
}

double move_class::getAverageRating() const
{
    return averageRating;
}

void move_class::setAverageRating(double newAverageRating)
{
    averageRating = newAverageRating;
}

long long move_class::getNumvotes() const
{
    return numvotes;
}

void move_class::setNumvotes(long long newNumvotes)
{
    numvotes = newNumvotes;
}

bool move_class::contains(QString n)
{
    if (this->ID.contains(n))
        return true;
    else if (this->title.contains(n))
        return true;
    return false;
}

move_class::move_class()
{
    this->ordering = 0 ;
    this->numvotes = 0 ;
    this->isorginaltitle = 0 ;
    this->averageRating = 0 ;
}
