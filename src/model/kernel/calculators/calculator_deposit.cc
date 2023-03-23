
#include "calculator_deposit.h"

s21::DataDeposit &s21::CalculatorDeposit::DepositCalculation(
    s21::DataDeposit &data_deposit) {
  double out_total{};
  double out_total_percent{};
  double out_total_tax{};
  double input_deposit{};
  int periodicity_of_capitalization{};
  int T{};

  constexpr double AVERAGE_DAYS_IN_MONTH = 30.416666666666667851;

  input_deposit = data_deposit.input_deposit_ + data_deposit.rep_minus_with_;

  if (data_deposit.capitalization_ == NO) {
    out_total_percent =
        input_deposit * data_deposit.input_percent_ *
        (data_deposit.input_term_ * AVERAGE_DAYS_IN_MONTH / 365) / 100;
    out_total = input_deposit + out_total_percent;
  } else {
    switch (data_deposit.periodicity_) {
      case DAY:
        periodicity_of_capitalization = 365;
        T = (int)(data_deposit.input_term_ * AVERAGE_DAYS_IN_MONTH);
        break;
      case MONTH:
        periodicity_of_capitalization = 12;
        T = data_deposit.input_term_;
        break;
      case CUARTER:
        periodicity_of_capitalization = 4;
        T = data_deposit.input_term_ / periodicity_of_capitalization;
        break;
      default:
        break;
    }

    out_total = input_deposit * pow((1 + (data_deposit.input_percent_ / 100) /
                                             periodicity_of_capitalization),
                                    T);
    out_total_percent = out_total - input_deposit;
  }

  double non_taxable_income = data_deposit.input_tax_ / 100 * 1000000;

  if (out_total_percent > non_taxable_income) {
    out_total_tax = (out_total_percent - non_taxable_income) * 0.13;
    out_total_percent -= out_total_tax;
  }

  data_deposit.out_total_ = round(out_total * 100) / 100;
  data_deposit.out_total_percent_ = round(out_total_percent * 100) / 100;
  data_deposit.out_total_tax_ = round(out_total_tax * 100) / 100;

  return data_deposit;
}
