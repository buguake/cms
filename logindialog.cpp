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

    connect(ui->checkinbutton, &QPushButton::clicked, this, &LoginDialog::on_checkinbutton_click);

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
        Student = new student(0, ID, password);
        /*
        Student->stud.SetID(ID);
        Student->stud.SetPassword(password.c_str());
        */
        // @ST
        Student->stud.SetType("student");
        if(Student->stud.Login()){
          QDialog::accept();
        }
    }
    else if(ui->teacherradio->isChecked()){
        Teacher = new teacher;
        Teacher->teac.SetID(ID);
        Teacher->teac.SetPassword(password.c_str());
        if(Teacher->teac.Login()){
          QDialog::done(2);
        }
    }
    else if(ui->managerradio->isChecked()){
        Manager = new manager;
        Manager->admi.SetID(ID);
        Manager->admi.SetPassword(password.c_str());
        if(Manager->admi.Login()){
            QDialog::done(3);
        }
    }
}
