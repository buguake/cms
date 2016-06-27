#ifndef SECTION_H
#define SECTION_H

#include <string>
using namespace std;

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
    Section(const int courseID, const int secID);   //constructors
    Section(const int courseID, const int secID, const string &semester, const int year);
    Section(const int courseID, const int secID, const string &semester, const int year, const int capacity, const string &building, const int roomNo, const int timeSlotID);
    virtual ~Section(){}    //destructor
    Section(const Section &s);  //copy constructor

    inline int GetCourseID() const; //get private variables
    inline int GetSecID() const;
    inline string GetSemester() const;
    inline int GetYear() const;
    inline int GetCapacity() const;
    inline int GetVacancy() const;
    inline string GetBuilding() const;
    inline int GetRoomNo() const;
    inline int GetTimeSlotID() const;

    inline void SetCourseID(const int courseID);    //set private variables
    inline void SetSecID(const int secID);
    inline void SetSemester(const string &semester);
    inline void SetYear(const int year);
    inline void SetCapacity(const int capacity);
    inline void SetVacancy(const int vacancy);
    inline void SetBuilding(const string &building);
    inline void SetRoomNo(const int roomNo);
    inline void SetTimeSlotID(const int timeSlotID);
};

/*inline functions*/
inline int Section::GetCourseID() const{
    return courseID;
}

inline int Section::GetSecID() const{
    return secID;
}

inline string Section::GetSemester() const{
    return semester;
}

inline int Section::GetYear() const{
    return year;
}

inline int Section::GetCapacity() const{
    return capacity;
}

inline int Section::GetVacancy() const{
    return vacancy;
}

inline string Section::GetBuilding() const{
    return building;
}

inline int Section::GetRoomNo() const{
    return roomNo;
}

inline int Section::GetTimeSlotID() const{
    return timeSlotID;
}

inline void Section::SetCourseID(const int courseID){
    this->courseID = courseID;
}

inline void Section::SetSecID(const int secID){
    this->secID = secID;
}

inline void Section::SetSemester(const string &semester){
    this->semester = semester;
}

inline void Section::SetYear(const int year){
    this->year = year;
}

inline void Section::SetCapacity(const int capacity){
    this->capacity = capacity;
}

inline void Section::SetVacancy(const int vacancy){
    this->vacancy = vacancy;
}

inline void Section::SetBuilding(const string &building){
    this->building = building;
}

inline void Section::SetRoomNo(const int roomNo){
    this->roomNo = roomNo;
}

inline void Section::SetTimeSlotID(const int timeSlotID){
    this->timeSlotID = timeSlotID;
}


#endif // SECTION_H
