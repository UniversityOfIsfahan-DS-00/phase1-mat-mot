#include "imdb.h"
#include "ui_imdb.h"

IMDB::IMDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IMDB)
{
    ui->setupUi(this);
}

IMDB::~IMDB()
{
    delete ui;
}

const source &IMDB::getData() const
{
    return data;
}

void IMDB::setData(const source &newData)
{
    data = newData;
}

