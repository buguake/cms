#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include "QDebug"
#include"student.h"
#include"teacher.h"
#include"manager.h"

extern student *Student;
extern teacher *Teacher;
extern manager *Manager;


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    connect(ui->checkinbutton, SIGNAL(clicked()), this, SLOT(on_checkinbutton_click()));

    QPalette palette;
    palette.setColor(QPalette::WindowText, QColor(2,52,96));
    ui->title->setPalette(palette);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_checkinbutton_click(){
    QString name=ui->namelineedit->text();
    QString key=ui->passwordline->text();
    bool ok;
    int ID=name.toInt(&ok,10);
    string password=key.toStdString();

    if(ui->studentratdio->isChecked()){
        Student->stud.SetID(ID);
        Student->stud.SetPassword(password.c_str());
        if(Student->stud.Login()){
          QDialog::accept();
        }
    }
    else if(ui->teacherradio->isChecked()){
        Teacher->teac.SetID(ID);
        Teacher->teac.SetPassword(password.c_str());
        if(Teacher->teac.Login()){
          QDialog::done(2);
        }
    }
    else if(ui->managerradio->isChecked()){
        Manager->admi.SetID(ID);
        Manager->admi.SetPassword(password.c_str());
        if(Manager->admi.Login()){
            QDialog::done(3);
        }
    }
}






