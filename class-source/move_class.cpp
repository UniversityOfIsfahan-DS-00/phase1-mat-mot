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

const QString &move_class::getType() const
{
    return type;
}

void move_class::setType(const QString &newType)
{
    type = newType;
}

const QString &move_class::getAttributes() const
{
    return attributes;
}

void move_class::setAttributes(const QString &newAttributes)
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

move_class::move_class()
{
    this->ordering = 0 ;
    this->numvotes = 0 ;
    this->isorginaltitle = 0 ;
    this->averageRating = 0 ;
}
