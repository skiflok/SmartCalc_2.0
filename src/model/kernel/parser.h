//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_

#include <iostream>
#include <queue>
#include <stack>
#include <string>

namespace s21 {

class Parser {
 public:
  explicit Parser(const std::string &expression) : expression_(expression) {}

  std::queue<std::string> GetRpn() {
    ExpressionToRpn();
    return rpn_expression_;
  }

  void ExpressionToRpn();
  void PrintExpression() const { std::cout << expression_ << std::endl; }
  void PrintRpnExpression();

 private:
  std::string expression_;
  std::stack<char> operators_;
  std::queue<std::string> rpn_expression_;
  double ParseOfDigitFromExpression(size_t &index);
  int GetPrecedence(char c) const;
  char CheckFuncIs(size_t &index);
  void PopFromStack(char c);
  void PopFromStackEnd();
  void PushRpnExpression();
  void ConditionsByPrecedence(char c);
  void UnaryMinusPlus(char c, size_t index);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
