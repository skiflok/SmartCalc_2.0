#ifndef GOOGLE_TESTS_SRC_CONTROLLER_CONTROLLER_H_
#define GOOGLE_TESTS_SRC_CONTROLLER_CONTROLLER_H_

#include "../Model/Model.h"

namespace s21 {
class Controller {
 public:
  Controller(std::string input_string) : model_(input_string) {}

  std::pair<int, double> calculateSimpleExpression() {
    return model_.calculateSimpleExpression();
  }

  double calculateExpressionForGraph();
  double calculateCredit();
  double calculateDebit();
  std::string getString() { return model_.getString(); }

 private:
  Model model_;
};
}  // namespace s21

#endif  // GOOGLE_TESTS_SRC_CONTROLLER_CONTROLLER_H_
