
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
  /***
   * @brif divides a string with a mathematical expression into tokens
   * @param expression - the string of a mathematical expression
   * @return the list of tokens of a mathematical expression
   */
  std::list<std::string> ExpressionToRpn(const std::string &expression);

 private:
  /***
   * @brif gets a number from a string of expressions
   * @param index is index a string of expressions
   * @return double-precision number
   */
  double ParseOfDigitFromExpression(size_t &index,
                                    const std::string &expression);

  /***
   * @brif get percedance of operators
   * @param с is operator
   * @return precedence
   */
  int GetPrecedence(char c) const;

  /***
   * @brif get percedance of operators
   * @param index is index a string of expressions, expression - the string of a
   * mathematical expression
   * @return alias math function
   */
  char CheckFuncIs(size_t &index, const std::string &expression);

  /***
   * @brif moves an element from the stack to the string rpn (by conditions)
   * @param c is token
   */
  void PopFromStack(char c, std::stack<char> &operators,
                    std::list<std::string> &rpn_expression);

  /***
   * @brif moves an element from the stack to the string rpn (without
   * conditions)
   */
  void PopFromStackEnd(std::stack<char> &operators,
                       std::list<std::string> &rpn_expression);

  /***
   * @brif moves an element from the stack to the string rpn (support function)
   */
  void PushRpnExpression(std::stack<char> &operators,
                         std::list<std::string> &rpn_expression);

  void ConditionsByPrecedence(char c, std::stack<char> &operators,
                              std::list<std::string> &rpn_expression);

  /***
   * @brif check unary minus and plus operators
   * @param c is operator
   * @param index is expression string index
   */
  void UnaryMinusPlus(char c, size_t index, const std::string &expression,
                      std::list<std::string> &rpn_expression);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
