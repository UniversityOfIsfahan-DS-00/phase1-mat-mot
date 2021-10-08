#ifndef PROCESS_H
#define PROCESS_H

#include <QDialog>
#include "class-source/file_class.h"
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QHash>
#include <QDebug>
#include <QListWidgetItem>
#include <QSharedPointer>
#include "class-source/user_class.h"
#include "class-source/movie_class.h"
#include <QStringList>
namespace Ui {
class process;
}

class process : public QDialog
{
    Q_OBJECT

public:
    double round_1d (double x ) ;
    explicit process(QWidget *parent = nullptr);
    ~process();

    void setpos (QString type) ;

    file *getChild_d() const;
    void setChild_d(file *newChild_d);

    const User &getCurrent_user() const;
    void setCurrent_user(const User &newCurrent_user);

    const movie_class &getCurrent_movie() const;
    void setCurrent_movie(const movie_class &newCurrent_movie);

private slots:
    void on_signin_forgetpasscheckbox_clicked(bool checked);

    void on_accedit_changepass_clicked(bool checked);

    void on_signup_signupbtn_clicked();

    void on_signup_cancelbtn_clicked();

    void on_accedit_email_textChanged();

    void on_signup_emai_textChanged();

    void on_signin_signinbtn_clicked();

    void on_signin_cancelbtn_clicked();

    void on_signin_passechomod_clicked(bool checked);

    void on_signup_passechomod_clicked(bool checked);

    void on_signup_passagainechomod_clicked(bool checked);

    void on_accedit_passechomod_clicked(bool checked);

    void on_accedit_newpassechomod_clicked(bool checked);

    void on_accedit_newpassagainechomod_clicked(bool checked);

    void on_vote_cancelbtn_clicked();

    void on_vote_confirmbtn_clicked();

    void on_accedit_cancelbtn_clicked();

    void on_accedit_confirmbtn_clicked();

private:
    Ui::process *ui;
    //file child_data ;
    User current_user ;
    movie_class current_movie ;
    file * child_d = nullptr ;
};

#endif // PROCESS_H
