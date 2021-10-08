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
#include "process-page/process.h"
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

    void on_actionVote_Movie_triggered();

    void on_actionLogin_triggered();

    void on_actionTop_10_triggered();

    void on_actionRefresh_triggered();

    void on_title_list_itemDoubleClicked();

    void on_actionLog_out_triggered();

    void on_actionSign_up_triggered();

    void on_actionEdit_triggered();

    void on_actionSign_in_triggered();

    void on_actionSort_base_rating_triggered();

    void on_refreshbtn_clicked();

private:
    Ui::IMDB *ui;
    file data ;
    User current_user ;

};
#endif // IMDB_H
