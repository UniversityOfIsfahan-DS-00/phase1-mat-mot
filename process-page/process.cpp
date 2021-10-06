#include "process.h"
#include "ui_process.h"

process::process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::process)
{
    ui->setupUi(this);
    ui->signin_email->hide();
    ui->signin_lable->hide();
    ui->accedit_newpassword->hide();
    ui->accedit_newpasswordagain->hide();
    ui->accedit_newpasswordagainlable->hide();
    ui->accedit_newpasswordlable->hide();
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->signup_emai->setValidator(new QRegularExpressionValidator(rx,this));
    QRegularExpression r("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->accedit_email->setValidator(new QRegularExpressionValidator(r,this));

}


process::~process()
{
    delete ui;
}

void process::on_signin_forgetpasscheckbox_clicked(bool checked)
{
    if (checked)
    {
        ui->signin_password->hide();
        ui->signin_email->show() ;
        ui->signin_signinbtn->setText("Varify") ;
        ui->signin_lable->show();
    }
    else
    {
        ui->signin_password->show();
        ui->signin_email->hide() ;
        ui->signin_signinbtn->setText("Sign in") ;
        ui->signin_lable->hide() ;
    }
}


void process::on_accedit_changepass_clicked(bool checked)
{
    if (checked)
    {
        ui->accedit_newpassword->show();
        ui->accedit_newpasswordagain->show();
        ui->accedit_newpasswordagainlable->show();
        ui->accedit_newpasswordlable->show();
    }
    else
    {
        ui->accedit_newpassword->hide();
        ui->accedit_newpasswordagain->hide();
        ui->accedit_newpasswordagainlable->hide();
        ui->accedit_newpasswordlable->hide();
    }
}


void process::on_signup_signupbtn_clicked()
{
    if (ui->signup_password->text() != ui->signu_passwordagain->text())
    {
        ui->signup_password->clear() ;
        ui->signu_passwordagain->clear();
        QMessageBox ::information(this , "wrong" , "your password doesn't match fill again") ;
        return;
    }
    if (ui->signup_username->text() == child_data.ulistcontains(ui->signup_username->text()).at(0).getUsername())
    {
        QMessageBox::information(this , "warning" , "the user that you want to create already existed !!!") ;
        return  ;
    }
    if (ui->signup_emai->text().isEmpty() ||
            ui->signup_name->text().isEmpty()||
            ui->signup_username->text().isEmpty()||
            ui->signup_password->text().isEmpty() )
    {
        QMessageBox ::information(this , "error" , "please fill all blanks space !");
        return;
    }
    if (!ui->signup_emai->hasAcceptableInput())
    {
        QMessageBox::critical(this , "Email" , "not valid !") ;
        return;
    }
    User tmp ;
    tmp.setUsername(ui->signup_username->text());
    tmp.setHpassword(qHash(ui->signup_password->text()));
    tmp.setEmail(ui->signup_emai->text());
    tmp.setName(ui->signup_name->text());
    child_data.my_user.push_front(tmp) ;
    QMessageBox::information(this , "registered" , "your register was seccesful now you can login .");
    ui->signin_gbox->close() ;
    ui->signup_username->clear() ;
    ui->signup_password->clear() ;
    ui->signup_emai->clear() ;
    ui->signup_name->clear() ;
    ui->signu_passwordagain->clear() ;
    ui->signin_gbox->show() ;
}

const User &process::getCurrent_user() const
{
    return current_user;
}

void process::setCurrent_user(const User &newCurrent_user)
{
    current_user = newCurrent_user;
}

const file &process::getChild_data() const
{
    return child_data;
}

void process::setChild_data(const file &newChild_data)
{
    child_data = newChild_data;
}


void process::on_signup_cancelbtn_clicked()
{
    this->close();
}


void process::on_accedit_email_textChanged()
{
    if (ui->accedit_email->hasAcceptableInput())
        ui->accedit_email->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->accedit_email->setStyleSheet("QLineEdit {color : red}") ;
}


void process::on_signup_emai_textChanged()
{
    if (ui->signup_emai->hasAcceptableInput())
        ui->signup_emai->setStyleSheet("QLineEdit {color : black}") ;
    else
        ui->signup_emai->setStyleSheet("QLineEdit {color : red}") ;
}

