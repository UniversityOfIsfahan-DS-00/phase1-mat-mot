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

