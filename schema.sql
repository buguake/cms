#schema.sql
drop table user;
drop table course;
drop table section;
drop table takes;
drop table teaches;
drop table classromm;
drop table timeSlot;

create table user
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    password char(16),  # a hash value of password is appreciative
    name varchar(20) NOT NULL,
    birthday date,
    gender varchar(6) DEFAULT 'male' CHECK(gender = 'male' or gender = 'female'),
    deptName varchar(30),
    type char DEFAULT 'S' CHECK (type = 'S' or type = 'T' or type = 'A'),   # user type, S for students, T for teachers and A for administrator
    primary key(ID)
);

create table course
(
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    title varchar(30) NOT NULL,
    capacity int CHECK(capacity > 0),
    credits int,
    primary key(courseID)
);

create table section
(
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester CHECK (semester in 'Spring', 'Summer', 'Fall', 'Winter'),
    year int(4) CHECK (year >= 1897),
    building varchar(20),
    roomNo int,
    timeSlotID int,
    primary key(courseID, secID, semester, year, building),
    foreign key courseID references course(courseID)
);

create table takes
(
    ID int(6) ZEROFILL UNSIGNED NOT NULL,
    courseID int(6) ZEROFILL UNSIGNED NOT NULL,
    secID int,
    semester CHECK (semester in 'Spring', 'Summer', 'Fall', 'Winter'),
    year int(4) CHECK (year >= 1897),
    grade numeric(1,1) CHECK (grade >= 0 and grade <= 5.0),
    primary key(ID, courseID, secID, semester, year),
    foreign key ID references user(ID),
    foreign key courseID references user(courseID),
    foreign key secID references section(secID),
    foreign key semester references section(semester),
    foreign key year references section(year)
);

create table teaches
(
    # @TODO
);

create table classromm
(
    # @TODO
);

create table timeSlot
(
    # @TODO
);
