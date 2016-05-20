#ifndef COURSE_HPP
#define COURSE_HPP

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
    Course(int courseID, const string &title, const string &deptName, double credits);
    ~Course();
    int GetCourseID() const;
    string GetTitle() const;
    string GetDeptName() const;
    double GetCredits() const;
    void SetCourseID(int courseID);
    void SetTitle(const string &title);
    void SetDeptName(const string &deptName);
    void SetCredits(double credtis);
};

class Section
{
private:
    int courseID;
    int secID;
    string semester;
    int year;
    int capacity;
    int vacancy;
    string building;
    int roomNo;
    int timeSlotID;
public:
    Section(int courseID, int secID, const string &semester, int year, int capacity, int vacancy, const string &building, int roomNo, int timeSlotID);
    // @NOTE 1 <= timeSlotID <= 7
    ~Section();
    int GetCourseID() const;
    int GetSecID() const;
    string GetSemester() const;
    int GetYear() const;
    int GetCapacity() const;
    int GetVacancy() const;
    string GetBuilding() const;
    int GetRoomNo() const;
    int GetTimeSlitID() const;
    // set, though the following functions might be useless, I still put them here
    void SetCourseID(int courseID);
    void SetSecID(int secID);
    void SetSemester(const string &semester);
    void SetYear(int year);
    void SetCapacity(int capacity);
    void SetVacancy(int vacancy);
    void SetBuilding(const string &building);
    void SetRoomNo(int roomNo);
    void SetTimeSlotID(int timeSlotID);
};

#endif
