//
// Created by Qyburn Bongo on 3/7/23.
//
#include "calculator.h"

#include <cmath>
#include <string>

double s21::Calculator::Calculate(std::queue<std::string> &rpn_expression) {
  std::stack<double> numbers{};

  double result{};

  while (!rpn_expression.empty()) {
    std::string token = rpn_expression.front();
    rpn_expression.pop();

    if (isdigit(token.front())) {
      numbers.push(std::stod(token));
    }

    if (token == "+" || token == "-" || token == "*" || token == "/" ||
        token == "^" || token == "m") {
      numbers.push(BinaryFunc(token, numbers));
    } else if (isalpha(token.front())) {
      numbers.push(UnaryFunc(token, numbers));
    }
  }
  result = numbers.top();
  if (!isfinite(result)) throw std::invalid_argument("value is infinite");
  return result;
}

double s21::Calculator::BinaryFunc(std::string &token, std::stack<double>& numbers) {
  //    double num1 = (op == U_MINUS || op == U_PLUS) ? 0 : pop(stack_n);
  double num1{}, num2{};
  num2 = numbers.top();
  numbers.pop();
  num1 = numbers.top();
  numbers.pop();
  double res{};

  switch (token.front()) {
    case '+':
      res = num1 + num2;
      break;
    case '-':
      res = num1 - num2;
      break;
    case '*':
      res = num1 * num2;
      break;
    case '/':
      res = num1 / num2;
      break;
    case '^':
      res = pow(num1, num2);
      break;
    case 'm':
      res = fmod(num1, num2);
      break;
  }

  return res;
}

double s21::Calculator::UnaryFunc(std::string &token, std::stack<double>& numbers) {
  double num{};
  num = numbers.top();
  numbers.pop();
  double res{};

  switch (token.at(0)) {
    case 's':
      res = sin(num);
      break;
    case 'c':
      res = cos(num);
      break;
    case 't':
      res = tan(num);
      break;
    case 'l':
      res = log(num);
      break;
    case 'L':
      res = log10(num);
      break;
    case 'S':
      res = asin(num);
      break;
    case 'C':
      res = acos(num);
      break;
    case 'T':
      res = atan(num);
      break;
    case 'q':
      res = sqrt(num);
      break;
  }
  return res;
}
