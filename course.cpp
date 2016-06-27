#include "course.h"

/*constructors for class course*/

Course::Course(const int courseID, const string &title, const string &deptName, const double credits)
    : courseID(courseID), title(title), deptName(deptName), credits(credits){}

Course::Course(const Course &c)
    :courseID(c.courseID),title(c.title),deptName(c.deptName),credits(c.credits){}
