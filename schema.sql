#schema.sql
drop table takes;
drop table teaches;
drop table section;
drop table student;
drop table teacher;
drop table administrator;
drop table course;
drop table classromm;
drop table timeSlot;
drop table user;

create table user
(
    ID int ZEROFILL UNSIGNED NOT NULL,
    type varchar(13) CHECK (type in ('student', 'teacher', 'administrator')),
    password binary(16) DEFAULT x'e10adc3949ba59abbe56e057f20f883e',  # default value: UNHEX(MD5('123456'))
    primary key(ID, type)
);

create table student
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    birthday date,
    gender varchar(6) DEFAULT 'male' CHECK(gender = 'male' or gender = 'female'),
    deptName varchar(30),
    primary key(ID)
);

create table teacher
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    deptName varchar(30),
    primary key(ID)
);

create table administrator
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    name varchar(20) NOT NULL,
    primary key(ID)
);

create table course
(
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    title varchar(30) NOT NULL,
    deptName varchar(30),
    credits numeric(2,1),
    primary key(courseID)
);

create table section
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
    foreign key (courseID) references course(courseID)
);

create table takes
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester varchar(6) CHECK (semester in ('Spring', 'Summer', 'Fall', 'Winter')),
    year int(4) CHECK (year >= 1897),
    grade numeric(2,1) CHECK (grade >= 0 and grade <= 5.0),
    primary key(ID, courseID, secID, semester, year),
    foreign key (ID) references student(ID),
    foreign key (courseID) references course(courseID)
);

create table teaches
(
    ID int(4) ZEROFILL UNSIGNED NOT NULL,
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester varchar(6) CHECK (semester in ('Spring', 'Summer', 'Fall', 'Winter')),
    year int(4) CHECK (year >= 1897),
    primary key(ID, courseID, semester, year),
    foreign key(ID) references teacher(ID),
    foreign key (courseID) references course(courseID)
);

create table classromm
(
    building varchar(30),
    roomNo int,
    capacity int,
    primary key(building, roomNo)
);

create table timeSlot
(
    timeSlotID int,
    day char(3) CHECK(day in ('Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun')),
    startTime time,
    endTime time,
    primary key(timeSlotID, day, startTime)
);
