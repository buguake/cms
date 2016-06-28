#include "manager.h"
#include "ui_manager.h"
#include "QTableWidgetItem"
#include "QCheckBox"
#include "QHBoxLayout"
#include "QWidget"
#include "QDebug"
#include "QMessageBox"

manager::manager(QWidget *parent, int ID, const string &password) :
    QMainWindow(parent), admi(ID, password),
    ui(new Ui::manager)
{

    ui->setupUi(this);
    connect(ui->student_add_button,SIGNAL(clicked()),this,SLOT(on_studentaddbutton_click()));
    connect(ui->student_sear_button,SIGNAL(clicked(bool)),this,SLOT(on_studentsearchbutton_click()));
    connect(ui->student_table,SIGNAL(cellClicked(int,int)),this,SLOT(on_studentwidget_click(int,int)));
    connect(ui->teacher_add_button,SIGNAL(clicked()),this,SLOT(on_teacheraddbutton_click()));
    connect(ui->teacher_ser_button,SIGNAL(clicked(bool)),this,SLOT(on_teachersearchbutton_click()));
    connect(ui->teacher_table,SIGNAL(cellClicked(int,int)),this,SLOT(on_teacherwidget_click(int,int)));
    connect(ui->mana_add,SIGNAL(clicked()),this,SLOT(on_admaddbutton_click()));
    connect(ui->mana_sear_button,SIGNAL(clicked(bool)),this,SLOT(on_admsearchbutton_click()));
    connect(ui->mana_table,SIGNAL(cellClicked(int,int)),this,SLOT(on_admwidget_click(int,int)));
    connect(ui->course_add_button,SIGNAL(clicked()),this,SLOT(on_courseaddbutton_click()));
    connect(ui->course_ser_button,SIGNAL(clicked(bool)),this,SLOT(on_coursesearchbutton_click()));
    connect(ui->course_table,SIGNAL(cellClicked(int,int)),this,SLOT(on_coursewidget_click(int,int)));
    connect(ui->sec_add_button,SIGNAL(clicked()),this,SLOT(on_sectionaddbutton_click()));
    connect(ui->sec_sear_button,SIGNAL(clicked(bool)),this,SLOT(on_sectionsearchbutton_click()));
    connect(ui->sec_table,SIGNAL(cellClicked(int,int)),this,SLOT(on_sectionwidget_click(int,int)));

    ui->student_table->setColumnCount(7);
    ui->student_table->setHorizontalHeaderLabels(QStringList()<<"学生账号"<<"姓名"<<"性别"<<"生日"<<"所属院系"<<"是否更新"<<"是否删除");

    ui->teacher_table->setColumnCount(5);
    ui->teacher_table->setHorizontalHeaderLabels(QStringList()<<"老师账号"<<"姓名"<<"所属院系"<<"是否更新"<<"是否删除");

    ui->mana_table->setColumnCount(5);
    ui->mana_table->setHorizontalHeaderLabels(QStringList()<<"管理员账号"<<"姓名"<<"所属院系"<<"是否更新"<<"是否删除");

    ui->course_table->setColumnCount(6);
    ui->course_table->setHorizontalHeaderLabels(QStringList()<<"课程号"<<"课程名"<<"开课院系"<<"学分"<<"是否更新"<<"是否删除");

    ui->sec_table->setColumnCount(11);
    ui->sec_table->setHorizontalHeaderLabels(QStringList()<<"课程号"<<"教学班号"<<"学期"<<"学年"<<"容量"<<"余量"<<"教学楼"<<"房间号"<<"教学时间" << "是否更新" << "是否删除");
}

manager::~manager()
{
    delete ui;
}

void manager::on_studentaddbutton_click(){
    int ID;
    string name,birthday,gender,deptname;
    ID=ui->student_ID->text().toInt();
    name=ui->student_name->text().toStdString();
    birthday=ui->student_birthday->text().toStdString();
    gender=ui->student_gender->text().toStdString();
    deptname=ui->student_dept->text().toStdString();
    UStudent stu(ID,"******",name,deptname,birthday,gender);
    bool status=admi.AddStudent(stu);
    if(status){
        QMessageBox::information(this,tr("提示"),tr("增加学生成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("增加学生失败"),QMessageBox::Ok);
    }
}

void manager::on_studentsearchbutton_click(){
    int ID,row;
    ID=ui->student_ser_ID->text().toInt();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    row=admi.FindStudent(ID);
    ui->student_table->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int i, j;
    for(i=0;i<row;i++){
        j=0;
        ui->student_table->setItem(i,0,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->student_table->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->student_table->setItem(i,1,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->student_table->setItem(i,2,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->student_table->setItem(i,3,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->student_table->setItem(i,4,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));

        QTableWidgetItem *check1 = new QTableWidgetItem();
        check1->setCheckState(Qt::Unchecked);
        check1->setTextAlignment(Qt::AlignCenter);
        ui->student_table->setItem(i,5,check1);

        QTableWidgetItem *check2 = new QTableWidgetItem();
        check2->setCheckState(Qt::Unchecked);
        check2->setTextAlignment(Qt::AlignCenter);
        ui->student_table->setItem(i,6,check2);
    }
    admi.Aresult.clear();
}

void manager::on_studentwidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int ID;
    string name,birthday,gender,deptname;
    if(col==5){
        QMessageBox msgBox;
        msgBox.setText("您确定更新学生信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->student_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->student_table->item(row,1);
                name = temp->text().toStdString();
                temp=ui->student_table->item(row,2);
                birthday = temp->text().toStdString();
                temp=ui->student_table->item(row,3);
                gender = temp->text().toStdString();
                temp=ui->student_table->item(row,4);
                deptname = temp->text().toStdString();
                UStudent stu(ID,"******",name,deptname,birthday,gender);
                bool status=admi.UpdateStudent(stu);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("更新学生信息成功！"),QMessageBox::Ok);
                    on_studentsearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("更新学生信息失败"),QMessageBox::Ok);
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
    else if(col==6){
        QMessageBox msgBox;
        msgBox.setText("您确定删除学生信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
            temp=ui->student_table->item(row,0);
            ID = temp->text().toInt();
            temp=ui->student_table->item(row,1);
            name = temp->text().toStdString();
            temp=ui->student_table->item(row,2);
            birthday = temp->text().toStdString();
            temp=ui->student_table->item(row,3);
            gender = temp->text().toStdString();
            temp=ui->student_table->item(row,4);
            deptname = temp->text().toStdString();
            UStudent stu(ID,"******",name,deptname,birthday,gender);
            bool status=admi.RemoveStudent(stu);
            if(status){
                QMessageBox::information(this,tr("提示"),tr("删除学生信息成功！"),QMessageBox::Ok);
                on_studentsearchbutton_click();
                break;
            }
            else{
                QMessageBox::information(this,tr("提示"),tr("删除学生信息失败"),QMessageBox::Ok);
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

void manager::on_teacheraddbutton_click(){
    int ID;
    string name,deptname;
    ID=ui->teacher_ID->text().toInt();
    name=ui->teacher_name->text().toStdString();
    deptname=ui->teacher_dept->text().toStdString();
    UTeacher tea(ID,"******",name,deptname);
    bool status=admi.AddTeacher(tea);
    if(status){
        QMessageBox::information(this,tr("提示"),tr("增加老师成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("增加老师失败"),QMessageBox::Ok);
    }
}

void manager::on_teachersearchbutton_click(){
    int ID,row;
    ID=ui->teacher_ser_id->text().toInt();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    row=admi.FindTeacher(ID);
    ui->teacher_table->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int i, j;
    for(i=0;i<row;i++){
        j=0;
        ui->teacher_table->setItem(i,0,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->teacher_table->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->teacher_table->setItem(i,1,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->teacher_table->setItem(i,2,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));

        QTableWidgetItem *check1 = new QTableWidgetItem();
        check1->setCheckState(Qt::Unchecked);
        check1->setTextAlignment(Qt::AlignCenter);
        ui->teacher_table->setItem(i,3,check1);

        QTableWidgetItem *check2 = new QTableWidgetItem();
        check2->setCheckState(Qt::Unchecked);
        check2->setTextAlignment(Qt::AlignCenter);
        ui->teacher_table->setItem(i,4,check2);
    }
    admi.Aresult.clear();
}

void manager::on_teacherwidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int ID;
    string name,deptname;
    if(col==3){
        QMessageBox msgBox;
        msgBox.setText("您确定更新教师信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->teacher_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->teacher_table->item(row,1);
                name = temp->text().toStdString();
                temp=ui->teacher_table->item(row, 2);
                deptname = temp->text().toStdString();
                UTeacher tea(ID,"******",name,deptname);
                bool status=admi.UpdateTeacher(tea);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("更新老师信息成功！"),QMessageBox::Ok);
                    on_teachersearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("更新老师信息失败"),QMessageBox::Ok);
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
    else if(col==4){
        QMessageBox msgBox;
        msgBox.setText("您确定删除教师信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->teacher_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->teacher_table->item(row,1);
                name = temp->text().toStdString();
                temp=ui->teacher_table->item(row, 2);
                deptname = temp->text().toStdString();
                UTeacher tea(ID,"******",name,deptname);
                bool status=admi.RemoveTeacher(tea);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("删除老师信息成功！"),QMessageBox::Ok);
                    on_teachersearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("删除老师信息失败"),QMessageBox::Ok);
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

void manager::on_admaddbutton_click(){
    int ID;
    string name,deptname;
    ID=ui->manager_ID->text().toInt();
    name=ui->mana_name->text().toStdString();
    deptname=ui->man_dept->text().toStdString();
    Administrator adm(ID,"******",name,deptname);
    bool status=admi.AddAdministartor(adm);
    if(status){
        QMessageBox::information(this,tr("提示"),tr("增加管理员成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("增加管理员失败"),QMessageBox::Ok);
    }
}

void manager::on_admsearchbutton_click(){
    int ID,row;
    ID=ui->mana_id_sear->text().toInt();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    row=admi.FindAdministrator(ID);
    ui->mana_table->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int i, j;
    for(i=0;i<row;i++){
        j=0;
        ui->mana_table->setItem(i,0,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->mana_table->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->mana_table->setItem(i,1,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->mana_table->setItem(i,2,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));

        QTableWidgetItem *check1 = new QTableWidgetItem();
        check1->setCheckState(Qt::Unchecked);
        check1->setTextAlignment(Qt::AlignCenter);
        ui->mana_table->setItem(i,3,check1);

        QTableWidgetItem *check2 = new QTableWidgetItem();
        check2->setCheckState(Qt::Unchecked);
        check2->setTextAlignment(Qt::AlignCenter);
        ui->mana_table->setItem(i,4,check2);
    }
    admi.Aresult.clear();
}

void manager::on_admwidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int ID;
    string name,deptname;
    if(col==3){
        QMessageBox msgBox;
        msgBox.setText("您确定更新管理员信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->mana_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->mana_table->item(row,1);
                name = temp->text().toStdString();
                temp=ui->mana_table->item(row,2);
                deptname = temp->text().toStdString();
                Administrator adm(ID,"******",name,deptname);
                bool status=admi.UpdateAdministrator(adm);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("更新管理员信息成功！"),QMessageBox::Ok);
                    on_admsearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("更新管理员信息失败"),QMessageBox::Ok);
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
    else if(col==4){
        QMessageBox msgBox;
        msgBox.setText("您确定删除管理员信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->teacher_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->teacher_table->item(row,1);
                name = temp->text().toStdString();
                temp=ui->teacher_table->item(row,4);
                deptname = temp->text().toStdString();
                Administrator adm(ID,"******",name,deptname);
                bool status=admi.RemoveAdministartor(adm);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("删除管理员信息成功！"),QMessageBox::Ok);
                    on_admsearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("删除管理员信息失败"),QMessageBox::Ok);
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

void manager::on_courseaddbutton_click(){
    int ID;
    string title,deptname;
    double credits;
    ID=ui->course_id->text().toInt();
    title=ui->course_name->text().toStdString();
    deptname=ui->course_dept->text().toStdString();
    credits=ui->course_credits->text().toDouble();
    Course cou(ID,title,deptname,credits);
    bool status=admi.AddCourse(cou);
    if(status){
        QMessageBox::information(this,tr("提示"),tr("增加课程成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("增加课程失败"),QMessageBox::Ok);
    }
}

void manager::on_coursesearchbutton_click(){
    int ID,row;
    ID=ui->course_ser_id->text().toInt();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    row=admi.FindCourse(ID);
    ui->course_table->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int i, j;
    for(i=0;i<row;i++){
        j=0;
        ui->course_table->setItem(i,0,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->course_table->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->course_table->setItem(i,1,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->course_table->setItem(i,2,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->course_table->setItem(i,3,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));

        QTableWidgetItem *check1 = new QTableWidgetItem();
        check1->setCheckState(Qt::Unchecked);
        check1->setTextAlignment(Qt::AlignCenter);
        ui->course_table->setItem(i,4,check1);

        QTableWidgetItem *check2 = new QTableWidgetItem();
        check2->setCheckState(Qt::Unchecked);
        check2->setTextAlignment(Qt::AlignCenter);
        ui->course_table->setItem(i,5,check2);
    }
    admi.Aresult.clear();
}

void manager::on_coursewidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int ID;
    string title,deptname;
    double credits;
    if(col==4){
        QMessageBox msgBox;
        msgBox.setText("您确定更新课程信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->course_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->course_table->item(row,1);
                title = temp->text().toStdString();
                temp=ui->course_table->item(row,2);
                deptname = temp->text().toStdString();
                temp=ui->course_table->item(row,3);
                credits = temp->text().toDouble();
                Course cou(ID,title,deptname,credits);
                bool status=admi.UpdateCourse(cou);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("更新课程信息成功！"),QMessageBox::Ok);
                    on_coursesearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("更新课程信息失败"),QMessageBox::Ok);
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
    else if(col==5){
        QMessageBox msgBox;
        msgBox.setText("您确定删除课程信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->course_table->item(row,0);
                ID = temp->text().toInt();
                temp=ui->course_table->item(row,1);
                title = temp->text().toStdString();
                temp=ui->course_table->item(row,2);
                deptname = temp->text().toStdString();
                temp=ui->course_table->item(row,3);
                credits = temp->text().toDouble();
                Course cou(ID,title,deptname,credits);
                bool status=admi.RemoveCourse(cou);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("删除课程信息成功！"),QMessageBox::Ok);
                    on_coursesearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("删除课程信息失败"),QMessageBox::Ok);
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

void manager::on_sectionaddbutton_click(){
    int courseID,secID,year,capacity,roomno,timeslotid;
    string semester,building;
    courseID=ui->sec_courseid->text().toInt();
    secID=ui->sec_secid->text().toInt();
    year=ui->sec_year->text().toInt();
    capacity=ui->sec_capacity->text().toInt();
    roomno=ui->sec_roomno->text().toInt();
    timeslotid=ui->sec_time->text().toInt();
    semester=ui->sec_semester->text().toStdString();
    building=ui->sec_building->text().toStdString();
    Section sec(courseID,secID,semester,year,capacity,building,roomno,timeslotid);
    bool status=admi.AddSection(sec);
    if(status){
        QMessageBox::information(this,tr("提示"),tr("增加教学班成功！"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("增加教学班失败"),QMessageBox::Ok);
    }
}

void manager::on_sectionsearchbutton_click(){
    int courseID,secid,row;
    courseID=ui->sec_courseid_sear->text().toInt();
    secid=ui->sec_secid_ser->text().toInt();
    //麻烦梓敏写一段，通过key，content查询数据库得到课程信息
    row=admi.FindSection(courseID,secid);
    ui->sec_table->setRowCount(row);
    /*********下面是示意如何处理梓敏返回的字符串*******/
    int i, j;
    for(i=0;i<row;i++){
        j=0;
        ui->sec_table->setItem(i,0,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->item(i,0)->setFlags(Qt::NoItemFlags);
        ui->sec_table->setItem(i,1,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,2,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,3,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,4,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,5,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,6,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,7,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));
        ui->sec_table->setItem(i,8,new QTableWidgetItem(admi.Aresult[i*row+(j++)]));

        QTableWidgetItem *check1 = new QTableWidgetItem();
        check1->setCheckState(Qt::Unchecked);
        check1->setTextAlignment(Qt::AlignCenter);
        ui->sec_table->setItem(i,9,check1);

        QTableWidgetItem *check2 = new QTableWidgetItem();
        check2->setCheckState(Qt::Unchecked);
        check2->setTextAlignment(Qt::AlignCenter);
        ui->sec_table->setItem(i,10,check2);
    }
    admi.Aresult.clear();
}

void manager::on_sectionwidget_click(int row, int col)
{
    QTableWidgetItem* temp;
    int courseID,secID,year,capacity,roomno,timeslotid;
    string semester,building;
    if(col==9){
        QMessageBox msgBox;
        msgBox.setText("您确定更新教学班信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->sec_table->item(row,0);
                courseID = temp->text().toInt();
                temp=ui->sec_table->item(row,1);
                secID = temp->text().toInt();
                temp=ui->sec_table->item(row,2);
                semester=temp->text().toStdString();
                temp=ui->sec_table->item(row,3);
                year = temp->text().toInt();
                temp=ui->sec_table->item(row,4);
                capacity = temp->text().toInt();
                temp=ui->sec_table->item(row,5);
                //vacancy = temp->text().toInt();
                temp=ui->sec_table->item(row,6);
                building=temp->text().toStdString();
                temp=ui->sec_table->item(row,7);
                roomno = temp->text().toInt();
                temp=ui->sec_table->item(row,8);
                timeslotid = temp->text().toInt();
                Section sec(courseID,secID,semester,year,capacity,building,roomno,timeslotid);
                bool status=admi.UpdateSection(sec);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("更新教学班信息成功！"),QMessageBox::Ok);
                    on_sectionsearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("更新教学班信息失败"),QMessageBox::Ok);
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
    else if(col==10){
        QMessageBox msgBox;
        msgBox.setText("您确定删除教学班信息吗");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret=msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:{
                temp=ui->sec_table->item(row,0);
                courseID = temp->text().toInt();
                temp=ui->sec_table->item(row,1);
                secID = temp->text().toInt();
                temp=ui->sec_table->item(row,2);
                semester=temp->text().toStdString();
                temp=ui->sec_table->item(row,3);
                year = temp->text().toInt();
                temp=ui->sec_table->item(row,4);
                capacity = temp->text().toInt();
                temp=ui->sec_table->item(row,5);
                //vacancy = temp->text().toInt();
                temp=ui->sec_table->item(row,6);
                building=temp->text().toStdString();
                temp=ui->sec_table->item(row,7);
                roomno = temp->text().toInt();
                temp=ui->sec_table->item(row,8);
                timeslotid = temp->text().toInt();
                Section sec(courseID,secID,semester,year,capacity,building,roomno,timeslotid);
                bool status=admi.RemoveSection(sec);
                if(status){
                    QMessageBox::information(this,tr("提示"),tr("删除教学班信息成功！"),QMessageBox::Ok);
                    on_studentsearchbutton_click();
                    break;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("删除教学班信息失败"),QMessageBox::Ok);
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
