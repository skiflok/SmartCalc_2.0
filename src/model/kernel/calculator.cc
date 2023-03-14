//
// Created by Qyburn Bongo on 3/7/23.
//
#include "calculator.h"

#include <cmath>
#include <string>

double s21::Calculator::Calculate() {
  double result = 0.0;
  int error = 0;
  while (!rpn_expression_.empty()) {
    std::string token = rpn_expression_.front();
    rpn_expression_.pop();
    GetDigitFromRpn(token);
    if (token == "+" || token == "-" || token == "*" || token == "/" ||
        token == "^" || token == "m") {
      BinaryFunc(token);
    } else if (isalpha(token.front())) {
      UnaryFunc(token);
    }
  }
  result = numbers_.top();
  if (isfinite(result)) error = 1;  // TODO something throw Exception
  return result;
}

void s21::Calculator::GetDigitFromRpn(const std::string &token) {
  if (isdigit(token.front())) {
    numbers_.push(std::stod(token));
  }
}

void s21::Calculator::BinaryFunc(std::string &token) {
  //    double num1 = (op == U_MINUS || op == U_PLUS) ? 0 : pop(stack_n);
  double num1{}, num2{};
  num2 = numbers_.top();
  numbers_.pop();
  num1 = numbers_.top();
  numbers_.pop();
  if (token == "+") {
    numbers_.push(num1 + num2);
  }
  if (token == "-") {
    numbers_.push(num1 - num2);
  }
  if (token == "*") {
    numbers_.push(num1 * num2);
  }
  if (token == "/") {
    numbers_.push(num1 / num2);
  }
  if (token == "^") {
    numbers_.push(pow(num1, num2));
  }
  if (token == "m") {
    numbers_.push(fmod(num1, num2));
  }
}

void s21::Calculator::UnaryFunc(std::string &token) {
  double num{};
  num = numbers_.top();
  numbers_.pop();
  if (token == "s") {
    numbers_.push(sin(num));
  }
  if (token == "c") {
    numbers_.push(cos(num));
  }
  if (token == "t") {
    numbers_.push(tan(num));
  }
  if (token == "l") {
    numbers_.push(log(num));
  }
  if (token == "L") {
    numbers_.push(log10(num));
  }
  if (token == "S") {
    numbers_.push(asin(num));
  }
  if (token == "C") {
    numbers_.push(acos(num));
  }
  if (token == "T") {
    numbers_.push(atan(num));
  }
  if (token == "q") {
    numbers_.push(sqrt(num));
  }
}
