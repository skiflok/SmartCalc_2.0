//
// Created by Tysane Norine on 3/20/23.
//

#ifndef GOOGLE_TESTS_SRC_MODEL_KERNEL_CALCULATOR_DEBIT_H_
#define GOOGLE_TESTS_SRC_MODEL_KERNEL_CALCULATOR_DEBIT_H_

#include <cmath>
#include "../../view/data/data_deposit.h"


constexpr double AVERAGE_DAYS = 30.416666666666667851;
constexpr double NDFL = 13.00/100.00;

namespace s21 {

class CalculatorDebit {
 public:
  DataDeposit &DebitCalculation(DataDeposit &data_deposit) {
	double part_for_tax{};
	// ____INPUT____
	double& input_contribution_amount =  data_deposit.input_contribution_amount_;   // сумма вклада // lineEdit_sum_dep
	int& input_period_of_placement =  data_deposit.input_period_of_placement_;     // срок размещения // lineEdit_period
	PeriodicityPayments& input_periodicity_payments =  data_deposit.input_periodicity_payments_; // периодичность выплат // comboBox_peiod_of_pay
	double &input_interest_rate =  data_deposit.input_interest_rate_;   // процентная ставка // lineEdit_rate
	double& input_tax_rate = data_deposit.input_tax_rate_;  // налоговая ставка // lineEdit_tax
	input_tax_rate = input_tax_rate * 1000000 / 100;
	Capitalization &iput_apitalization = data_deposit.iput_apitalization_ ; // капитализация // comboBox_capital
	std::vector<double> &input_refills = data_deposit.input_refills_;    // пополнения // listWidget_add
	std::vector<double> &input_withdrawals = data_deposit.input_withdrawals_;  // снятия // listWidget_sub

	// ____OUTPUT____
	double& output_total_refills = data_deposit.output_total_refills_;      // сумма пополнения // lineEdit_add_all // add_all
	double& output_total_withdrawals = data_deposit.output_total_withdrawals_;  // сумма снятия // lineEdit_sub_all // sub_all
	double& output_interest_charges = data_deposit.output_interest_charges_;  // начисленные проценты // lineEdit_percents // percents
	double& output_tax_amount = data_deposit.output_tax_amount_;        // сумма налога // lineEdit_tax_sum // tax_sum
	double& output_total_deposit_amount = data_deposit.output_total_deposit_amount_;  // сумма вклада к концу срока // lineEdit_total_sum_dep // total

	// ____CALCULATION____
	for (auto refill : input_refills) {
	  output_total_refills += refill;
	}
	input_contribution_amount += output_total_refills;

	for (auto withdrawal : input_withdrawals) {
	  output_total_withdrawals += withdrawal;
	}
	input_contribution_amount -= output_total_withdrawals;

	if (iput_apitalization == MONTHLY_CAP) {
	  output_interest_charges = (input_contribution_amount * pow((1 + (input_interest_rate/100) /12), input_period_of_placement)) - input_contribution_amount;
	} else {
	  output_interest_charges = (input_contribution_amount * input_interest_rate * input_period_of_placement * AVERAGE_DAYS_IN_MONTH / 365) / 100;
	}
	part_for_tax = output_interest_charges - input_tax_rate;

	if (part_for_tax > 0 && input_tax_rate) {
	  output_tax_amount = part_for_tax * NDFL;
	} else {
	  output_tax_amount = 0;
	}

	if (input_periodicity_payments == MONTHLY) {
	  output_total_deposit_amount = input_contribution_amount;
	} else {
	  output_total_deposit_amount = input_contribution_amount + output_interest_charges - output_tax_amount;
	}

	output_total_deposit_amount = round(output_total_deposit_amount);
	output_interest_charges = round(output_interest_charges);

	return data_deposit;
  }

};
}  // namespace s21
#endif //GOOGLE_TESTS_SRC_MODEL_KERNEL_CALCULATOR_DEBIT_H_
