#include "student_ui.h"
#include "ui_student.h"
#include "QTableWidgetItem"
#include "QCheckBox"
#include "QHBoxLayout"
#include "QWidget"
#include "QDebug"
#include "QMessageBox"

int a = 0;
student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{

    ui->setupUi(this);
    connect(ui->mycoursewidget, SIGNAL(cellClicked(int,int)), this, SLOT(on_mycoursewidget_click(int,int)));
    connect(ui->searchbutton, SIGNAL(clicked()), this, SLOT(on_searchbutton_click()));
    connect(ui->selectcoursewidget, SIGNAL(cellClicked(int,int)), this, SLOT(on_selectcoursewidget_click(int,int)));

    int i,j;
    /***********查看课程部分***********/
    ui->mycoursewidget->setColumnCount(8);
    ui->mycoursewidget->setRowCount(10);
    ui->mycoursewidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"任课老师"<< "教学班号" << "学期"<< "学年"<<"成绩"<<"是否退课");
    QString courseid="0001";
    QString coursename="微积分";
    QString teacher="苏德矿";
    QString secid="1";
    QString semester="春夏";
    QString year="2016";
    QString grade="95";
    for(i=0;i<10;i++){
        ui->mycoursewidget->setItem(i,0,new QTableWidgetItem(courseid));
        /*使（i，0）这个位置的item不能修改（注意，设置为不能修改的这个坐标的item必须存在
         ，你可以试着把for循环的i<10改为i<20，因为这个表格最多有10行所以会报错）*/
        ui->mycoursewidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,1,new QTableWidgetItem(coursename));
        ui->mycoursewidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,2,new QTableWidgetItem(teacher));
        ui->mycoursewidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,3,new QTableWidgetItem(secid));
        ui->mycoursewidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,4,new QTableWidgetItem(semester));
        ui->mycoursewidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,5,new QTableWidgetItem(year));
        ui->mycoursewidget->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,6,new QTableWidgetItem(grade));
        ui->mycoursewidget->item(i,6)->setFlags(Qt::NoItemFlags);
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->mycoursewidget->setItem(i,7,check);
    }

    /*********网上选课部分**********/
    QStringList key;
    key << "课程号" << "课程名称" << "教师姓名";
    ui->comboBox->insertItems(1, key);

    ui->selectcoursewidget->setColumnCount(7);
    ui->selectcoursewidget->setRowCount(10);//这句话是必须的，可以填梓敏传回的记录的个数
    ui->selectcoursewidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"任课老师"<< "教学班号" << "学期"<< "学年"<<"是否选课");
}

student::~student()
{
    delete ui;
}



void student::on_mycoursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int courseid,secid;
    qDebug()<<col;
    if(col==7){
        QMessageBox msgBox;
        msgBox.setText("你确定退这门课吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->mycoursewidget->item(row,0);
                courseid = temp->text().toInt();
                qDebug()<<courseid;
                temp=ui->mycoursewidget->item(row,3);
                secid = temp->text().toInt();
                break;
        }
          case QMessageBox::No:
                break;
          default:
              // should never be reached
              break;
        }
    }
}

void student::on_selectcoursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int courseid,secid;
    if(col==6){//如果他是最后一列选课，才需要跳出对话框
        QMessageBox msgBox;
        msgBox.setText("你确定选这门课吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->selectcoursewidget->item(row,0);
                courseid = temp->text().toInt();
                temp=ui->selectcoursewidget->item(row,3);
                secid = temp->text().toInt();
                break;
        }
          case QMessageBox::No:
                break;
          default:
              // should never be reached
              break;
        }
    }
}

void student::on_searchbutton_click(){
    int i;
    QString key;
    QString content;
    key=ui->comboBox->currentText();
    content=ui->lineEdit->text();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    /*********下面是示意如何处理梓敏返回的字符串*******/
    QString courseid="0001";
    QString coursename="微积分";
    QString teacher="苏德矿";
    QString secid="1";
    QString semester="春夏";
    QString year="2016";
    QString grade="95";
    for(i=0;i<10;i++){
        ui->selectcoursewidget->setItem(i,0,new QTableWidgetItem(key));
        ui->selectcoursewidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,1,new QTableWidgetItem(content));
        ui->selectcoursewidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,2,new QTableWidgetItem(teacher));
        ui->selectcoursewidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,3,new QTableWidgetItem(secid));
        ui->selectcoursewidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,4,new QTableWidgetItem(semester));
        ui->selectcoursewidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,5,new QTableWidgetItem(year));
        ui->selectcoursewidget->item(i,5)->setFlags(Qt::NoItemFlags);
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->selectcoursewidget->setItem(i,6,check);
    }
}

