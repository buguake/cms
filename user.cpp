#include "user.h"

//constuctors for class User

User::User(void)
    :ID(-1),name("null"),deptName("null")
{
    SetPassword("******");
    SetType("null");
}

User::User(const int ID, const string &password, const string &type, const string &name, const string &deptname)
    :ID(ID), name(name), deptName(deptname)
{
    SetPassword(password.c_str());
    SetType(type);
}

User::User(const User& user)
     :ID(user.ID), type(user.type), name(user.name), deptName(user.deptName)
{
    SetPassword(user.password);
}

// try to Login, using ID, password and type
bool User::Login() const
{
    /*select from user table*/

    //set the recordtype
    QString RecordType;
    if(this->type == Ustudent) RecordType = "student";
    else if(this->type == Uteacher) RecordType = "teacher";
    if(this->type == administrator) RecordType = "administrator";

    QString str = "select * from User where ID = ";
    str += QString::number(ID);
    str += " and password = ";
    str += password;
    str += " and type = '";
    str += RecordType;
    str += "'";

    QSqlQuery query;
    if(!query.exec(str)){
        return false;
    }
    else{
        //see whether the result type matches
        if(query.size()){
            return true;
        }
    }
    return false;
}



