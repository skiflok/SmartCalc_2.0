//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_

#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>

namespace s21 {

class Parser {
 public:
  //  explicit Parser(const std::string &expression) : expression_(expression)
  //  {}

  std::list<std::string> GetRpn(const std::string &expression) {
    return ExpressionToRpn(expression);
  }

  std::list<std::string> ExpressionToRpn(const std::string &expression);
  void PrintExpression(std::string &expression) const {
    std::cout << expression << std::endl;
  }
  void PrintRpnExpression(std::list<std::string> &rpn_expression);

 private:
  //  std::string expression_;
  //  std::stack<char> operators_;
  //  std::queue<std::string> rpn_expression_;
  double ParseOfDigitFromExpression(size_t &index,
                                    const std::string &expression);
  int GetPrecedence(char c) const;
  char CheckFuncIs(size_t &index, const std::string &expression);
  void PopFromStack(char c, std::stack<char> &operators,
                    std::list<std::string> &rpn_expression);
  void PopFromStackEnd(std::stack<char> &operators,
                       std::list<std::string> &rpn_expression);
  void PushRpnExpression(std::stack<char> &operators,
                         std::list<std::string> &rpn_expression);
  void ConditionsByPrecedence(char c, std::stack<char> &operators,
                              std::list<std::string> &rpn_expression);
  void UnaryMinusPlus(char c, size_t index, const std::string &expression,
                      std::list<std::string> &rpn_expression);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
