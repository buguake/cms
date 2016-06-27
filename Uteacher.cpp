#include "UTeacher.h"
//vector <QString> Tresult;

/*construtors for class teacher*/

UTeacher::UTeacher(void)
        :User(-1, "******", "teacher", "null", "null"){}

UTeacher::UTeacher(const int ID, const string &password, const string &name, const string &deptname)
        :User(ID, password, "teacher", name, deptname){}

// show courses that the teacher teaches
int UTeacher::ViewMyCourses() const
{
    /*select from teacher table*/

    int RecordNum;
    QString str = "select * from Teaches where ID = ";
    str += QString::number(ID);

    QSqlQuery query;
    if(!query.exec(str)){
        return 0;
    }
    else{
        while(query.next()){
            /*get record number, courseID*/

            RecordNum = query.size();
            QString courseID = query.value("courseID").toString();
            Tresult.push_back(courseID);

            /*select from course table*/

            QString str2;
            QSqlQuery query2;
            str2 = "select * from Course where courseID = ";
            str2 += courseID;
            if(!query2.exec(str2))
                return 0;
             /*get courseID, secID, semester, year*/

            while(query2.next()){
                for(int i = 1; i < 4; i++)
                    Tresult.push_back(query2.value(i).toString());
            }
            for(int i = 2; i < 5; i++)
                Tresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}
int UTeacher::ViewMyNewStudent(const Section &s) const
{
    /*select from teacher table*/

    int RecordNum =0;
    QString title, deptName;
    QString str = "select * from Course where courseID = ";
    str += QString::number(s.GetCourseID());

    QSqlQuery query;
    if(!query.exec(str)){
        return 0;
    }
    else{
        /*get title, deptName*/
        while(query.next()){
            title = query.value("title").toString();
            deptName = query.value("deptName").toString();
        }
    }

    /*select from takes table*/

    str = "select * from Takes where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and year = 2016 and semester = 'Fall' union ";
    str += "select * from Takes where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and year = 2016 and semester = 'Winter'";

    if(!query.exec(str)){
        return 0;
    }
    else{

        /*get ID, secID, semester, year*/

        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 2; i++)
                Tresult.push_back(query.value(i).toString());
            Tresult.push_back(title);
            Tresult.push_back(deptName);
            for(int i = 2; i < 6; i++)
                Tresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

int UTeacher::ViewMyOldStudent(const Section &s) const  //show students who takes the courses which this Teacher teaches
{
    /*select from teacher table*/

    int RecordNum =0;
    QString title, deptName;
    QString str = "select * from Course where courseID = ";
    str += QString::number(s.GetCourseID());

    QSqlQuery query;
    if(!query.exec(str)){
        return 0;
    }
    else{
        /*get title, deptName*/
        while(query.next()){
            title = query.value("title").toString();
            deptName = query.value("deptName").toString();
        }
    }

    /*select from takes table*/

    str = "select * from Takes where courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and year = 2016 and semester = 'Summer'";

    if(!query.exec(str)){
        return 0;
    }
    else{

        /*get ID, secID, semester, year*/

        while(query.next()){
            RecordNum = query.size();
            for(int i = 0; i < 2; i++)
                Tresult.push_back(query.value(i).toString());
            Tresult.push_back(title);
            Tresult.push_back(deptName);
            for(int i = 2; i < 6; i++)
                Tresult.push_back(query.value(i).toString());
        }
    }
    return RecordNum;
}

bool UTeacher::Marks(int ID, const Section &s, double grade)
{
    /*update takes table*/

    QString str = "update Takes set grade = ";
    str += QString::number(grade);
    str += " where ID = ";
    str += QString::number(ID);
    str += " and courseID = ";
    str += QString::number(s.GetCourseID());
    str += " and secID = ";
    str += QString::number(s.GetSecID());
    str += " and year = 2016 and semester = 'Summer'";

    QSqlQuery query;
    if(!query.exec(str)){
        return false;
    }
    else
        return true;
}



