//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_

#include <list>

#include "../../view/data/data_plot.h"
#include "calculator.h"

#define EPS 1e-7

namespace s21 {

class CalculatorPlot : public Calculator {
 public:
  //  CalculatorPlot(const DataPlot &data_plot,
  //                 std::queue<std::string> rpn_expression)
  //      : data_plot_(data_plot) {
  //    // потом лучше в родителе поменять на лист
  //    for (auto i = 0; !rpn_expression.empty(); ++i) {
  //      rpn_expression_list_.push_back(rpn_expression.front());
  //      rpn_expression.pop();
  //    }
  //    CalculateStepSize();
  //  }

  std::pair<std::vector<double>, std::vector<double>> PlotCalculation(
      const DataPlot &data_plot, std::queue<std::string> rpn_expression);

 private:
  //  DataPlot data_plot_;
  //  std::queue<std::string> rpn_expression_;
  //  std::list<std::string> rpn_expression_list_{};
  //  double step_size_{};

  void GetDigitFromRpn(const std::string &token, const double &xValue,
                       std::stack<double> &numbers);
  double CalculateStepSize(const DataPlot &data_plot);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
