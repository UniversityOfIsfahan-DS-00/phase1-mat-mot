#ifndef IMDB_H
#define IMDB_H

#include <QMainWindow>
#include "source_class/source_class.h"
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QHash>
QT_BEGIN_NAMESPACE
namespace Ui { class IMDB; }
QT_END_NAMESPACE

class IMDB : public QMainWindow
{
    Q_OBJECT

public:
    IMDB(QWidget *parent = nullptr);
    ~IMDB();

    const source &getData() const;
    void setData(const source &newData);

private:
    Ui::IMDB *ui;
    source data ;
};
#endif // IMDB_H
