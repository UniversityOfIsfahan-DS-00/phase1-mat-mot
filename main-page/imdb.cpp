#include "imdb.h"
#include "ui_imdb.h"

IMDB::IMDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMDB)
{
    ui->setupUi(this);
    this->data.load();
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

