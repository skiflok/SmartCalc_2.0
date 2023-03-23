#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "../controller/controller.h"
#include "credit_view/creditview.h"
#include "deposit_viev/depositview.h"
#include "../qcustomplot.h"

#include <QMainWindow>
#include <QVector>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QDebug>

#include <string>

using namespace s21;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Controller *controller;
  CreditView *credit_view{};
  DepositView *deposit_view{};

 private
  slots:
  void ButtonListener();
  void FunctionListener();

  void on_clear_clicked();
  void on_calcculate_clicked();
  void on_plot_clicked();
  void on_credit_calc_clicked();
  void on_deposit_calc_clicked();
  void on_const_pi_clicked();
};
#endif // MAINWINDOW_H
