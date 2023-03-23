#include "creditview.h"
#include "ui_creditview.h"

CreditView::CreditView(QWidget *parent) : QDialog(parent), ui(new Ui::CreditView) {
    ui->setupUi(this);
    ui->input_credit_body->setValidator(new QDoubleValidator(this));
    ui->input_credit_term->setValidator(new QDoubleValidator(this));
    ui->input_percent->setValidator(new QDoubleValidator(this));
}

CreditView::~CreditView() {
    delete ui;
}



void CreditView::on_solution_clicked() {


    // ____INPUT____
    TypeOfCredit type_credit = (ui->type_ayt->isChecked()) ? ANNUITY : DIFFERENTIATED;
    double input_credit_body = ui->input_credit_body->text().toDouble();
    int input_credit_term = ui->input_credit_term->text().toInt();
    double input_percent = ui->input_percent->text().toDouble();

    ui->out_term_list->clear();

    s21::DataCredit data_credit(type_credit,
                                input_credit_body,
                                input_credit_term,
                                input_percent);

    data_credit = controller->CreditCalculation(data_credit);

    // ____OUTPUT____
    std::vector<double> output_monthly_payment = data_credit.output_monthly_payment_;
    double output_overpayment_loan = data_credit.output_overpayment_loan_;
    double output_final_payment = data_credit.output_final_payment_;

    if (type_credit == ANNUITY) {
      ui->out_total_playment->setText(QString::number(output_final_payment, 'g', 20));
      ui->out_overpayment->setText(QString::number(output_overpayment_loan, 'g', 20));

      for(int i = 1; i <= input_credit_term; i++) {
        ui->out_term_list->addItem(QString::number(i, 'g', 20) + " month: " + QString::number(output_monthly_payment.at(i-1), 'g', 20));
      }

    } else if (type_credit == DIFFERENTIATED) {
      ui->out_total_playment->setText(QString::number(output_final_payment, 'g', 20));
      ui->out_overpayment->setText(QString::number(output_overpayment_loan, 'g', 20));

      for(int i = 1; i <= input_credit_term; i++) {
        ui->out_term_list->addItem(QString::number(i, 'g', 20)  + " month: " + QString::number(output_monthly_payment.at(i - 1), 'g', 20));
      }
    }



}

