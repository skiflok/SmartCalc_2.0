#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "credit_view/creditview.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {

  ui->setupUi(this);

  connect(ui->num_0, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_1, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_2, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_3, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_4, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_5, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_6, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_7, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_8, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->num_9, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->point, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_plus, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_minus, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_mult, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_div, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_mod, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_degree, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_bracket_o, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->operand_bracket_c, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->graf_x, SIGNAL(clicked()), this, SLOT(ButtonListener()));
//  connect(ui->const_pi, SIGNAL(clicked()), this, SLOT(ButtonListener()));
  connect(ui->const_e, SIGNAL(clicked()), this, SLOT(ButtonListener()));

  connect(ui->func_ln, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->func_log, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_sin, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_cos, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_tan, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_asin, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_acos, SIGNAL(clicked()), this, SLOT(FunctionListener()));
  connect(ui->trigonometry_atan, SIGNAL(clicked()), this, SLOT(FunctionListener()));


}

MainWindow::~MainWindow() {
  delete ui;
}


void MainWindow::ButtonListener() {

  QPushButton *button = (QPushButton *)sender();
  qDebug() << "clic " << button->text();

  QString new_label = "";
  ui->text_label->setText(ui->text_label->text() + button->text());
  new_label = ui->text_label->text();

  qDebug() << "ui->text_label =  " << new_label;

}


void MainWindow::FunctionListener() {

  QPushButton *button = (QPushButton *)sender();
  qDebug() << "clic " << button->text();

  QString new_label = "";
  ui->text_label->setText(ui->text_label->text() + button->text() + "(");
  new_label = ui->text_label->text();

  qDebug() << "ui->text_label =  " << new_label;

}

void MainWindow::on_const_pi_clicked() {
    qDebug() << "clic pi";
    ui->text_label->setText(ui->text_label->text() + "3.141592");
}

void MainWindow::on_clear_clicked() {
  qDebug() << "clic clear";
  ui->text_label->setText("");
}

void MainWindow::on_calcculate_clicked() {

    qDebug() << "on_calcculate_clicked";

    double res{};
      QString inputStr = ui->text_label->text();
      try {
          qDebug() << "try res =  controller->Calculation(inputStr)";
          res =  controller->Calculation(inputStr);
          inputStr = QString::number(res, 'g', 15);
          ui->text_label->setText(inputStr);
          qDebug() << "res = " << res;
      } catch (const std::exception& e) {
          qDebug() << "catch" << e.what();
          ui->text_label->setText(e.what());
      }
}

void MainWindow::on_plot_clicked() {

  qDebug() << "on_plot_clicked";

  ui->widget->clearGraphs();

  DataPlot data_plot_input(ui->text_label->text().toStdString(),
           ui->lineEdit_x_min->text().toDouble(),
           ui->lineEdit_x_max->text().toDouble());

  std::pair<QVector<double>, QVector<double>> data_plot;

    ui->widget->xAxis->setRange(data_plot_input.x_begin_, data_plot_input.x_end_);
    ui->widget->yAxis->setRange(ui->lineEdit_y_min->text().toDouble(), ui->lineEdit_y_max->text().toDouble());

    try {
        qDebug() << "try calculate";
        data_plot = controller->PlotCalculation(data_plot_input);
        ui->widget->addGraph();
        ui->widget->graph(0)->addData(data_plot.first, data_plot.second);
        ui->widget->replot();
        qDebug() << "calculate sucsess";
    } catch (std::exception &e) {
        qDebug() << "catch" << e.what();
        ui->text_label->setText(e.what());
    }
}



void MainWindow::on_credit_calc_clicked() {
    if (credit_view != nullptr) {
        credit_view->~CreditView();
        credit_view = nullptr;
    }
    credit_view = new CreditView(this);
    credit_view->show();
}

void MainWindow::on_deposit_calc_clicked() {

    if (deposit_view != nullptr) {
        deposit_view->~DepositView();
        deposit_view = nullptr;
    }
    deposit_view = new DepositView(this);
      deposit_view->show();
}




