//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_

#include "../../view/data/data_plot.h"
#include "calculator.h"

namespace s21 {

class CalculatorPlot : public Calculator {
 public:
  CalculatorPlot(const DataPlot &data_plot,
                 const std::queue<std::string> &rpn_expression)
      : data_plot_(data_plot), rpn_expression_(rpn_expression) {}

  std::pair<std::vector<double>, std::vector<double>> PlotCalculation() {

    // TODO function

    // TODO try catch

    return std::pair<std::vector<double>, std::vector<double>>();
  }

 private:
  DataPlot data_plot_;
  std::queue<std::string> rpn_expression_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
