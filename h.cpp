#include "h.h"
#include "ui_h.h"

h::h(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::h)
{
    ui->setupUi(this);
}

h::~h()
{
    delete ui;
}
