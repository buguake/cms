#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "Course.hpp"
using namespace std;
enum UserType {student, teacher, administrator};
enum GenderType {male, female};

class User
{
protected:
    User(int ID, char *password, UserType type, string &name);
private:
    int ID;
    char password[16];  // 128-bit hashed value
    string name;
    UserType type;
    string deptName;
public:
    int GetID() const;
    char *GetPassword() const;
    UserType GetType() const;
    string GetName() const;
    string GetDeptName() const;
    void SetID(int ID);  // set user's ID from
    void SetPassword(char *password);  // get user's input(use to validate)
    void SetType(const string &type);  // set user's type, student, teacher or administrator
    void SetName(const string &name);  // set user's name after Login successfully
    void SetDeptName(const string &deptName);  // set user's deptName after Login
    bool Login();  // try to Login, using ID, password and type
    void Logout();  // clean
    void ViewCourses();  // show all the courses available
};

class Student: public User
{
private:
    string birthday;
    GenderType gender;
public:
    string GetBirthday();  // show birthday, format: YYYY-MM-DD
    GenderType GetGender();  // show gender, male / female
    void SetBirthday(string birthday);
    void SetGender(string gender);  // seemes trivial but actually useful when you sign up
    void ViewMyCourses();  // show tables that the student takes
    // @NOTE sometimes it fails to take a course because of collison
    bool Takes(Course c, Section s);  // take a course
    bool Drops(Course c, Section s);  // drop a course
};

class Teacher: public User
{
public:
    void ViewMyCourses();  // show courses that the teacher teaches
    void Marks(Course c, Section s);  // mark grade of one course, here we can invoke some Qt functions here to show a table for the user to edit
};

class Administrator: public User
{
public:
    // @NOTE Add / Delete users must update the User table and Student / Teacher / Administrator table respectively
    void AddStudent(Student s);
    void RemoveStudent(Student s);
    void AddTeacher(Teacher t);
    void RemoveTeacher(Teacher t);
    void AddAdministartor(Administrator a);
    void RemoveAdministartor(Administrator a);
    // @NOTE Be careful when removing a course, have to delete related sections
    void AddCourse(Course c);
    void RemoveCourse(Course c);
    void AddSection(Section s);
    void RemoveSection(Section s);
};

#endif // USER_H
