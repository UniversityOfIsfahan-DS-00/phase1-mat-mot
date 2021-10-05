#include "imdb.h"
#include "ui_imdb.h"
#include "process-page/process.h"
IMDB::IMDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMDB)
{
    ui->setupUi(this);
    if (!this->data.load() )
        QMessageBox::information(this , "Load" , "data can't load corectly !! open program again .") ;
    this->setlist() ;
    if (data.my_user.size()==0)
    {
        User tmp  ;
        QString n = "ADMIN" ;
        tmp.setName(n);
        tmp.setHpassword(qHash(n));
        tmp.setUsername(n);
        tmp.setEmail("ADMIN@ADMIN.com");
        data.my_user.push_back(tmp) ;
    }
    process * tmp = new process () ;
    tmp->open() ;
}

IMDB::~IMDB()
{
    this->data.save();
    delete ui;
}

const file &IMDB::getData() const
{
    return data;
}

void IMDB::setData(const file &newData)
{
    data = newData;
}

void IMDB::setlist()
{
    ui->title_list->addItems(data.items("move")) ;
}


void IMDB::on_search_box_textChanged(const QString &arg1)
{
    QList<move_class> tmp = data.mlistcontains(arg1) ;
    ui->title_list->clear() ;
    for (int i=0 ; i<tmp.size() ;i++)
        ui->title_list->addItem(tmp.at(i).getTitle() + " [" +tmp.at(i).getID() + "]") ;
}


void IMDB::on_actionExit_triggered()
{
    this->close() ;
}


void IMDB::on_actionCountact_Us_triggered()
{
    QString tmp ;
    tmp += "Phone number : 09015743537\nAddress : University of Isfahan , Ansar building\n" ;
    tmp += "Telegram ID : @Mat-Mot\nInstgram ID : matin_motmaen\n";
    tmp += "Git repo : https://github.com/mat-mot/ap-final-project.git\nEmail addres : matinmotmaen@gmail.com\n" ;
    tmp += "this program wrriten by mat-mot (*_*)" ;
    QMessageBox::information(this , "Contact Us" , tmp ) ;
}


void IMDB::on_actionSave_Data_triggered()
{
    if (data.save() )
        QMessageBox::information(this , "Save" , "your data seccesfully saved!") ;
}

