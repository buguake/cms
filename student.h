#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>
#include "Ustudent.h"

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    UStudent stud;
    explicit student(QWidget *parent = 0);
    ~student();

private:
    Ui::student *ui;

private slots:
    void on_mycoursewidget_click(int,int);
    void on_searchbutton_click();
    void on_selectcoursewidget_click(int, int);
};

#endif // STUDENT_H
