
#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_

#include <list>

#include "calculator.h"
#include "../../data/data_plot.h"

#define EPS 1e-7

namespace s21 {

class CalculatorPlot : public Calculator {
 public:
  std::pair<std::vector<double>, std::vector<double>> PlotCalculation(
	  const DataPlot &data_plot, std::list<std::string> rpn_expression);

 private:
  void GetDigitFromRpn(const std::string &token, const double &xValue,
					   std::stack<double> &numbers);
  double CalculateStepSize(const DataPlot &data_plot);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_CALCULATOR_PLOT_H_
