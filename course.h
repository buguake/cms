#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
private:
    int courseID;
    string title;
    string deptName;
    double credits;
public:
    Course(const int courseID, const string &title, const string &deptName, const double credits);  //constructor
    virtual ~Course(){} //destructor
    Course(const Course &c);   //copy constructor

    inline int GetCourseID() const; //get private variables
    inline string GetTitle() const;
    inline string GetDeptName() const;
    inline double GetCredits() const;

    inline void SetCourseID(const int courseID);    //set private variables
    inline void SetTitle(const string &title);
    inline void SetDeptName(const string &deptName);
    inline void SetCredits(const double credtis);
};

/*inline functions*/
inline int Course::GetCourseID() const
{
    return courseID;
}

inline string Course::GetTitle() const
{
    return title;
}

inline string Course::GetDeptName() const
{
    return deptName;
}

inline double Course::GetCredits() const
{
    return credits;
}

inline void Course::SetCourseID(const int courseID)
{
    this->courseID = courseID;
}

inline void Course::SetTitle(const string &title)
{
    this->title = title;
}

inline void Course::SetDeptName(const string &deptName)
{
    this->deptName = deptName;
}

inline void Course::SetCredits(const double credits)
{
    this->credits = credits;
}

#endif  //COURSE_H
