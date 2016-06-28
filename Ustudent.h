#ifndef UStudent_H
#define UStudent_H

#include "user.h"

class UStudent: public User
{
private:
    string birthday;
    GenderType gender;
public:
    vector <QString> Sresult;
    UStudent(void);  //constructors
    UStudent(const int ID, const string &password, const string &name, const string &deptname);
    UStudent(const int ID, const string &password, const string &name, const string &deptname, const string &birthday, const string &gender);
    virtual ~UStudent(){}    //destructor

    /*get private variables*/
    inline string GetBirthday() const;  // show birthday, format: YYYY-MM-DD
    inline GenderType GetGender() const;  // show gender, male / female

    /*set private variables*/
    inline void SetBirthday(const string &birthday);
    inline void SetGender(const string &gender);  // seemes trivial but actually useful when you sign up

    int ViewMyCourses();  // show courses that the Student takes
    bool Takes(const Section &s) const;  // take a course
    bool Drops(const Section &s) const;  // drop a course

    int SearchSection(const int courseID);    //search section according to courseID
    int SearchSection(const string &title);   //search section according to course title
};

/*inline functions*/
inline string UStudent::GetBirthday() const
{
    return this->birthday;
}

inline GenderType UStudent::GetGender() const
{
    return this->gender;
}

inline void UStudent::SetBirthday(const string &birthday)
{
    this->birthday = birthday;
}

inline void UStudent::SetGender(const string &gender)
{
    if(gender == "male") this->gender = male;
    if(gender == "female") this->gender = female;
}

#endif // UStudent_H
