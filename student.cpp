#include "student.h"
#include "ui_student.h"
#include "QTableWidgetItem"
#include "QCheckBox"
#include "QHBoxLayout"
#include "QWidget"
#include "QDebug"
#include "QMessageBox"
#include"section.h"

//int a = 0;  // what the hell ?
student::student(QWidget *parent, int ID, const string &password) :
    QMainWindow(parent), stud(ID, password),
    ui(new Ui::student)
{

    ui->setupUi(this);
    connect(ui->mycoursewidget, SIGNAL(cellClicked(int,int)), this, SLOT(on_mycoursewidget_click(int,int)));
    connect(ui->searchbutton, SIGNAL(clicked()), this, SLOT(on_searchbutton_click()));
    connect(ui->selectcoursewidget, SIGNAL(cellClicked(int,int)), this, SLOT(on_selectcoursewidget_click(int,int)));

 /***********查看课程部分***********/
    int i,j,row,column=9;
    row=stud.ViewMyCourses();
    ui->mycoursewidget->setColumnCount(column);
    ui->mycoursewidget->setRowCount(row);
    ui->mycoursewidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"开课院系"<< "学分" << "开课号"<< "学季"<<"学年"<<"成绩"<<"是否退课");

    for(i=0;i<row;i++){
        j=0;
        ui->mycoursewidget->setItem(i,0,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        //使（i，0）这个位置的item不能修改（注意，设置为不能修改的这个坐标的item必须存在
        // ，你可以试着把for循环的i<10改为i<20，因为这个表格最多有10行所以会报错）
        ui->mycoursewidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,1,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,2,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,3,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,4,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,5,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,6,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,6)->setFlags(Qt::NoItemFlags);
        ui->mycoursewidget->setItem(i,7,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->mycoursewidget->item(i,7)->setFlags(Qt::NoItemFlags);
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->mycoursewidget->setItem(i,8,check);
    }
    stud.Sresult.clear();
    /*********网上选课部分**********/
    QStringList key;
    key << "课程号" << "课程名称";
    ui->comboBox->insertItems(1, key);

    ui->selectcoursewidget->setColumnCount(14);
   // ui->selectcoursewidget->setRowCount(10);//这句话是必须的，可以填梓敏传回的记录的个数
    ui->selectcoursewidget->setHorizontalHeaderLabels(QStringList() << "课程号" <<"课程名"<<"学分"<< "开课号" << "学季"<< "学年"<<"容量"<<"余量"<<"教学楼"<<"教室号"<<"上课日期"<<"开始时间"<<"结束时间"<<"是否选课");
}

student::~student()
{
    delete ui;
}



void student::on_mycoursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int courseid,secid,year;
    string semester;
    qDebug()<<col;
    if(col==8){
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
                temp=ui->mycoursewidget->item(row,4);
                secid = temp->text().toInt();
                qDebug()<<courseid;
                temp=ui->mycoursewidget->item(row,5);
                semester = temp->text().toStdString();
                qDebug()<<semester.c_str();
                temp=ui->mycoursewidget->item(row,6);
                year = temp->text().toInt();
                qDebug()<<year;
                Section sec(courseid,secid,semester,year);
                int status=stud.Drops(sec);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("退课成功！"),QMessageBox::Ok);
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("退课失败！"),QMessageBox::Ok);
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

void student::on_selectcoursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int courseid,secid,year;
    string semester;
    if(col==13){//如果他是最后一列选课，才需要跳出对话框
        QMessageBox msgBox;
        msgBox.setText("你确定选这门课吗？");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->selectcoursewidget->item(row,0);
                courseid = temp->text().toInt();
                qDebug()<<courseid;
                temp=ui->selectcoursewidget->item(row,3);
                secid = temp->text().toInt();
                temp=ui->selectcoursewidget->item(row,4);
                semester = temp->text().toStdString();
                temp=ui->selectcoursewidget->item(row,5);
                year = temp->text().toInt();
                Section sec(courseid,secid,semester,year);
                int status=stud.Takes(sec);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("选课成功！"),QMessageBox::Ok);
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("选课失败！"),QMessageBox::Ok);
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

void student::on_searchbutton_click(){
    int i,j;
    QString key;
    QString content;
    int ID;
    string title;
    bool ok;
    int row;
    key=ui->comboBox->currentText();
    content=ui->lineEdit->text();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    if(key=="课程号"){
        ID=content.toInt(&ok,10);
        row=stud.SearchSection(ID);
    }
    else{
        title=content.toStdString();
        row=stud.SearchSection(title);
    }
    ui->selectcoursewidget->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int column = 14;
    for(i=0;i<row;i++){
        j=0;
        ui->selectcoursewidget->setItem(i,0,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,1,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,1)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,2,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,2)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,3,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,3)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,4,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,4)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,5,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,5)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,6,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,6)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,7,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,7)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,8,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,8)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,9,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,9)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,10,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,10)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,11,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,11)->setFlags(Qt::NoItemFlags);
        ui->selectcoursewidget->setItem(i,12,new QTableWidgetItem(stud.Sresult[i * (column - 1) + (j++)]));
        ui->selectcoursewidget->item(i,12)->setFlags(Qt::NoItemFlags);

        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        check->setTextAlignment(Qt::AlignCenter);
        ui->selectcoursewidget->setItem(i,13,check);
    }
    stud.Sresult.clear();
}
