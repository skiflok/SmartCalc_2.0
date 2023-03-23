#ifndef DEPOSITVIEW_H
#define DEPOSITVIEW_H

#include <QDialog>

#include "../controller/controller.h"

using namespace s21;

namespace Ui {
class DepositView;
}

class DepositView : public QDialog
{
    Q_OBJECT

public:
    explicit DepositView(QWidget *parent = nullptr);
    ~DepositView();

private slots:
    void on_but_get_solution_clicked();

    void on_but_add_rep_clicked();

    void on_but_del_rep_clicked();

    void on_but_with_add_clicked();

    void on_but_with_del_clicked();

private:
    Ui::DepositView *ui;
    Controller *controller_;
};

#endif // DEPOSITVIEW_H
