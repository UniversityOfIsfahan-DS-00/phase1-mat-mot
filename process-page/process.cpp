#include "process.h"
#include "ui_process.h"

process::process(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::process)
{
    ui->setupUi(this);
}

process::~process()
{
    delete ui;
}
