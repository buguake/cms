#include "student.h"
#include <QApplication>
#include "logindialog.h"
#include "teacher.h"
#include "manager.h"
#include <QSqlDatabase>
#include <vector>
#include <iostream>
#define REMOTE_SERVER
using namespace std;

student *Student;
teacher *Teacher;
manager *Manager;

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
#ifdef REMOTE_SERVER
    db.setHostName("xjiajiahao.tk");
    db.setDatabaseName("cms");
    db.setUserName("cms");
    db.setPassword("1897");
    db.open();

#else
    db.setHostName("localhost");
    db.setDatabaseName("cms");
    db.setUserName("root");
    db.setPassword("1897");
#endif
    int ok = db.open();
    if (!ok)
    {
        std::cout << "Failed to connect to database, please check your network." << endl;
        return 1;
    }
    cout << "Connectd to database. " << endl;
    QApplication a(argc, argv);

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
