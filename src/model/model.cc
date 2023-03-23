
#include "model.h"
double s21::Model::Calculation(std::string &expression) {
  try {
    if (validator_.IsNotValid(expression)) {
      throw std::invalid_argument("error: Invalid input");
    }
  } catch (...) {
    throw;
  }

  std::list<std::string> listRpn = parser_.ExpressionToRpn(expression);

  double result{};
  try {
    result = calculator_.Calculate(listRpn);
  } catch (...) {
    throw;
  }
  return result;
}
std::pair<std::vector<double>, std::vector<double>> s21::Model::PlotCalculation(
    const s21::DataPlot &data_plot) {
  if (validator_.IsNotValid(data_plot.expression_)) {
    throw std::invalid_argument("error: Invalid input");
  }

  std::list<std::string> rpn_expression =
      parser_.ExpressionToRpn(data_plot.expression_);

  std::pair<std::vector<double>, std::vector<double>> res;

  try {
    res = calculator_plot_.PlotCalculation(data_plot, rpn_expression);
  } catch (...) {
    throw;
  }

  return res;
}
