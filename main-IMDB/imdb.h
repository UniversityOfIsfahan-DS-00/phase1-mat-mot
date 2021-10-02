#ifndef IMDB_H
#define IMDB_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class IMDB; }
QT_END_NAMESPACE

class IMDB : public QMainWindow
{
    Q_OBJECT

public:
    IMDB(QWidget *parent = nullptr);
    ~IMDB();

private:
    Ui::IMDB *ui;
};
#endif // IMDB_H
