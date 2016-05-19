# administrator
INSERT INTO user(ID, type, password) values (0, 'administrator', UNHEX(MD5('admin')));
INSERT INTO administrator(ID, name) values (0, 'admin');

# teacher
INSERT INTO user(ID, type) values (1, 'teacher');
INSERT INTO teacher(ID, name, deptName) values (1, 'Turing', 'Comp. Sci.');

INSERT INTO user(ID, type) values (2, 'teacher');
INSERT INTO teacher(ID, name, deptName) values (2, 'Newton', 'Physics');

INSERT INTO user(ID, type) values (3, 'teacher');
INSERT INTO teacher(ID, name, deptName) values (3, 'Tchaikovsky', 'Music');

INSERT INTO user(ID, type) values (4, 'teacher');
INSERT INTO teacher(ID, name, deptName) values (4, 'Socrates', 'Philosophy');

INSERT INTO user(ID, type) values (5, 'teacher');
INSERT INTO teacher(ID, name, deptName) values (5, 'Guass', 'Math');

# student
INSERT INTO user(ID, type) values (123456, 'student');
INSERT INTO student(ID, name, birthday, gender, deptName) values(123456, 'Stephen Tse', '1996-02-01', 'male', 'Comp. Sci.');

INSERT INTO user(ID, type) values (123457, 'student');
INSERT INTO student(ID, name, deptName) values(123457, 'Foo Bar', 'Comp. Sci.');

INSERT INTO user(ID, type) values (123458, 'student');
INSERT INTO student(ID, name, deptName) values(123458, 'Plato', 'Philosophy');

INSERT INTO user(ID, type) values (123459, 'student');
INSERT INTO student(ID, name, deptName) values(123459, 'Chopin', 'Music');

INSERT INTO user(ID, type) values (123460, 'student');
INSERT INTO student(ID, name, deptName) values(123460, 'Fermat', 'Math');

INSERT INTO user(ID, type) values (123461, 'student');
INSERT INTO student(ID, name, deptName) values(123461, 'Einstein', 'Physics');

# course
INSERT INTO course(courseID, title, deptName, credits) values(100000, 'Calculus', 'Math', 4.0);
INSERT INTO course(courseID, title, deptName, credits) values(100001, 'Linear Algebra', 'Math', 2.5);
INSERT INTO course(courseID, title, deptName, credits) values(100002, 'Object-oriented Programming', 'Comp. Sci.', 2.5);
INSERT INTO course(courseID, title, deptName, credits) values(100003, 'Data Structure', 'Comp. Sci.', 2.5);
INSERT INTO course(courseID, title, deptName, credits) values(100004, 'Algorithms', 'Comp. Sci.', 2.5);
INSERT INTO course(courseID, title, deptName, credits) values(100005, 'Western Music', 'Music', 1.5);
INSERT INTO course(courseID, title, deptName, credits) values(100006, 'Database System', 'Comp. Sci.', 1.5);
INSERT INTO course(courseID, title, deptName, credits) values(100007, 'Basic Physics', 'Physics', 4.0);
INSERT INTO course(courseID, title, deptName, credits) values(100008, 'Electricity and Magnetism', 'Physics', 2.5);
INSERT INTO course(courseID, title, deptName, credits) values(100009, 'Basic Philosophy', 'Philosophy', 4.0);

# section
INSERT INTO section values(100000, 1, 'Spring', 2016, 100, 80, 'West 1', '105', 1);
INSERT INTO section values(100000, 2, 'Spring', 2016, 100, 90, 'West 2', '201', 2);

INSERT INTO section values(100001, 1, 'Summer', 2016, 80, 80, 'East 1', '303', 3);

INSERT INTO section values(100002, 1, 'Fall', 2016, 80, 66, 'East 2', '303', 4);

INSERT INTO section values(100003, 1, 'Fall', 2016, 80, 66, 'East 2', '304', 3);

INSERT INTO section values(100004, 1, 'Fall', 2016, 80, 78, 'East 2', '304', 3);

INSERT INTO section values(100005, 1, 'Fall', 2016, 40, 40, 'West 2', '205', 5);

INSERT INTO section values(100006, 1, 'Winter', 2016, 40, 40, 'East 4', '509', 6);

INSERT INTO section values(100007, 1, 'Winter', 2016, 40, 40, 'East 4', '511', 7);

INSERT INTO section values(100008, 1, 'Summer', 2016, 60, 45, 'West 2', '216', 7);

INSERT INTO section values(100009, 1, 'Summer', 2016, 120, 120, 'West 1', '102', 5);

# takes
INSERT INTO takes(ID, courseID, secID, semester, year, grade) values(123456, 100000, 1, 'Spring', 2016, 5.0);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123456, 100001, 1, 'Summer', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123456, 100002, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123456, 100005, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123456, 100008, 1, 'Summer', 2016);

INSERT INTO takes(ID, courseID, secID, semester, year) values(123457, 100000, 2, 'Summer', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123457, 100003, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123457, 100004, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123457, 100006, 1, 'Winter', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123457, 100007, 1, 'Winter', 2016);

INSERT INTO takes(ID, courseID, secID, semester, year) values(123458, 100000, 2, 'Summer', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123458, 100004, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123458, 100006, 1, 'Winter', 2016);

INSERT INTO takes(ID, courseID, secID, semester, year) values(123459, 100005, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123459, 100007, 1, 'Winter', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123459, 100008, 1, 'Summer', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123459, 100009, 1, 'Summer', 2016);

INSERT INTO takes(ID, courseID, secID, semester, year, grade) values(123460, 100000, 1, 'Spring', 2016, 4.0);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123460, 100009, 1, 'Summer', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123460, 100005, 1, 'Fall', 2016);
INSERT INTO takes(ID, courseID, secID, semester, year) values(123460, 100004, 1, 'Fall', 2016);

# teaches
INSERT INTO teaches values(5, 100000, 1, 'Spring', 2016);
INSERT INTO teaches values(5, 100000, 2, 'Summer', 2016);
INSERT INTO teaches values(5, 100001, 1, 'Summer', 2016);
INSERT INTO teaches values(1, 100002, 1, 'Fall', 2016);
INSERT INTO teaches values(1, 100003, 1, 'Fall', 2016);
INSERT INTO teaches values(1, 100004, 1, 'Fall', 2016);
INSERT INTO teaches values(3, 100005, 1, 'Fall', 2016);
INSERT INTO teaches values(1, 100006, 1, 'Winter', 2016);
INSERT INTO teaches values(2, 100007, 1, 'Winter', 2016);
INSERT INTO teaches values(2, 100008, 1, 'Summer', 2016);
INSERT INTO teaches values(4, 100009, 1, 'Summer', 2016);

# timeSlot
INSERT INTO timeSlot values(1, 'Mon', '08:00:00', '09:35:00');
INSERT INTO timeSlot values(2, 'Tue', '09:50:00', '12:15:00');
INSERT INTO timeSlot values(3, 'Wed', '13:15:00', '15:40:00');
INSERT INTO timeSlot values(4, 'Thu', '18:30:00', '20:05:00');
INSERT INTO timeSlot values(5, 'Fri', '15:50:00', '17:30:00');
INSERT INTO timeSlot values(6, 'Wed', '08:00:00', '09:35:00');
INSERT INTO timeSlot values(7, 'Tue', '08:00:00', '09:35:00');
