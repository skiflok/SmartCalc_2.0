//
// Created by Qyburn Bongo on 3/7/23.
//

#include <gtest/gtest.h>

#include <iostream>
//#include "../model/kernel/calculator.cc"
//#include "../model/kernel/validator.cc"

#include "../controller/controller.h"
#include "../model/kernel/parser.h"

using std::cout;
using std::endl;
using namespace s21;

class Calculator_test : public ::testing::Test {
 protected:
  void SetUp() override {}
  Controller controller;
  Parser parser;
};

TEST_F(Calculator_test, Controller_calculation_1) {
  std::string expression = "2+3*2-5/2^4";
  double res{};

  res = controller.Calculation(expression);

  cout << res << endl;
}

TEST_F(Calculator_test, parse_test) {
  std::string expression = "2+3*2-5/2^4";

  std::queue<std::string> result = parser.ExpressionToRpn(expression);
  parser.PrintExpression(expression);
  cout << "________________" << endl;
  cout << "232*+524^/-" << endl;
  parser.PrintRpnExpression(result);
}

TEST_F(Calculator_test, parse_testX) {
  std::string expression = "x+3*2-5/2^x";

  std::queue<std::string> result = parser.ExpressionToRpn(expression);
  parser.PrintExpression(expression);
  cout << "________________" << endl;
  cout << "x32*+52x^/-" << endl;
  parser.PrintRpnExpression(result);
}

TEST_F(Calculator_test, CalculateX) {
  std::string expression = "x+3*2-5/2^x";
  std::cout << "Input_____string\n" << expression << std::endl << std::endl;

  DataPlot data_plot(expression, -10, 10);

  std::pair<std::vector<double>, std::vector<double>> result =
      controller.PlotCalculation(data_plot);

  std::cout << "Xbegin_____Xend" << std::endl;
  for (auto iter : result.first) {
    std::cout << iter << ' ';
  }
  std::cout << "\n\nYbegin_____Yend" << std::endl;
  for (auto iter : result.second) {
    std::cout << iter << ' ';
  }
}

TEST_F(Calculator_test, expression_to_rpn_brck) {
  std::string expression = "2*(2+3)/5-(1+4)^2";
  double calculated_result = controller.Calculation(expression);
  double should_result = -23;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, expression_to_rpn_funck) {
  std::string expression = "2*sin(3)+sqrt(5)";
  double calculated_result = controller.Calculation(expression);
  double should_result = 2.518307993619524;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, expression_to_rpn_double) {
  std::string expression = "2.58e+1*sin(3.45)+sqrt(5)";
  double calculated_result = controller.Calculation(expression);
  double should_result = -5.5953030503776873;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, Calculate) {
  std::string expression =
      "sqrt(4)+9.235+2^3^sin(cos(10))-564-sqrt(25)+28.6*35mod99^2^3";

  double calculated_result = controller.Calculation(expression);
  //  double should_result = 2.518307993619524;
  //  EXPECT_DOUBLE_EQ(calculated_result , should_result);
}

TEST_F(Calculator_test, Calculate1) {
  std::string expression =
      "5+(1+2)*4*(1)*cos(2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";

  double calculated_result = controller.Calculation(expression);
  //  double should_result = 2.518307993619524;
  //  EXPECT_DOUBLE_EQ(calculated_result , should_result);
}

TEST_F(Calculator_test, Calculate2) {
  std::string expression =
      "-5+(-1+2)*4*cos(-2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";

  double calculated_result = controller.Calculation(expression);
  //  double should_result = 2.518307993619524;
  //  EXPECT_DOUBLE_EQ(calculated_result , should_result);
}

TEST_F(Calculator_test, Calculate3) {
  std::string expression = "3+(3+5)*2+3/(1-4)^3*2";

  double calculated_result = controller.Calculation(expression);
  //  double should_result = 2.518307993619524;
  //  EXPECT_DOUBLE_EQ(calculated_result , should_result);
}

TEST_F(Calculator_test, Calculate4) {
  std::string expression = "-1+(-2+5)";

  double calculated_result = controller.Calculation(expression);
  //  double should_result = 2.518307993619524;
  //  EXPECT_DOUBLE_EQ(calculated_result , should_result);
}

TEST_F(Calculator_test, ParseOfDigitFromExpression) {
  std::string expression = "25.58e-1+89.47";
  double res = controller.Calculation(expression);

  //  cout << res << endl;
}

TEST_F(Calculator_test, IsNotValid) {
  //  std::string expression = "(2)^(-1/2)";
  //    std::string expression = "9.47+1.1*5";
  //  std::string expression = "2.58e-1*1+80.8";
  //    std::string expression = "25.58+89.47";
  //    std::string expression =
  //    "(5)+(1+2)*4*(-12)+cos(2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+(1)+ln(5)+(1)";
  //    std::string expression = "5.55e+1+sin(-2.88) ";
  //    std::string expression = "1+(1)+sin(-2)+1+(1)+1";
  //    std::string expression = "";
  //    std::string expression = "0";
  //    std::string expression = " ";
  //  double res = controller.Calculation(expression);

  //  cout << res << endl;
}
