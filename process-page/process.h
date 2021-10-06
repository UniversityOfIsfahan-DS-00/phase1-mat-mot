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
#include <QStringList>
namespace Ui {
class process;
}

class process : public QDialog
{
    Q_OBJECT

public:
    explicit process(QWidget *parent = nullptr);
    ~process();

    const file &getChild_data() const;
    void setChild_data(const file &newChild_data);

    const User &getCurrent_user() const;
    void setCurrent_user(const User &newCurrent_user);

private slots:
    void on_signin_forgetpasscheckbox_clicked(bool checked);

    void on_accedit_changepass_clicked(bool checked);

    void on_signup_signupbtn_clicked();

    void on_signup_cancelbtn_clicked();

    void on_accedit_email_textChanged();

    void on_signup_emai_textChanged();

private:
    Ui::process *ui;
    file child_data ;
    User current_user ;
};

#endif // PROCESS_H
