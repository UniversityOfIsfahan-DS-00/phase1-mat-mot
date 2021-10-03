#include "imdb.h"
#include "ui_imdb.h"

IMDB::IMDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMDB)
{
    ui->setupUi(this);
    this->data.load();
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

