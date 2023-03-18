//
// Created by Tysane Norine on 3/17/23.
//

#ifndef GOOGLE_TESTS_SRC_VIEW_CREDIT_H_
#define GOOGLE_TESTS_SRC_VIEW_CREDIT_H_

namespace Ui {
class credit;
}

class credit : public QDialog
{
  Q_OBJECT

 public:
  explicit credit(QWidget *parent = nullptr);
  ~credit();

 private slots:
	  void on_calculate_clicked();

 private:
  Ui::credit *ui;
  s21::Controller controller_{};
};


#endif //GOOGLE_TESTS_SRC_VIEW_CREDIT_H_
