#ifndef USER_H
#define USER_H

#include <cstring>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>
#include <QDateTime>
#include "course.h"
#include "section.h"

using namespace std;

enum UserType {Ustudent, Uteacher, administrator, null};
enum GenderType {male, female};

class User
{
protected:
    int ID;
private:
    char password[16];  // 128-bit hashed value
    UserType type;
    string name;
    string deptName;
public:
    User(void); //constructos
    User(const int ID, const string &password, const string &type, const string &name, const string &deptname);
    virtual ~User(){}   //destructos
    User(const User& user); //copy constructors

    /*get private variables*/
    inline int GetID() const;
    inline const char *GetPassword() const;
    inline UserType GetType() const;
    inline string GetName() const;
    inline string GetDeptName() const;

    /*set private variables*/
    inline void SetID(const int ID);  // set user's ID from
    inline void SetPassword(const char *password);  // get user's input(use to validate)
    inline void SetType(const string &type);  // set user's type, student, teacher or administrator
    inline void SetName(const string &name);  // set user's name after Login successfully
    inline void SetDeptName(const string &deptName);  // set user's deptName after Login

    bool Login() const;  // try to Login, using ID, password and type
};

/*inline functions*/
inline int User::GetID() const
{
    return ID;
}

inline const char *User::GetPassword() const
{
    return this->password;
}

inline UserType User::GetType() const
{
    return this->type;
}

inline string User::GetName() const
{
    return this->name;
}

inline string User::GetDeptName() const
{
    return this->deptName;
}

inline void User::SetID(const int ID)
{
    this->ID = ID;
}

inline void User::SetPassword(const char *password)
{
    strcpy(this->password, password);
}

// set user's type, student, teacher or administrator
inline void User::SetType(const string &type)
{
    // @ST damn it, sily mistake
    if(type == "student") this->type = Ustudent;
    else if(type == "teacher") this->type = Uteacher;
    else if(type == "administrator") this->type = administrator;
    else this->type = null;
}

inline void User::SetName(const string &name)
{
    this->name = name;
}

inline void User::SetDeptName(const string &deptName)
{
    this->deptName = deptName;
}

#endif // USER_H
