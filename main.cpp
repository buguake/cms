#include "student.h"
#include <QApplication>
#include "logindialog.h"
#include "teacher.h"
#include "manager.h"
#include <QSqlDatabase>
#include <vector>
#include <iostream>

using namespace std;

student Student;
LoginDialog logindialog;
teacher Teacher;
manager Manager;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("cms_master");
    db.setUserName("root");
    db.setPassword("LRrg970328");
    bool ok = db.open();

    QApplication a(argc, argv);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    logindialog.setPalette(palette);

    int check=logindialog.exec();

    if(check==1){
        Student.show();
    }
    else if(check==2){
        Teacher.show();
    }
    else if(check==3){
        Manager.show();
    }

    return a.exec();
}
