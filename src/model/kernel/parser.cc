//
// Created by Violator Emilie on 3/14/23.
//

#include "parser.h"

void s21::Parser::ExpressionToRpn() {
  for (size_t i = 0; i < expression_.size(); ++i) {
    char c = expression_[i];
    // парсер без x
    //    if (c != ' ' && isdigit(c)) {  // TODO Is it necessary to check spaces?
    //      double d = ParseOfDigitFromExpression(i);
    //      rpn_expression_.push(std::to_string(d));
    //      --i;

    if (c != ' ' && (isdigit(c) || c == 'X' || c == 'x')) {
      std::string d{};
      if (c == 'X' || c == 'x') {
        d = "x";
      } else {
        d = std::to_string(ParseOfDigitFromExpression(i));
        --i;
      }
      rpn_expression_.push(d);
    } else if (isalpha(c) && c != ' ' && c != 'm') {
      c = CheckFuncIs(i);
      operators_.push(c);
    } else if (c != ' ' && (c == '+' || c == '-' || c == '*' || c == '/' ||
                            c == '(' || c == ')' || c == '^' || c == 'm')) {
      if (c == 'm') i += 2;
      UnaryMinusPlus(c, i);
      ConditionsByPrecedence(c);
    }
  }
  PopFromStackEnd();
}

double s21::Parser::ParseOfDigitFromExpression(size_t &index) {
  std::size_t pos = index;
  double digit{};
  digit = std::stod(expression_.substr(pos), &pos);
  index += pos;
  return digit;
}

int s21::Parser::GetPrecedence(char c) const {
  int precedence;
  if (c == '(')
    precedence = 0;
  else if (c == ')')
    precedence = -1;
  else if (c == '+' || c == '-')
    precedence = 1;
  else if (c == '*' || c == '/' || c == 'm')
    precedence = 2;
  else if (c == '^')
    precedence = 3;
  else
    precedence = 4;
  return precedence;
}

char s21::Parser::CheckFuncIs(size_t &index) {
  char symbol_func{};
  size_t next_symbol = index + 1;
  if (expression_[index] == 's' && expression_[next_symbol] == 'i') {
    index = index + 2;
    symbol_func = 's';
  }
  if (expression_[index] == 'c') {
    index = index + 2;
    symbol_func = 'c';
  }
  if (expression_[index] == 't') {
    index = index + 2;
    symbol_func = 't';
  }
  if (expression_[index] == 'l' && expression_[next_symbol] == 'n') {
    index = index + 1;
    symbol_func = 'l';
  }
  if (expression_[index] == 'l' && expression_[next_symbol] == 'o') {
    index = index + 2;
    symbol_func = 'L';
  }
  if (expression_[index] == 'a' && expression_[next_symbol] == 's') {
    index = index + 3;
    symbol_func = 'S';
  }
  if (expression_[index] == 'a' && expression_[next_symbol] == 'c') {
    index = index + 3;
    symbol_func = 'C';
  }
  if (expression_[index] == 'a' && expression_[next_symbol] == 't') {
    index = index + 3;
    symbol_func = 'T';
  }
  if (expression_[index] == 's' && expression_[next_symbol] == 'q') {
    index = index + 3;
    symbol_func = 'q';
  }
  return symbol_func;
}

void s21::Parser::PopFromStack(char c) {
  while (!operators_.empty()) {
    if (operators_.top() == '(') {
      break;
    }
    if (GetPrecedence(operators_.top()) < GetPrecedence(c)) {
      break;
    }
    PushRpnExpression();
  }
}

void s21::Parser::PopFromStackEnd() {
  while (!operators_.empty()) {
    PushRpnExpression();
  }
}

void s21::Parser::PushRpnExpression() {
  std::string op = {operators_.top()};
  rpn_expression_.push(op);
  operators_.pop();
}

void s21::Parser::ConditionsByPrecedence(char c) {
  if (operators_.empty() || c == '(' ||
      GetPrecedence(c) > GetPrecedence(operators_.top()) ||
      (c == '^' && operators_.top() == '^'))
    operators_.push(c);
  else if (c == ')') {
    while (operators_.top() != '(') {
      PushRpnExpression();
    }
    operators_.pop();
  } else {
    PopFromStack(c);
    operators_.push(c);
  }
}

void s21::Parser::UnaryMinusPlus(char c, size_t index) {
  if ((c == '-' && (index == 0 || expression_[index - 1] == '(')) ||
      (c == '+' && (index == 0 || expression_[index - 1] == '(')))
    rpn_expression_.push("0.0");
}

void s21::Parser::PrintRpnExpression() {
  std::queue<std::string> rpn_expression2 = rpn_expression_;
  while (!rpn_expression2.empty()) {
    std::cout << rpn_expression2.front();
    rpn_expression2.pop();
  }
}
