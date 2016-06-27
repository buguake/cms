#include "section.h"

/*constructors for class section*/

Section::Section(const int courseID, const int secID)
    : courseID(courseID), secID(secID), semester("null"), year(0),
      capacity(0), vacancy(0), building("null"),
      roomNo(0), timeSlotID(0){}

Section::Section(const int courseID, const int secID, const string &semester, const int year)
    : courseID(courseID), secID(secID), semester(semester), year(year),
      capacity(0), vacancy(0), building("null"),
      roomNo(0), timeSlotID(0){}

Section::Section(const int courseID, const int secID, const string &semester, const int year, const int capacity, const string &building, const int roomNo, const int timeSlotID)
    : courseID(courseID), secID(secID), semester(semester), year(year),
      capacity(capacity), vacancy(capacity), building(building),
      roomNo(roomNo), timeSlotID(timeSlotID){}

Section::Section(const int courseID, const int secID, const string &semester, const int year, const int capacity, const int vacancy,const string &building, const int roomNo, const int timeSlotID)
    : courseID(courseID), secID(secID), semester(semester), year(year),
      capacity(capacity), vacancy(vacancy), building(building),
      roomNo(roomNo), timeSlotID(timeSlotID){}

Section::Section(const Section &s)
    : courseID(s.courseID), secID(s.secID), semester(s.semester),
      year(s.year), capacity(s.capacity), vacancy(s.vacancy),
      building(s.building), roomNo(s.roomNo), timeSlotID(s.timeSlotID){}
