#ifndef CREDITVIEW_H
#define CREDITVIEW_H

#include <QDialog>

#include "../controller/controller.h"

using namespace s21;

namespace Ui {
class CreditView;
}

class CreditView : public QDialog
{
    Q_OBJECT

public:
    explicit CreditView(QWidget *parent = nullptr);
    ~CreditView();

private slots:
    void on_solution_clicked();

private:
    Ui::CreditView *ui;
    Controller *controller;
};

#endif // CREDITVIEW_H
