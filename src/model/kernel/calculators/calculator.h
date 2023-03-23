

#ifndef CPP3_SMARTCALC_V2_0_0_CALCULATOR_H
#define CPP3_SMARTCALC_V2_0_0_CALCULATOR_H
#include <cstring>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <string>

namespace s21 {

class Calculator {
 public:
  /***
   * @brif main method for calculation expression
   */
  double Calculate(std::list<std::string> &rpn_expression);

 protected:

  /***
   * @brif calculates expression (binary operator)
   * @param token is operator
   */
  double BinaryFunc(std::string &token, std::stack<double> &numbers);
  /***
   * @brif calculates expression (unary operator)
   * @param token is operator
   */
  double UnaryFunc(std::string &token, std::stack<double> &numbers);

 private:
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_CALCULATOR_H
