#-------------------------------------------------
#
# Project created by QtCreator 2016-06-10T10:31:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourseSystem
TEMPLATE = app


SOURCES += main.cpp\
    logindialog.cpp \
    student.cpp \
    teacher.cpp \
    manager.cpp \
    administrator.cpp \
    course.cpp \
    section.cpp \
    user.cpp \
    Ustudent.cpp \
    Uteacher.cpp

HEADERS  += \
    logindialog.h \
    student.h \
    teacher.h \
    manager.h \
    administrator.h \
    course.h \
    section.h \
    user.h \
    Ustudent.h \
    Uteacher.h

FORMS    += \
    logindialog.ui \
    student.ui \
    teacher.ui \
    manager.ui

RESOURCES += \
    src.qrc
QT +=sql
UI_DIR=./UI
