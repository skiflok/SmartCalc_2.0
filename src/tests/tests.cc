//
// Created by Qyburn Bongo on 3/7/23.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../model/kernel/calculator.cc"
#include "../model/kernel/validator.cc"

#include "../controller/controller.h"

using std::cout;
using std::endl;
using namespace s21;

class Calculator_test : public ::testing::Test {
protected:
    void SetUp() override {
    }
    Controller controller;
};




TEST_F(Calculator_test, simple_expression_to_rpn) {
    std::string expression = "2+3*2-5/2^4";
//    cout << expression.length() << endl;
//    cout << "________________" << endl;
    s21::Calculator calc(expression);
    calc.ExpressionToRpn();
    calc.PrintExpression();
    cout << "________________" << endl;
    cout << "232*+524^/-" << endl;
    calc.PrintRpnExpression();
}

TEST_F(Calculator_test, expression_to_rpn_brck) {
    std::string expression = "2*(2+3)/5-(1+4)^2";
//    cout << expression.length() << endl;
//    cout << "________________" << endl;
    s21:: Calculator calc(expression);
    calc.ExpressionToRpn();
    calc.PrintExpression();
    cout << "________________" << endl;
    cout << "223+*5/14+2^-" << endl;
    calc.PrintRpnExpression();
}

TEST_F(Calculator_test, expression_to_rpn_funck) {
    std::string expression = "2*sin(3)+sqrt(5)";
//    std::string expression = "2+2";
//    cout << expression.length() << endl;
//    cout << "________________" << endl;
    s21::Calculator calc(expression);
    calc.ExpressionToRpn();
    calc.PrintExpression();
    cout << "________________" << endl;
    cout << "23s*5q+" << endl;
    calc.PrintRpnExpression();
}

TEST_F(Calculator_test, expression_to_rpn_double) {
    std::string expression = "2.58e+1*sin(3.45)+sqrt(5)";
    s21::Calculator calc(expression);
    calc.ExpressionToRpn();
    calc.PrintExpression();
    cout << "________________" << endl;
    cout << "23s*5q+" << endl;
    calc.PrintRpnExpression();
}

TEST_F(Calculator_test, Calculate) {
//    std::string expression = "2.58e+1 * sin( 3.45) + sqrt(5)";
//    std::string expression = "(2*((2+3)/5-(1+4))^2)mod7";
//    std::string expression = "2^2^3";
    std::string expression = "sqrt(4)+9.235+2^3^sin(cos(10))-564-sqrt(25)+28.6*35mod99^2^3";
//    std::string expression = "5+(1+2)*4*(1)*cos(2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";
//    std::string expression = "-5+(-1+2)*4*cos(-2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";
//    std::string expression = "3+(3+5)*2+3/(1-4)^3*2";
//    std::string expression = "-1+(-2+5)";
//    std::string expression = "0";
    double d{};
    s21::Calculator calc(expression);
    calc.ExpressionToRpn();
    calc.PrintExpression();
    cout << "________________" << endl;
    cout << "23s*5q+" << endl;
    calc.PrintRpnExpression();
    cout << endl;
    cout << "________________" << endl;
    d = calc.Calculate();
    cout << d << endl;
}

TEST_F(Calculator_test, ParseOfDigitFromExpression) {
//    std::string expression = "25.58+89.47";
    std::string expression = "25.58e-1+89.47";
    double result{};
    size_t index = 0;
    s21::Calculator calc(expression);
    result = calc.ParseOfDigitFromExpression(index);
    cout << "________________" << endl;
    cout << result << endl;
    cout << index << endl;
}

TEST_F(Calculator_test, IzValid) {
//    std::string expression = "25.58+89.47";
//    std::string expression = "(5)+(1+2)*4*(-12)+cos(2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+(1)+ln(5)+(1)";
    std::string expression = "5.55e+1+sin(-2.88) ";
//    std::string expression = "1+(1)+sin(-2)+1+(1)+1";
//    std::string expression = "";
//    std::string expression = "0";
//    std::string expression = " ";
    bool error{};

    s21::Validator valid(expression);
    error = valid.IsValid();
    cout << "________________" << endl;
    cout << error << endl;

}




int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

