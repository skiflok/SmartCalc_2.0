//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_

#include <queue>
#include <string>
#include <vector>

#include "./kernel/calculators/calculator.h"
#include "./kernel/calculators/calculator_credit.h"
#include "./kernel/calculators/calculator_deposit.h"
#include "./kernel/calculators/calculator_plot.h"
#include "./kernel/parser.h"
#include "./kernel/validator.h"
#include "data/data_credit.h"
#include "data/data_deposit.h"

namespace s21 {

class Model {
 public:
  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @return результат расчета
   */
  double Calculation(std::string &expression);

  /**
   * расчет точек для построения графика
   * @param data_plot
   * @return пару векторов для построения графика
   */
  std::pair<std::vector<double>, std::vector<double>> PlotCalculation(
      const DataPlot &data_plot);

  /**
   * Расчет кредита
   * @param data_credit
   * @return структуру с данными для вью
   */
  DataCredit CreditCalculation(DataCredit &data_credit) {
    return calculator_credit_.CreditCalculation(data_credit);
  }
  /**
   * расчет депозита
   * @param data_deposit
   * @return структуру с данными для вью
   */
  DataDeposit DepositCalculation(DataDeposit &data_deposit) {
    return calculator_deposit_.DepositCalculation(data_deposit);
  }

 private:
  Validator validator_;
  Parser parser_;
  Calculator calculator_;
  CalculatorPlot calculator_plot_;
  CalculatorCredit calculator_credit_;
  CalculatorDeposit calculator_deposit_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
