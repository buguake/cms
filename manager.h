#ifndef MANAGER_H
#define MANAGER_H

#include <QMainWindow>
#include"administrator.h"

namespace Ui {
class manager;
}

class manager : public QMainWindow
{
    Q_OBJECT

public:
    Administrator admi;
    explicit manager(QWidget *parent = 0, int ID = -1, const string &password = "");
    ~manager();

private:
    Ui::manager *ui;
private slots:
    void on_studentaddbutton_click();
    void on_studentsearchbutton_click();
    void on_studentwidget_click(int, int);
    void on_teacheraddbutton_click();
    void on_teachersearchbutton_click();
    void on_teacherwidget_click(int, int);
    void on_courseaddbutton_click();
    void on_coursesearchbutton_click();
    void on_coursewidget_click(int, int);
    void on_sectionaddbutton_click();
    void on_sectionsearchbutton_click();
    void on_sectionwidget_click(int, int);
    void on_admaddbutton_click();
    void on_admsearchbutton_click();
    void on_admwidget_click(int, int);
};

#endif // MANAGER_H
