#include "student.h"
#include <QApplication>
#include "logindialog.h"
#include "teacher.h"
#include "manager.h"
#include <QSqlDatabase>
#include <vector>
#include <iostream>

using namespace std;

student *Student;
teacher *Teacher;
manager *Manager;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("cms");
    db.setUserName("jiahao.xie");
    db.setPassword("1897");
    db.open();

    QApplication a(argc, argv);
    Student = new student;
    Teacher = new teacher;
    Manager = new manager;
    LoginDialog logindialog;
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    logindialog.setPalette(palette);

    int check=logindialog.exec();

    if(check==1){
        Student->show();
    }
    else if(check==2){
        Teacher->show();
    }
    else if(check==3){
        Manager->show();
    }

    return a.exec();
}
