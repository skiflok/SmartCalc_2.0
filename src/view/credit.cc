#include "credit.h"
#include "ui_credit.h"
#include "mainwindow.h"

credit::credit(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::credit)
{
  ui->setupUi(this);
  ui->lineEdit_sum_credit->setValidator(new QDoubleValidator(this));
  ui->lineEdit_limit->setValidator(new QDoubleValidator(this));
  ui->lineEdit_percent->setValidator(new QDoubleValidator(this));
}

credit::~credit() {
  delete ui;
}

void credit::on_calculate_clicked() {
  // ____INPUT____
  TypeOfCredit input_type_of_credit = (ui->annuit->isChecked()) ? ANNUITY : DIFFERENTIATED;
  double input_total_credit = ui->lineEdit_sum_credit->text().toDouble(); // sum
  int input_term_in_months = ui->lineEdit_limit->text().toInt(); // months
  double input_interest_rate = ui->lineEdit_percent->text().toDouble(); // rate / 12 / 100;

  ui->listWidget_pay->clear();

  s21::DataCredit data_credit(input_type_of_credit, input_total_credit, input_term_in_months, input_interest_rate);

  data_credit = controller_.CreditCalculation(data_credit);

  // ____OUTPUT____
  std::vector<double> output_monthly_payment = data_credit.output_monthly_payment_;
  double output_overpayment_loan = data_credit.output_overpayment_loan_;
  double output_final_payment = data_credit.output_final_payment_;


  if (input_type_of_credit == ANNUITY) {
	ui->lineEdit_total_sum->setText(QString::number(output_final_payment, 'g', 20));
	ui->lineEdit_overpayment->setText(QString::number(output_overpayment_loan, 'g', 20));

	for(int i = 1; i <= input_term_in_months; i++) {
	  ui->listWidget_pay->addItem(QString::number(i, 'g', 20) + " month: " + QString::number(output_monthly_payment.at(i-1), 'g', 20));
	}

  } else if (input_type_of_credit == DIFFERENTIATED) {
	ui->lineEdit_total_sum->setText(QString::number(output_final_payment, 'g', 20));
	ui->lineEdit_overpayment->setText(QString::number(output_overpayment_loan, 'g', 20));

	for(int i = 1; i <= input_term_in_months; i++) {
	  ui->listWidget_pay->addItem(QString::number(i, 'g', 20)  + " month: " + QString::number(output_monthly_payment.at(i - 1), 'g', 20));
	}
  }

}
