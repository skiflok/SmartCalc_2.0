//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_

#include <string>
#include <queue>

namespace s21 {

class Parser {
 public:
  explicit Parser(const std::string &expression) : expression_(expression) {}

  std::queue<std::string> GetRpn() {
    return rpn_expression_;
  }

private :
    std::string expression_;
    std::queue<std::string> rpn_expression_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_MODEL_KERNEL_PARSER_H_
