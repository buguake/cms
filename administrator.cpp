#include "administrator.h"

//construtors for administrator
Administrator::Administrator(void)
        :User(-1, "******", "administrator", "null", "null"){}

Administrator::Administrator(const int ID, const string &password, const string &name, const string &deptname)
        :User(ID, password, "administrator", name, deptname){}

// administrator adds a student
bool Administrator::AddStudent(const UStudent &s) const
{
    /*insert a record into the student table*/

    QSqlQuery query;
    query.prepare("insert into Student (ID, name, birthday, gender, deptName) values (?, ?, ? ,?, ?)");
    query.addBindValue(s.GetID());
    query.addBindValue(s.GetName().data());
    query.addBindValue(QDateTime::fromString(QString::fromStdString(s.GetBirthday()), "yyyy-MM-dd"));
    if(!s.GetGender())
        query.addBindValue("male");
    else
        query.addBindValue("female");
    query.addBindValue(s.GetDeptName().data());

    if(!query.exec())
        return false;

    /*insert a record into the user table*/

    query.prepare("insert into User (ID, type, password) values (?, ?, ?)");
    query.addBindValue(s.GetID());
    query.addBindValue("student");
    query.addBindValue(s.GetPassword());

    if(!query.exec())
        return false;

    return true;
}

// administrator removes a student
bool Administrator::RemoveStudent(const UStudent &s) const
{
    /*delete a record from the student table*/

    QString str;
    str = "delete from Student where ID = ";
    str += QString::number(s.GetID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*delete a record from the user table*/

    str = "delete from User where ID = ";    //set the query sentence
    str += QString::number(s.GetID());
    str += " and type = 'student'";

    if(!query.exec(str))
       return false;

    return true;
}

bool Administrator::UpdateStudent(const UStudent &s) const
{
    /*update the student's name*/

    QString str;
    str = "update Student set name = '";
    str += s.GetName().data();
    str += "' where ID = ";
    str += QString::number(s.GetID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*update the student's department*/

    str = "update Student set deptName = '";
    str += s.GetDeptName().data();
    str += "' where ID = ";
    str += QString::number(s.GetID());

    if(!query.exec(str))
        return false;

    /*update the student's gender*/

    QString gender;
    if(s.GetGender() == 0)
        gender = "male";
    else gender = "female";

    str = "update Student set gender = '";
    str += gender;
    str += "' where ID = ";
    str += QString::number(s.GetID());

    if(!query.exec(str))
        return false;

    /*update the student's birthday*/

    str = "update Student set birthday = '";
    str += s.GetBirthday().data();
    str += "' where ID = ";
    str += QString::number(s.GetID());

    if(!query.exec(str))
        return false;

    return true;
}

int Administrator::FindStudent(const int ID)
{
    /*select from student table*/

    QString str = "select * from Student where ID = ";
    str += QString::number(ID);
    int RecordNum = 0;

    QSqlQuery query;
    if(!query.exec(str))
        return 0;
    else{
        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 5; i++)
                Aresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

// administrator adds a teacher
bool Administrator::AddTeacher(const UTeacher &t) const
{
    /*insert a record into the teacher table*/
    QSqlQuery query;
    query.prepare("insert into Teacher (ID, name, deptName) values (?, ?, ?)");
    query.addBindValue(t.GetID());
    query.addBindValue(t.GetName().data());
    query.addBindValue(t.GetDeptName().data());

    if(!query.exec())
        return false;

    /*insert a record into the user table*/

    query.prepare("insert into User (ID, type, password) values (?, ?, ?)");
    query.addBindValue(t.GetID());
    query.addBindValue("teacher");
    query.addBindValue(t.GetPassword());

    if(!query.exec())
        return false;

    return true;
}

// administrator removes a teacher
bool Administrator::RemoveTeacher(const UTeacher &t) const
{
    /*delete a record from the teacher table*/

    QString str;
    str = "delete from Teacher where ID = ";
    str += QString::number(t.GetID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*delete a record from the user table*/

    str = "delete from User where ID = ";
    str += QString::number(t.GetID());
    str += " and type = 'teacher'";

    if(!query.exec(str))
       return false;

    return true;
}

bool Administrator::UpdateTeacher(const UTeacher &t) const
{
    /*update the teacher's name*/

    QString str;
    str = "update Teacher set name = '";
    str += t.GetName().data();
    str += "' where ID = ";
    str += QString::number(t.GetID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

     /*update the teacher's department*/
    str = "update Teacher set deptName = '";
    str += t.GetDeptName().data();
    str += "' where ID = ";
    str += QString::number(t.GetID());

    if(!query.exec(str))
        return false;

    return true;
}

int Administrator::FindTeacher(const int ID)
{
    /*select from teacher table*/

    QString str = "select * from Teacher where ID = ";
    str += QString::number(ID);
    // @ST damn it, should have benn initialized
    int RecordNum = 0;

    QSqlQuery query;
    if(!query.exec(str))
        return 0;
    else{
        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 3; i++)
                Aresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

// administrator adds a administrator
bool Administrator::AddAdministartor(const Administrator &a) const
{
    /*insert a record into the administrator table*/

    QSqlQuery query;
    query.prepare("insert into Administrator (ID, name, deptName) values (?, ?, ?)");
    query.addBindValue(a.GetID());
    query.addBindValue(a.GetName().data());
    query.addBindValue(a.GetDeptName().data());

    if(!query.exec())
        return false;

    /*insert a record into the user table*/

    query.prepare("insert into User (ID, type, password) values (?, ?, ?)");
    query.addBindValue(a.GetID());
    query.addBindValue("administrator");
    query.addBindValue(a.GetPassword());

    if(!query.exec())
        return false;

    return true;
}

// administrator removes a administrator
bool Administrator::RemoveAdministartor(const Administrator &a) const
{
    /*delete a record from the administrator table*/

    QString str;
    str = "delete from Administrator where ID = ";
    str += QString::number(a.GetID());

    QSqlQuery query;

    if(!query.exec(str))
        return false;

    /*delete a record from the user table*/

    str = "delete from User where ID = ";
    str += QString::number(a.GetID());
    str += " and type = 'administrator'";

    if(!query.exec(str))
       return false;

    return true;
}

bool Administrator::UpdateAdministrator(const Administrator &a) const
{
    /*delete a record from the student table*/

    QString str;    //set the query sentence
    str = "update Administrator set name = '";
    str += a.GetName().data();
    str += "' where ID = ";
    str += QString::number(a.GetID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    str = "update Administrator set deptName = '";
    str += a.GetDeptName().data();
    str += "' where ID = ";
    str += QString::number(a.GetID());

    if(!query.exec(str))
        return false;

    return true;
}

int Administrator::FindAdministrator(const int ID)
{
    /*select from administrator*/

    QString str = "select * from Administrator where ID = ";
    str += QString::number(ID);
    int RecordNum = 0;

    QSqlQuery query;
    if(!query.exec(str))
        return 0;
    else{
        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 3; i++)
                Aresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

// administrator adds a course
bool Administrator::AddCourse(const Course &c) const
{
    /*insert a record into the course table*/

    QSqlQuery query;
    query.prepare("insert into Course (courseID, title, deptName, credits) values (?, ?, ? ,?)");
    query.addBindValue(c.GetCourseID());
    query.addBindValue(c.GetTitle().data());
    query.addBindValue(c.GetDeptName().data());
    query.addBindValue(c.GetCredits());

    if(!query.exec())
        return false;

    return true;
}

// administrator removes a course
bool Administrator::RemoveCourse(const Course &c) const
{
    /*delete a record from the course table*/

    QString str;
    str = "delete from Course where courseID = ";
    str += QString::number(c.GetCourseID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*delete records from the section table*/

    str = "delete from Section where courseID = ";
    str += QString::number(c.GetCourseID());

    if(!query.exec(str))
       return false;

    return true;
}

bool Administrator::UpdateCourse(const Course &c) const
{
    /*update course's title*/

    QString str;
    str = "update Course set title = '";
    str += c.GetTitle().data();
    str += "' where courseID = ";
    str += QString::number(c.GetCourseID());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*update course's department*/

    str = "update Course set deptName = '";
    str += c.GetDeptName().data();
    str += "' where courseID = ";
    str += QString::number(c.GetCourseID());

    if(!query.exec(str))
        return false;

    /*update course's credits*/

    str = "update Course set credits = '";
    str += QString::number(c.GetCredits());
    str += "' where courseID = ";
    str += QString::number(c.GetCourseID());

    if(!query.exec(str))
        return false;

    return true;
}

int Administrator::FindCourse(const int courseID)
{
    /*select from course table*/

    QString str = "select * from Course where courseID = ";
    str += QString::number(courseID);
    int RecordNum = 0;

    QSqlQuery query;
    if(!query.exec(str))
        return 0;
    else{
        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 4; i++)
                Aresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}


// administrator adds a section
bool Administrator::AddSection(const Section &s) const
{
    /*insert a record into the section table*/

    QSqlQuery query;
    query.prepare("insert into Section (courseID, secID, semester, year, capacity, vacancy, building, roomNo, timeSlotID) values (?, ?, ? ,?, ?, ?, ?, ?, ?)");
    query.addBindValue(s.GetCourseID());
    query.addBindValue(s.GetSecID());
    query.addBindValue(s.GetSemester().data());
    query.addBindValue(s.GetYear());
    query.addBindValue(s.GetCapacity());
    query.addBindValue(s.GetVacancy());
    query.addBindValue(s.GetBuilding().data());
    query.addBindValue(s.GetRoomNo());
    query.addBindValue(s.GetTimeSlotID());

    if(!query.exec())
        return false;

    return true;
}

// administrator removes a section
bool Administrator::RemoveSection(const Section &s) const
{
    /*delete a record from the section table*/

    QString str;
    str = "delete from Section where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str += s.GetSemester().data();
    str += "' and year = ";
    str += QString::number(s.GetYear());
    str += " and building = '";
    str += s.GetBuilding().data();
    str += "'";

    QSqlQuery query;
    if(!query.exec(str))
       return false;

    return true;
}

bool Administrator::UpdateSection(const Section &s) const
{
    /*update the section's capacity*/

    QString str;
    str = "update Section set capacity = ";
    str += QString::number(s.GetCapacity());
    str += " where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str += s.GetSemester().data();
    str += "' and year = ";
    str += QString::number(s.GetYear());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*update the section's building*/

    str = "update Section set building = '";
    str += s.GetBuilding().data();
    str += "' where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str += s.GetSemester().data();
    str += "' and year = ";
    str += QString::number(s.GetYear());

    if(!query.exec(str))
        return false;

    /*update the section's roomNo*/

    str = "update Section set roomNo = ";
    str += QString::number(s.GetRoomNo());
    str += " where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str += s.GetSemester().data();
    str += "' and year = ";
    str += QString::number(s.GetYear());
    if(!query.exec(str))
        return false;

    /*update the section's timeSlotID*/

    str = "update Section set timeSlotID = ";
    str += QString::number(s.GetTimeSlotID());
    str += " where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str += s.GetSemester().data();
    str += "' and year = ";
    str += QString::number(s.GetYear());

    if(!query.exec(str))
        return false;

    return true;
}

int Administrator::FindSection(const int courseID, const int secID)
{
    /*select from section table*/

    QString str = "select * from Section where courseID = ";
    str += QString::number(courseID);
    str += " and secID = ";
    str += QString::number(secID);
    int RecordNum = 0;

    QSqlQuery query;
    if(!query.exec(str))
        return 0;
    else{
        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 9; i++)
                Aresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}
