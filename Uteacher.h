#ifndef UTeacher_H
#define UTeacher_H

#include "user.h"

class UTeacher: public User
{
public:
    vector <QString> Tresult;
    UTeacher(void);  //constructors
    UTeacher(const int ID, const string &password, const string &name = "", const string &deptname = "");
    virtual ~UTeacher(){}    //destructors

    int ViewMyCourses();  // show courses that the Teacher teaches
    int ViewMyNewStudent(const Section &s);  //show students who takes the courses which this Teacher teaches
    int ViewMyOldStudent(const Section &s);  //show students who takes the courses which this Teacher teaches
    bool Marks(int ID, const Section &s, double grade);
};

#endif // UTeacher_H
