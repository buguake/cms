#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "user.h"
#include "Ustudent.h"
#include "Uteacher.h"

class Administrator : public User
{
public:
    vector <QString> Aresult;
    Administrator(void);    //construtors
    Administrator(const int ID, const string &password, const string &name, const string &deptname);
    virtual ~Administrator(){}  //destructor

    bool AddStudent(const UStudent &s) const;    //add a student
    bool RemoveStudent(const UStudent &s) const; //delete a student
    bool UpdateStudent(const UStudent &s) const; //update the information of a student
    int FindStudent(const int ID) const;

    bool AddTeacher(const UTeacher &t) const;    //operations about teachers
    bool RemoveTeacher(const UTeacher &t) const;
    bool UpdateTeacher(const UTeacher &t) const;
    int FindTeacher(const int ID) const;

    bool AddAdministartor(const Administrator &a) const;    //operations about administrators
    bool RemoveAdministartor(const Administrator &a) const;
    bool UpdateAdministrator(const Administrator &a) const;
    int FindAdministrator(const int ID) const;

    bool AddCourse(const Course &c) const;  //operations about courses
    bool RemoveCourse(const Course &c) const;
    bool UpdateCourse(const Course &c) const;
    int FindCourse(const int courseID) const;

    bool AddSection(const Section &s) const;    //opertions about sections
    bool RemoveSection(const Section &s) const;
    bool UpdateSection(const Section &s) const;
    int FindSection(const int courseID, const int secID) const;
};

#endif // ADMINISTRATOR_H
