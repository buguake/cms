#include "Ustudent.h"
//vector <QString> Sresult;

/*constructor for class UStudent*/

UStudent::UStudent(void)
    : User(-1, "******", "Student", "null", "null"){
}

UStudent::UStudent(const int ID, const string &password, const string &name, const string &deptname)
    : User(ID, password, "Student", name, deptname){
}

UStudent::UStudent(const int ID, const string &password, const string &name, const string &deptname, const string &birthday, const string &gender)
    : User(ID, password, "Student", name, deptname), birthday(birthday)
{
    SetGender(gender);
}

// show courses that the UStudent takes
int UStudent::ViewMyCourses()
{

    /*select from takes table*/

    int RecordNum = 0;

    QString str = "select * from Takes where ID = ";
    str += QString::number(ID);

    QSqlQuery query;
    if(!query.exec(str)) {
        return 0;
    }

    else{
        while(query.next()) {
            /*get record num*/
            RecordNum = query.size();

            /*get courseID, secID, semester, year*/

            QString courseID = query.value("courseID").toString();
            Sresult.push_back(courseID);

            /*select from course table*/

            QString str2;
            QSqlQuery query2;
            str2 = "select * from Course where courseID = ";
            str2 += courseID;
            if(!query2.exec(str2))
                return 0;
            /*get title, deptName, credits*/

            while(query2.next()) {
                for(int i = 1; i < 4; i++)
                    Sresult.push_back(query2.value(i).toString());
            }
            for(int i = 2; i < 6; i++)
                Sresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

// take a course
bool UStudent::Takes(const Section &s) const
{
    /*select vacancy to see whether the course capacity is full*/

    QString str;
    str = "select vacancy from Section where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str +=  s.GetSemester().data();
    str += +"' and year = ";
    str += QString::number(s.GetYear());
    str += " and building = '";
    str += s.GetBuilding().data();
    str += "'";

    QSqlQuery query;
    if(!query.exec(str)) {
        return false;
    }
    else{
        while(query.next()) {
            int vacancy = query.value("vacancy").toInt();
            if(vacancy <= 0) {
                return false;
            }
        }
    }

    /*insert a record into the takes table*/

    query.prepare("insert into Takes (ID, courseID, secID, semester, year, grade) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(ID);
    query.addBindValue(s.GetCourseID());
    query.addBindValue(s.GetSecID());
    query.addBindValue(s.GetSemester().data());
    query.addBindValue(s.GetYear());
    query.addBindValue(0);

    if(!query.exec())
        return false;


    /*update the vacancy*/

    str = "update Section set vacancy = vacancy - 1 where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str +=  s.GetSemester().data();
    str += +"' and year = ";
    str += QString::number(s.GetYear());
    str += " and building = '";
    str += s.GetBuilding().data();
    str += "'";

    if(!query.exec(str))
        return false;

    return true;
}

// drop a course
bool UStudent::Drops(const Section &s) const
{
    /*delete a record from the takes table*/

    QString str;
    str = "delete from Takes where ID = ";
    str += QString::number(ID);
    str += " and courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str +=  s.GetSemester().data();
    str += +"' and year = ";
    str += QString::number(s.GetYear());

    QSqlQuery query;
    if(!query.exec(str))
        return false;

    /*update the vacancy*/

    str = "update Section set vacancy = vacancy + 1 where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and semester = '";
    str +=  s.GetSemester().data();
    str += +"' and year = ";
    str += QString::number(s.GetYear());
    str += " and building = '";
    str += s.GetBuilding().data();
    str += "'";

    if(!query.exec(str))
        return false;

    return true;

}

int UStudent::SearchSection(const int courseID)
{
    QString title, credits;
    int RecordNum = 0;

    /*select from course table*/

    QString str = "select * from Course where courseID = ";
    str += QString::number(courseID);

    QSqlQuery query;
    if(!query.exec(str))
        return 0;

    /*get title, credits*/
    while(query.next()) {
        title = query.value("title").toString();
        credits = query.value("credits").toString();
    }

    /*select from section table*/

    str = "select * from Section where courseID = ";
    str += QString::number(courseID);
    /* @ST I just want to select all courses available in 2016 @TODO
       str += " and year = 2016 and semester = 'Fall' union select * from Section where courseID = ";
       str += QString::number(courseID);
       str += " and year = 2016 and semester = 'Winter'";
     */
    str += " and year = 2016";

    if(!query.exec(str)) {  //if the query fails
        return 0;
    }

    while(query.next()) {
        /*get record number*/
        RecordNum = query.size();

        /*get secID, semester, year, capacity, vacancy, buidling, roomNo, timeSlotID*/

        Sresult.push_back(QString::number(courseID));
        Sresult.push_back(title);
        Sresult.push_back(credits);
        for(int i = 1; i < 8; i++)
            Sresult.push_back(query.value(i).toString());
        QString timeSlotID = query.value("timeSlotID").toString();

        /*select from timeSlot table*/

        QString str2 = "select * from TimeSlot where timeSlotID = ";
        str2 += timeSlotID;
        QSqlQuery query2;
        if(!query2.exec(str2))
            return 0;

        /*get day, startime, endtime*/

        while(query2.next())
            for(int i = 1; i < 4; i++)
                Sresult.push_back(query2.value(i).toString());
    }
    return RecordNum;

}

int UStudent::SearchSection(const string &title)
{
    QString courseID, credits;
    int RecordNum = 0;

    /*select from course table*/

    QString str = "select * from Course where title = '";
    str += title.data();
    str += "'";

    QSqlQuery query;
    if(!query.exec(str))
        return 0;

    /*get courseID, credits*/

    while(query.next()) {
        courseID = query.value("courseID").toString();
        credits = query.value("credits").toString();
    }

    /*select from section table*/

    str = "select * from Section where courseID = ";
    str += courseID;
    /* @ST I would like to show courses available in 2016
    str += " and year = 2016 and semester = 'Fall' union select * from Section where courseID = ";
    str += courseID;
    str += " and year = 2016 and semester = 'Winter'";
    */
    str += " and year = 2016";

    if(!query.exec(str))
        return 0;

    /*get secID, semester, year, capacity, vacancy, buidling, roomNo, timeSlotID*/

    while(query.next()) {
        RecordNum = query.size();
        Sresult.push_back(courseID);
        Sresult.push_back(title.data());
        Sresult.push_back(credits);
        for(int i = 1; i < 8; i++)
            Sresult.push_back(query.value(i).toString());
        QString timeSlotID = query.value("timeSlotID").toString();

        /*select from timeSlot table*/

        QString str2 = "select * from TimeSlot where timeSlotID = ";
        str2 += timeSlotID;
        QSqlQuery query2;
        if(!query2.exec(str2))
            return 0;

        /*get day, startime, endtime*/

        while(query2.next())
            for(int i = 1; i < 4; i++)
                Sresult.push_back(query2.value(i).toString());
    }
    return RecordNum;

}
