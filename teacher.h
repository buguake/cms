#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include<Uteacher.h>
namespace Ui {
class teacher;
}

class teacher : public QMainWindow
{
    Q_OBJECT

public:
    UTeacher teac;
    explicit teacher(QWidget *parent = 0);
    ~teacher();

private:
    Ui::teacher *ui;
private slots:
    void on_searchbuttonselect_click();
    void on_searchbuttonmark_click();
    void on_refresh_click();
    void on_markcoursewidget_click(int, int);
};

#endif // TEACHER_H


