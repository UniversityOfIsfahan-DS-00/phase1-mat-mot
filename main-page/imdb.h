#ifndef IMDB_H
#define IMDB_H

#include <QMainWindow>
#include "class-source/file_class.h"
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QHash>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class IMDB; }
QT_END_NAMESPACE

class IMDB : public QMainWindow
{
    Q_OBJECT

public:
    IMDB(QWidget *parent = nullptr);
    ~IMDB();

    const file &getData() const;
    void setData(const file &newData);
    void setlist () ;

private:
    Ui::IMDB *ui;
    file data ;

};
#endif // IMDB_H
