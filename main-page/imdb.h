#ifndef IMDB_H
#define IMDB_H

#include <QMainWindow>
#include "class-source/file_class.h"
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QHash>
#include <QDebug>
#include <QListWidgetItem>
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

private slots:
    void on_search_box_textChanged(const QString &arg1);

    void on_actionExit_triggered();

    void on_actionCountact_Us_triggered();

    void on_actionSave_Data_triggered();

    void on_title_list_itemClicked(QListWidgetItem *item);

private:
    Ui::IMDB *ui;
    file data ;
    User current_user ;

};
#endif // IMDB_H
