#schema.sql
drop table Takes;
drop table Teaches;
drop table Section;
drop table Student;
drop table Teacher;
drop table Administrator;
drop table Course;
drop table Classroom;
drop table TimeSlot;
drop table User;

create table User
(
    ID int ZEROFILL UNSIGNED NOT NULL,
    type varchar(13) CHECK (type in ('student', 'teacher', 'administrator')),
    password binary(16) DEFAULT x'e10adc3949ba59abbe56e057f20f883e',  # default value: UNHEX(MD5('123456'))
    primary key(ID, type)
);

create table Student
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    birthday date,
    gender varchar(6) DEFAULT 'male' CHECK(gender = 'male' or gender = 'female'),
    deptName varchar(30),
    primary key(ID)
);

create table Teacher
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    deptName varchar(30),
    primary key(ID)
);

create table Administrator
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    deptName varchar(30),
    primary key(ID)
);

create table Course
(
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    title varchar(30) NOT NULL,
    deptName varchar(30),
    credits numeric(2,1),
    primary key(courseID)
);

create table Section
(
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester varchar(6) CHECK (semester in ('Spring', 'Summer', 'Fall', 'Winter')),
    year int(4) CHECK (year >= 1897),
    capacity int CHECK(capacity > 0),
    vacancy int,
    building varchar(20),
    roomNo int,
    timeSlotID int,
    primary key(courseID, secID, semester, year, building),
    foreign key (courseID) references Course(courseID)
);

create table Takes
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester varchar(6) CHECK (semester in ('Spring', 'Summer', 'Fall', 'Winter')),
    year int(4) CHECK (year >= 1897),
    grade numeric(2,1) CHECK (grade >= 0 and grade <= 5.0),
    primary key(ID, courseID, secID, semester, year),
    foreign key (ID) references Student(ID),
    foreign key (courseID) references Course(courseID)
);

create table Teaches
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester varchar(6) CHECK (semester in ('Spring', 'Summer', 'Fall', 'Winter')),
    year int(4) CHECK (year >= 1897),
    primary key(ID, courseID, semester, year),
    foreign key(ID) references Teacher(ID),
    foreign key (courseID) references Course(courseID)
);

create table Classroom
(
    building varchar(30),
    roomNo int,
    capacity int,
    primary key(building, roomNo)
);

create table TimeSlot
(
    timeSlotID int,
    day char(3) CHECK(day in ('Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun')),
    startTime time,
    endTime time,
    primary key(timeSlotID, day, startTime)
);

