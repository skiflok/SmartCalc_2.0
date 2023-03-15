//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_

#include <queue>
#include <string>
#include <vector>

#include "../view/data/data_credit.h"
#include "../view/data/data_deposit.h"
#include "../view/data/data_plot.h"
#include "./kernel/calculator.h"
#include "./kernel/calculator_plot.h"
#include "./kernel/parser.h"
#include "./kernel/validator.h"

namespace s21 {

class Model {
 public:
  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @return результат расчета
   */
  double Calculation(std::string &expression) {
    if (validator_.IsNotValid(expression)) {
      throw std::invalid_argument("Invalid input");
    }
    std::queue<std::string> queueRpn = parser_.GetRpn(expression);

    double result{};
    try {
      result = calculator_.Calculate(queueRpn);
    } catch (...) {
      throw std::invalid_argument("Calculation error");
    }
    return result;
  }

  double Calculation(std::string &expression, double &x) { return 0; }

  /**
   *
   * @param data_plot
   * @return
   */
  std::pair<std::vector<double>, std::vector<double>> PlotCalculation(
      const DataPlot &data_plot) {
//    if (validator_.IsNotValid(data_plot.expression_)) {
//      throw std::invalid_argument("Invalid input");
//    }

    std::queue<std::string> rpn_expression = parser_.GetRpn(data_plot.expression_);
    //        (data_plot,parser_.GetRpn(data_plot.expression_));

    std::pair<std::vector<double>, std::vector<double>> res;

    try {
      res = calculator_plot_.PlotCalculation(data_plot, rpn_expression);
    } catch (...) {
      throw;
    }

    return res;
  }

  DataCredit CreditCalculation(DataCredit &data_credit);

  DataDeposit DebitCalculation(DataDeposit &data_deposit);

 private:
  Validator validator_;
  Parser parser_;
  Calculator calculator_;
  CalculatorPlot calculator_plot_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
