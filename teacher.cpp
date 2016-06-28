#include "teacher.h"
#include "ui_teacher.h"
#include "QTableWidgetItem"
#include "QCheckBox"
#include "QHBoxLayout"
#include "QWidget"
#include "QDebug"
#include "QMessageBox"
#include "user.h"
#include"section.h"

int a = 0;
teacher::teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher)
{

    ui->setupUi(this);
    connect(ui->tableWidget_2,SIGNAL(cellClicked(int,int)),this,SLOT(on_markcoursewidget_click(int,int)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_searchbuttonmark_click()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_searchbuttonselect_click()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(on_refresh_click()));

 /***********查看课程部分***********/
    int i,j,row,column=7;
    row=teac.ViewMyCourses();
    ui->tableWidget->setColumnCount(column);
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"开课院系"<< "学分" << "开课号"<< "学季"<<"学年");
    for(i=0;i<row;i++){
        j=0;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,6)->setFlags(Qt::NoItemFlags);
    }

    /*********查选课情况**********/

    ui->tableWidget_3->setColumnCount(8);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() <<"学生账号"<< "课程号" <<"课程名"<<"开课院系"<< "开课号" << "学季"<< "学年"<<"成绩");

    ui->tableWidget_2->setColumnCount(9);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() <<"学生账号"<< "课程号" <<"课程名"<<"开课院系"<< "开课号" << "学季"<< "学年"<<"成绩"<<"是否登分");
}

teacher::~teacher()
{
    delete ui;
}

void teacher::on_markcoursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int ID,courseid,secid,year;
    double grade;
    string semester;
    qDebug()<<col;
    if(col==8){
        QMessageBox msgBox;
        msgBox.setText("您确定登入成绩吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->tableWidget_2->item(row,0);
                ID = temp->text().toInt();
                temp=ui->tableWidget_2->item(row,1);
                courseid = temp->text().toInt();
                qDebug()<<courseid;
                temp=ui->tableWidget_2->item(row,4);
                secid = temp->text().toInt();
                qDebug()<<secid;
                temp=ui->tableWidget_2->item(row,5);
                semester = temp->text().toStdString();
                qDebug()<<semester.c_str();
                temp=ui->tableWidget_2->item(row,6);
                year = temp->text().toInt();
                qDebug()<<year;
                temp=ui->tableWidget_2->item(row,7);
                grade = temp->text().toDouble();
                qDebug()<<year;
                Section sec(courseid,secid,semester,year);
                bool status=teac.Marks(ID,sec,grade);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("登分成功！"),QMessageBox::Ok);
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("登分失败！"),QMessageBox::Ok);
                    break;
                }
        }
          case QMessageBox::No:
                break;
          default:
              // should never be reached
              break;
        }
    }
}

void teacher::on_searchbuttonmark_click(){
    int i,j;
    int course_id,sec_id;
    int row;
    course_id=ui->lineEdit_2->text().toInt();
    sec_id=ui->lineEdit->text().toInt();
    Section sec(course_id,sec_id);
    row=teac.ViewMyNewStudent(sec);
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    ui->tableWidget_3->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    for(i=0;i<row;i++){
        j=0;
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,4,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,5,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,6,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,6)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,7,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));

        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_2->setItem(i,8,check);
    }
    teac.Tresult.clear();
}

void teacher::on_searchbuttonselect_click(){
    int i,j;
    int course_id,sec_id;
    int row;
    course_id=ui->lineEdit_3->text().toInt();
    sec_id=ui->lineEdit_4->text().toInt();
    Section sec(course_id,sec_id);
    row=teac.ViewMyNewStudent(sec);
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    ui->tableWidget_3->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    for(i=0;i<row;i++){
        j=0;
        ui->tableWidget_3->setItem(i,0,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,1,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,2,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,3,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,4,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,5,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,6,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,6)->setFlags(Qt::NoItemFlags);
        ui->tableWidget_3->setItem(i,7,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget_3->item(i,7)->setFlags(Qt::NoItemFlags);
    }
    teac.Tresult.clear();
}

void teacher::on_refresh_click(){
    int i,j,row,column=7;
    row=teac.ViewMyCourses();
    ui->tableWidget->setColumnCount(column);
    ui->tableWidget->setRowCount(row);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"开课院系"<< "学分" << "开课号"<< "学季"<<"学年");
    for(i=0;i<row;i++){
        j=0;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(teac.Tresult[i*row+(j++)]));
        ui->tableWidget->item(i,6)->setFlags(Qt::NoItemFlags);
    }
    teac.Tresult.clear();
}
