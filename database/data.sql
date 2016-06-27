# Administrator
INSERT INTO User(ID, type, password) values (0, 'administrator', UNHEX(MD5('admin')));
INSERT INTO Administrator(ID, name) values (0, 'admin');

# Teacher
INSERT INTO User(ID, type) values (1, 'Teacher');
INSERT INTO Teacher(ID, name, deptName) values (1, 'Turing', 'Comp. Sci.');

INSERT INTO User(ID, type) values (2, 'Teacher');
INSERT INTO Teacher(ID, name, deptName) values (2, 'Newton', 'Physics');

INSERT INTO User(ID, type) values (3, 'Teacher');
INSERT INTO Teacher(ID, name, deptName) values (3, 'Tchaikovsky', 'Music');

INSERT INTO User(ID, type) values (4, 'Teacher');
INSERT INTO Teacher(ID, name, deptName) values (4, 'Socrates', 'Philosophy');

INSERT INTO User(ID, type) values (5, 'Teacher');
INSERT INTO Teacher(ID, name, deptName) values (5, 'Guass', 'Math');

# Student
INSERT INTO User(ID, type) values (123456, 'Student');
INSERT INTO Student(ID, name, birthday, gender, deptName) values(123456, 'Stephen Tse', '1996-02-01', 'male', 'Comp. Sci.');

INSERT INTO User(ID, type) values (123457, 'Student');
INSERT INTO Student(ID, name, deptName) values(123457, 'Foo Bar', 'Comp. Sci.');

INSERT INTO User(ID, type) values (123458, 'Student');
INSERT INTO Student(ID, name, deptName) values(123458, 'Plato', 'Philosophy');

INSERT INTO User(ID, type) values (123459, 'Student');
INSERT INTO Student(ID, name, deptName) values(123459, 'Chopin', 'Music');

INSERT INTO User(ID, type) values (123460, 'Student');
INSERT INTO Student(ID, name, deptName) values(123460, 'Fermat', 'Math');

INSERT INTO User(ID, type) values (123461, 'Student');
INSERT INTO Student(ID, name, deptName) values(123461, 'Einstein', 'Physics');

# Course
INSERT INTO Course(courseID, title, deptName, credits) values(100000, 'Calculus', 'Math', 4.0);
INSERT INTO Course(courseID, title, deptName, credits) values(100001, 'Linear Algebra', 'Math', 2.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100002, 'Object-oriented Programming', 'Comp. Sci.', 2.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100003, 'Data Structure', 'Comp. Sci.', 2.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100004, 'Algorithms', 'Comp. Sci.', 2.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100005, 'Western Music', 'Music', 1.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100006, 'Database System', 'Comp. Sci.', 1.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100007, 'Basic Physics', 'Physics', 4.0);
INSERT INTO Course(courseID, title, deptName, credits) values(100008, 'Electricity and Magnetism', 'Physics', 2.5);
INSERT INTO Course(courseID, title, deptName, credits) values(100009, 'Basic Philosophy', 'Philosophy', 4.0);

# Section
INSERT INTO Section values(100000, 1, 'Spring', 2016, 100, 80, 'West 1', '105', 1);
INSERT INTO Section values(100000, 2, 'Spring', 2016, 100, 90, 'West 2', '201', 2);

INSERT INTO Section values(100001, 1, 'Summer', 2016, 80, 80, 'East 1', '303', 3);

INSERT INTO Section values(100002, 1, 'Fall', 2016, 80, 66, 'East 2', '303', 4);

INSERT INTO Section values(100003, 1, 'Fall', 2016, 80, 66, 'East 2', '304', 3);

INSERT INTO Section values(100004, 1, 'Fall', 2016, 80, 78, 'East 2', '304', 3);

INSERT INTO Section values(100005, 1, 'Fall', 2016, 40, 40, 'West 2', '205', 5);

INSERT INTO Section values(100006, 1, 'Winter', 2016, 40, 40, 'East 4', '509', 6);

INSERT INTO Section values(100007, 1, 'Winter', 2016, 40, 40, 'East 4', '511', 7);

INSERT INTO Section values(100008, 1, 'Summer', 2016, 60, 45, 'West 2', '216', 7);

INSERT INTO Section values(100009, 1, 'Summer', 2016, 120, 120, 'West 1', '102', 5);

# Takes
INSERT INTO Takes(ID, courseID, secID, semester, year, grade) values(123456, 100000, 1, 'Spring', 2016, 5.0);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123456, 100001, 1, 'Summer', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123456, 100002, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123456, 100005, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123456, 100008, 1, 'Summer', 2016);

INSERT INTO Takes(ID, courseID, secID, semester, year) values(123457, 100000, 2, 'Summer', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123457, 100003, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123457, 100004, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123457, 100006, 1, 'Winter', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123457, 100007, 1, 'Winter', 2016);

INSERT INTO Takes(ID, courseID, secID, semester, year) values(123458, 100000, 2, 'Summer', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123458, 100004, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123458, 100006, 1, 'Winter', 2016);

INSERT INTO Takes(ID, courseID, secID, semester, year) values(123459, 100005, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123459, 100007, 1, 'Winter', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123459, 100008, 1, 'Summer', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123459, 100009, 1, 'Summer', 2016);

INSERT INTO Takes(ID, courseID, secID, semester, year, grade) values(123460, 100000, 1, 'Spring', 2016, 4.0);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123460, 100009, 1, 'Summer', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123460, 100005, 1, 'Fall', 2016);
INSERT INTO Takes(ID, courseID, secID, semester, year) values(123460, 100004, 1, 'Fall', 2016);

# Teaches
INSERT INTO Teaches values(5, 100000, 1, 'Spring', 2016);
INSERT INTO Teaches values(5, 100000, 2, 'Summer', 2016);
INSERT INTO Teaches values(5, 100001, 1, 'Summer', 2016);
INSERT INTO Teaches values(1, 100002, 1, 'Fall', 2016);
INSERT INTO Teaches values(1, 100003, 1, 'Fall', 2016);
INSERT INTO Teaches values(1, 100004, 1, 'Fall', 2016);
INSERT INTO Teaches values(3, 100005, 1, 'Fall', 2016);
INSERT INTO Teaches values(1, 100006, 1, 'Winter', 2016);
INSERT INTO Teaches values(2, 100007, 1, 'Winter', 2016);
INSERT INTO Teaches values(2, 100008, 1, 'Summer', 2016);
INSERT INTO Teaches values(4, 100009, 1, 'Summer', 2016);

# TimeSlot
INSERT INTO TimeSlot values(1, 'Mon', '08:00:00', '09:35:00');
INSERT INTO TimeSlot values(2, 'Tue', '09:50:00', '12:15:00');
INSERT INTO TimeSlot values(3, 'Wed', '13:15:00', '15:40:00');
INSERT INTO TimeSlot values(4, 'Thu', '18:30:00', '20:05:00');
INSERT INTO TimeSlot values(5, 'Fri', '15:50:00', '17:30:00');
INSERT INTO TimeSlot values(6, 'Wed', '08:00:00', '09:35:00');
INSERT INTO TimeSlot values(7, 'Tue', '08:00:00', '09:35:00');

