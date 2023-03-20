//
// Created by Tysane Norine on 3/20/23.
//

#ifndef GOOGLE_TESTS_SRC_VIEW_DEBIT_H_
#define GOOGLE_TESTS_SRC_VIEW_DEBIT_H_


#include <QDialog>
#include "../model/data/data_deposit.h"
#include "../controller/controller.h"

namespace Ui {
class debit;
}

class debit : public QDialog
{
  Q_OBJECT

 public:
  explicit debit(QWidget *parent = nullptr);
  ~debit();

 private slots:
	  void on_pushButton_calculate_clicked();

  double on_pushButton_del_clicked();

  void on_pushButton_add_clicked();

  double on_pushButton_del_2_clicked();

  void on_pushButton_add_2_clicked();

 private:
  Ui::debit *ui;
  s21::Controller controller_;
};


#endif //GOOGLE_TESTS_SRC_VIEW_DEBIT_H_
