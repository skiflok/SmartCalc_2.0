#include "depositview.h"
#include "ui_depositview.h"
#include <QDebug>
#include <QMessageBox>
#include "model/data/data_deposit.h"
#include <cmath>

using namespace s21;

DepositView::DepositView(QWidget *parent) : QDialog(parent), ui(new Ui::DepositView) {
    ui->setupUi(this);
    ui->input_deposit->setValidator(new QDoubleValidator(this));
    ui->input_term->setValidator(new QIntValidator(this));
    ui->input_percent->setValidator(new QDoubleValidator(this));
    ui->input_rep_add_line->setValidator(new QDoubleValidator(this));
    ui->input_tax->setValidator(new QDoubleValidator(this));
    ui->input_with_add_line->setValidator(new QDoubleValidator(this));
}

DepositView::~DepositView() {
    delete ui;
}

void DepositView::on_but_get_solution_clicked(){

    //----INPUT----
    Periodicity periodicity;
    Capitalization capitalization;


    if (ui->set_period->currentText() == "Ежедневно") {
        periodicity = DAY;
    } else if (ui->set_period->currentText() == "Ежемесячно") {
        periodicity = MONTH;
    } else if (ui->set_period->currentText() == "Квартально") {
        periodicity = CUARTER;
    }



    capitalization = ui->set_capitalization->currentText() == "Да" ? YES : NO;


    double input_deposit = ui->input_deposit->text().toDouble();
    int input_term = ui->input_term->text().toInt();
    double input_percent = ui->input_percent->text().toDouble();
    double input_tax = ui->input_tax->text().toDouble();
    double input_rep_add_sum = 0;
    double input_with_add_sum = 0;

    double rep_minus_with = 0;

    while (ui->out_rep_history->count() >0) {
        input_rep_add_sum += ui->out_rep_history->takeItem(ui->out_rep_history->count()-1)->text().toDouble();
        qDebug() << "input_rep_add_sum" << input_rep_add_sum;
    }
    ui->out_rep_total_line->setText(QString::number(input_rep_add_sum));

    while (ui->out_with_history->count() >0) {
        input_with_add_sum += ui->out_with_history->takeItem(ui->out_with_history->count()-1)->text().toDouble();
        qDebug() << "input_with_add_sum" << input_with_add_sum;
    }
    ui->out_total_with_line->setText(QString::number(input_with_add_sum));


    rep_minus_with = input_rep_add_sum - input_with_add_sum;

    qDebug() << "rep_minus_with" << rep_minus_with;


    DataDeposit data_deposit(
                          periodicity,
                          capitalization,
                          input_deposit,
                          input_term,
                          input_percent,
                          input_tax,
                          rep_minus_with);


    //----CALCULATION----


    data_deposit = controller_->DepositCalculation(data_deposit);


    //----OUTPUT----

    ui->out_total_line->setText(QString::number(data_deposit.out_total_, 'g', 15));
    ui->out_total_percent->setText(QString::number(data_deposit.out_total_percent_, 'g', 15));
    ui->out_total_tax->setText(QString::number(data_deposit.out_total_tax_, 'g', 15));
}




void DepositView::on_but_add_rep_clicked(){
    ui->out_rep_history->addItem(ui->input_rep_add_line->text());

}


void DepositView::on_but_del_rep_clicked() {
    if (ui->out_rep_history->count() != 0) {
        ui->out_rep_history->takeItem(ui->out_rep_history->count() - 1)->text();
    }
}


void DepositView::on_but_with_add_clicked(){
        ui->out_with_history->addItem(ui->input_with_add_line->text());
}


void DepositView::on_but_with_del_clicked(){
    if (ui->out_with_history->count() != 0) {
        ui->out_with_history->takeItem(ui->out_with_history->count() - 1)->text();
    }
}





