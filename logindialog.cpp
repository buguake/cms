#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPainter>
#include "QDebug"
#include"student.h"
#include"teacher.h"
#include"manager.h"

extern student Student;
extern teacher Teacher;
extern manager Manager;


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
    QString key=ui->passwordlineedit->text();
    book ok;
    int ID=name.toInt(&ok,10);
    string password=key.toStdString();

    if(ui->studentratdio->isChecked()){
        Student.stud(ID,password,"null","null");
        if(Student.stud.Login()){
          QDialog::accept();
        }
    }
    else if(ui->teacherradio->isChecked()){
        Teacher.teac(ID,password,"null","null");
        if(Teacher.teac.Login()){
          QDialog::done(2);
        }
    }
    else if(ui->managerradio->isChecked()){
        Manager.admi(ID,password,"null","null");
        if(Manager.admi.Login()){
            QDialog::done(3);
        }
    }
}






