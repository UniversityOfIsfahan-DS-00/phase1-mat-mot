#include "process.h"
#include "ui_process.h"

double process::round_1d(double x)
{
    x *= 10 ;
    x = (int)x ;
    return x/10;
}

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
    ui->accedit_newpassechomod->hide();
    ui->accedit_newpassagainechomod->hide();
    QRegularExpression rx("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->signup_emai->setValidator(new QRegularExpressionValidator(rx,this));
    QRegularExpression r("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b",QRegularExpression::CaseInsensitiveOption);
    ui->accedit_email->setValidator(new QRegularExpressionValidator(r,this));
    ui->signin_gbox->hide();
    ui->signup_gbox->hide();
    ui->accountedit_gbox->hide();
    ui->vote_gbox->hide();

}


process::~process()
{
    delete ui;
}

void process::setpos(QString type)
{
    if (type == "Vote")
    {
        ui->vote_gbox->show();
        ui->vote_id->setText(current_movie.getID());
        ui->vote_title->setText(current_movie.getTitle());
        ui->vote_avaragerating->setText(QString::number(current_movie.getAverageRating())) ;
    }
    else if (type == "sign in")
    {
        ui->signin_gbox->show();

    }
    else if (type == "sign up")
    {
        ui->signup_gbox->show();
    }
    else if (type == "account edit")
    {
        ui->accountedit_gbox->show() ;
        ui->accedit_username->setText(current_user.getUsername());
        ui->accedit_email->setText(current_user.getEmail()) ;
        ui->accedit_name->setText(current_user.getName());
    }
}

void process::on_signin_forgetpasscheckbox_clicked(bool checked)
{
    if (checked)
    {
        ui->signin_password->hide();
        ui->signin_email->show() ;
        ui->signin_passechomod->hide();
        ui->signin_signinbtn->setText("Varify") ;
        ui->signin_lable->show();
    }
    else
    {
        ui->signin_password->show();
        ui->signin_email->hide() ;
        ui->signin_signinbtn->setText("Sign in") ;
        ui->signin_lable->hide() ;
        ui->signin_passechomod->show();
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
        ui->accedit_newpassechomod->show();
        ui->accedit_newpassagainechomod->show();
    }
    else
    {
        ui->accedit_newpassword->hide();
        ui->accedit_newpasswordagain->hide();
        ui->accedit_newpasswordagainlable->hide();
        ui->accedit_newpasswordlable->hide();
        ui->accedit_newpassechomod->hide();
        ui->accedit_newpassagainechomod->hide();
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
    if ( (*child_d).ulistcontains(ui->signup_username->text()).size() != 0)
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
    (*child_d).my_user.push_front(tmp) ;
    QMessageBox::information(this , "registered" , "your sign up was successful now you can sign in .");
    ui->signin_gbox->close() ;
    ui->signup_username->clear() ;
    ui->signup_password->clear() ;
    ui->signup_emai->clear() ;
    ui->signup_name->clear() ;
    ui->signu_passwordagain->clear() ;
    ui->signup_gbox->hide();
    ui->signin_gbox->show() ;
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

const User &process::getCurrent_user() const
{
    return current_user;
}

void process::setCurrent_user(const User &newCurrent_user)
{
    current_user = newCurrent_user;
}

file *process::getChild_d() const
{
    return child_d;
}

void process::setChild_d(file *newChild_d)
{
    child_d = newChild_d;
}


void process::on_signin_signinbtn_clicked()
{
    if (!ui->signin_forgetpasscheckbox->isChecked())
    {
        if (ui->signin_username->text().isEmpty() || ui->signin_password->text().isEmpty())
        {
            QMessageBox::information(this , "faild" , "please fill in the blanks !") ;
            return;
        }
        User tmp , tp ;
        tmp.setUsername(ui->signin_username->text()) ;
        tmp.setHpassword(qHash(ui->signin_password->text())) ;
        tp = (*child_d).ulistcontains(ui->signin_username->text()).at(0) ;
        if (tp.getUsername() != tmp.getUsername() || tp.getHpassword() != tmp.getHpassword())
        {
            //ui->infolbldetail->setText("your user or pass dose not correct !!") ;
            QMessageBox::information(this , "login" , "user or password was wrong please try again :-) ") ;
            ui->signin_password->clear() ;
            return;
        }
        QMessageBox::information(this , "login" , "successfull !") ;
        current_user = tp ;
        this->close() ;
    }
    else
    {
        if (ui->signin_email->text().isEmpty()||ui->signin_username->text().isEmpty())
        {
            QMessageBox::information(this , "faild" , "please fill in the blanks !") ;
            return;
        }
        User tmp , tp ;
        tmp.setUsername(ui->signin_username->text()) ;
        tmp.setEmail(ui->signin_email->text()) ;
        tp = (*child_d).ulistcontains(ui->signin_username->text()).at(0) ;
        if (tp.getUsername() != tmp.getUsername() || tp.getEmail() != tmp.getEmail())
        {
            QMessageBox::information(this , "faild" , "your user or email dose not exist !!") ;
            return;
        }
        QMessageBox::information(this , "recovery" , "we send new password to your email plaese login again") ;
        ui->signin_username->clear() ;
        ui->signin_email->clear() ;
        ui->signin_password->clear() ;
        ui->signin_forgetpasscheckbox->setChecked(false) ;
    }
}


void process::on_signin_cancelbtn_clicked()
{
    this->close() ;
}


void process::on_signin_passechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->signin_password->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->signin_password->setEchoMode(QLineEdit::Password) ;
    }
}


void process::on_signup_passechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->signup_password->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->signup_password->setEchoMode(QLineEdit::Password) ;
    }
}


void process::on_signup_passagainechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->signu_passwordagain->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->signu_passwordagain->setEchoMode(QLineEdit::Password) ;
    }
}


void process::on_accedit_passechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->accedit_password->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->accedit_password->setEchoMode(QLineEdit::Password) ;
    }
}


void process::on_accedit_newpassechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->accedit_newpassword->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->accedit_newpassword->setEchoMode(QLineEdit::Password) ;
    }
}


void process::on_accedit_newpassagainechomod_clicked(bool checked)
{
    if (checked)
    {
        ui->accedit_newpasswordagain->setEchoMode(QLineEdit::Normal) ;
    }
    else
    {
        ui->accedit_newpasswordagain->setEchoMode(QLineEdit::Password) ;
    }
}

const movie_class &process::getCurrent_movie() const
{
    return current_movie;
}

void process::setCurrent_movie(const movie_class &newCurrent_movie)
{
    current_movie = newCurrent_movie;
}


void process::on_vote_cancelbtn_clicked()
{
    this->close() ;
}


void process::on_vote_confirmbtn_clicked()
{
    int ret = QMessageBox :: critical(this , "close" , "are you sure ???\nyou can't vote again!!" , "yes"  ,"cansel");
    if (ret == 0)
    {
        int i= ui->vote_spinbox->value() ;
        double tt = current_movie.getAverageRating()*current_movie.getNumvotes() ;
        tt = (tt + (i) )/(current_movie.getNumvotes()+1) ;
        current_movie.setAverageRating(round_1d(tt)) ;
        current_movie.setNumvotes(current_movie.getNumvotes()+1) ;
        QStringList ttt =  current_user.getVotedlist() ;
        ttt.push_back(ui->vote_id->text()) ;
        current_user.setVotedlist(ttt) ;
        this->close();
    }
    else if (ret ==1)
    {
        return;
    }
}


void process::on_accedit_cancelbtn_clicked()
{
    this->close();
}


void process::on_accedit_confirmbtn_clicked()
{
    if (ui->accedit_password->text().isEmpty()|| ui->accedit_name->text().isEmpty()||ui->accedit_email->text().isEmpty())
    {
        QMessageBox::information(this , "failed" , "please fill the blanks !!");
        return;
    }
    if (ui->accedit_changepass->isChecked()&&(ui->accedit_newpassword->text().isEmpty()||ui->accedit_newpasswordagain->text().isEmpty()))
    {
        QMessageBox::information(this , "failed" , "please fill the blanks !!");
        return;
    }
    long long a = qHash(ui->accedit_password->text());
    long long b = child_d->ulistcontains(ui->accedit_username->text()).at(0).getHpassword() ;
    if ( a != b)
    {
        QMessageBox::information(this , "edit" , "password is not corect try again !") ;
        return;
    }
    if (ui->accedit_newpassword->text()!=ui->accedit_newpasswordagain->text())
    {
        QMessageBox::information(this , "failed", "the new passwords does not match !");
        return;
    }
    current_user.setEmail(ui->accedit_email->text());
    current_user.setName(ui->accedit_name->text());
    if (ui->accedit_changepass->isChecked())
    {
        current_user.setHpassword(qHash( ui->accedit_newpassword->text()));
    }
    QMessageBox::information(this , "done" , "edit was successful !");
    this->close();
}

