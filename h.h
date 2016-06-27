#ifndef H_H
#define H_H

#include <QWidget>

namespace Ui {
class h;
}

class h : public QWidget
{
    Q_OBJECT

public:
    explicit h(QWidget *parent = 0);
    ~h();

private:
    Ui::h *ui;
};

#endif // H_H
