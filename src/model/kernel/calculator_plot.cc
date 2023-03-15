//
// Created by Violator Emilie on 3/14/23.
//

#include "calculator_plot.h"

#include <cmath>
#include <iostream>

// надо вместо очереди rpn_expression_ использовать лист, так как в очереди нет
// итераторов и она в первом же цикле обнуляется
std::pair<std::vector<double>, std::vector<double>>
s21::CalculatorPlot::PlotCalculation() {
  std::vector<double> X{}, Y{};
  for (auto xValue = data_plot_.x_begin_; xValue < data_plot_.x_end_;
       xValue += step_size_) {


    double yValue = 0.0;
    std::stack<double> numbers{};
    if (fabs(xValue) < EPS) {  // нужно при нуле
      xValue = 0.0;
    }
    for (auto token : rpn_expression_list_) {
      GetDigitFromRpn(token, xValue);
      if (token == "+" || token == "-" || token == "*" || token == "/" ||
          token == "^" || token == "m") {
        BinaryFunc(token, numbers);
      } else if (isalpha(token.front()) && token != "x") {
        UnaryFunc(token, numbers);
      }
    }
    yValue = numbers_.top();
    if (!isfinite(yValue)) throw std::invalid_argument("value is infinite");
    X.push_back(xValue);
    Y.push_back(yValue);
  }
  return {X, Y};
}

void s21::CalculatorPlot::GetDigitFromRpn(const std::string &token,
                                          const double &xValue) {
  if (isdigit(token.front())) {
    numbers_.push(std::stod(token));
  } else if (token == "x") {
    numbers_.push(xValue);
  }
}

void s21::CalculatorPlot::CalculateStepSize() {
  double x_begin = abs(data_plot_.x_begin_);
  double x_end = abs(data_plot_.x_end_);
  step_size_ = static_cast<double>((x_begin + x_end) * 0.01);
}