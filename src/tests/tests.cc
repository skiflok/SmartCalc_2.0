#include <gtest/gtest.h>

#include "../model/model.h"

using namespace s21;

class Calculator_test : public ::testing::Test {
 protected:
  void SetUp() override {}
  Model model;
};

TEST_F(Calculator_test, GeneralCalculate) {
  std::string expression =
	  "sqrt(4)+9.235+2^3^sin(cos(10))-564-sqrt(25)+28.6*35mod99^2^3";
  double calculated_result = model.Calculation(expression);
  double should_result = 444.59309217773205;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate1) {
  std::string expression =
	  "5+(1+2)*4*(1)*cos(2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";
  double calculated_result = model.Calculation(expression);
  double should_result = 17.920647794675116;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate2) {
  std::string expression =
	  "-5+(-1+2)*4*cos(-2*7.5-2)+sin(cos(2*5))-sqrt(2^log(5-1))+ln(55)";
  double calculated_result = model.Calculation(expression);
  double should_result = -4.069366934933627;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate3) {
  std::string expression = "3+(3+5)*2+3/(1-4)^3*2";
  double calculated_result = model.Calculation(expression);
  double should_result = 18.77777777777778;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate4) {
  std::string expression = "-1+(-2+5)";
  double calculated_result = model.Calculation(expression);
  double should_result = 2;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate5) {
  std::string expression = "25.58e-1+89.47";
  double calculated_result = model.Calculation(expression);
  double should_result = 92.02799999999999;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate6) {
  std::string expression = "2+3*2-5/2^4";
  double calculated_result = model.Calculation(expression);
  double should_result = 7.6875;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate7) {
  std::string expression = "2*(2+3)/5-(1+4)^2";
  double calculated_result = model.Calculation(expression);
  double should_result = -23;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate8) {
  std::string expression = "2*sin(3)+sqrt(5)";
  double calculated_result = model.Calculation(expression);
  double should_result = 2.518307993619524;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, GeneralCalculate9) {
  std::string expression = "2.58e+1*sin(3.45)+sqrt(5)";
  double calculated_result = model.Calculation(expression);
  double should_result = -5.5953030503776873;
  EXPECT_DOUBLE_EQ(calculated_result, should_result);
}

TEST_F(Calculator_test, CreditCalculateAnnuity) {
  DataCredit data_credit(ANNUITY, 150200.00, 3.00, 13.00);
  std::vector<double> output_monthly_payment = {51155.00, 51155.00, 51155.00};
  double output_overpayment_loan = 3266.00;
  double output_final_payment = 153466.00;
  data_credit = model.CreditCalculation(data_credit);
  EXPECT_TRUE(output_monthly_payment == data_credit.output_monthly_payment_);
  EXPECT_DOUBLE_EQ(output_overpayment_loan,
				   data_credit.output_overpayment_loan_);
  EXPECT_DOUBLE_EQ(output_final_payment, data_credit.output_final_payment_);
}

TEST_F(Calculator_test, CreditCalculateDifferentiated) {
  DataCredit data_credit(DIFFERENTIATED, 150200.00, 3, 13.00);
  std::vector<double> output_monthly_payment = {51694.00, 51151.00, 50609.00};
  double output_overpayment_loan = 3254.00;
  double output_final_payment = 153454.00;
  data_credit = model.CreditCalculation(data_credit);
  EXPECT_TRUE(output_monthly_payment == data_credit.output_monthly_payment_);
  EXPECT_DOUBLE_EQ(output_overpayment_loan,
				   data_credit.output_overpayment_loan_);
  EXPECT_DOUBLE_EQ(output_final_payment, data_credit.output_final_payment_);
}

TEST_F(Calculator_test, DebitCalculateOnce) {
  DataDeposit data_deposit(1500000.00, 25, ONCE, 10, 15, NO, {1000, 10000},
						   {2000, 3000});

  double output_total_refills = 11000.00;
  double output_total_withdrawals = 5000.00;
  double output_interest_charges = 313750.00;
  double output_tax_amount = 21287.50;
  double output_total_deposit_amount = 1798463.00;
  data_deposit = model.DebitCalculation(data_deposit);
  EXPECT_DOUBLE_EQ(output_total_refills, data_deposit.output_total_refills_);
  EXPECT_DOUBLE_EQ(output_total_withdrawals,
				   data_deposit.output_total_withdrawals_);
  EXPECT_DOUBLE_EQ(output_interest_charges,
				   data_deposit.output_interest_charges_);
  EXPECT_DOUBLE_EQ(output_tax_amount, data_deposit.output_tax_amount_);
  EXPECT_DOUBLE_EQ(output_total_deposit_amount,
				   data_deposit.output_total_deposit_amount_);
}

TEST_F(Calculator_test, DebitCalculateMonthly) {
  DataDeposit data_deposit(1500000.00, 25, ONCE, 10, 15, MONTHLY_CAP,
						   {1000, 10000}, {2000, 3000});

  double output_total_refills = 11000.00;
  double output_total_withdrawals = 5000.00;
  double output_interest_charges = 347225.00;
  double output_tax_amount = 25639.210271591222;
  double output_total_deposit_amount = 1827585.00;
  data_deposit = model.DebitCalculation(data_deposit);
  EXPECT_DOUBLE_EQ(output_total_refills, data_deposit.output_total_refills_);
  EXPECT_DOUBLE_EQ(output_total_withdrawals,
				   data_deposit.output_total_withdrawals_);
  EXPECT_DOUBLE_EQ(output_interest_charges,
				   data_deposit.output_interest_charges_);
  EXPECT_DOUBLE_EQ(output_tax_amount, data_deposit.output_tax_amount_);
  EXPECT_DOUBLE_EQ(output_total_deposit_amount,
				   data_deposit.output_total_deposit_amount_);
}

TEST_F(Calculator_test, DebitCalculateOnce1) {
  DataDeposit data_deposit(1500000.00, 25, MONTHLY, 10, 15, NO, {1000, 10000},
						   {2000, 3000});

  double output_total_refills = 11000.00;
  double output_total_withdrawals = 5000.00;
  double output_interest_charges = 313750.00;
  double output_tax_amount = 21287.5;
  double output_total_deposit_amount = 1506000.00;
  data_deposit = model.DebitCalculation(data_deposit);
  EXPECT_DOUBLE_EQ(output_total_refills, data_deposit.output_total_refills_);
  EXPECT_DOUBLE_EQ(output_total_withdrawals,
				   data_deposit.output_total_withdrawals_);
  EXPECT_DOUBLE_EQ(output_interest_charges,
				   data_deposit.output_interest_charges_);
  EXPECT_DOUBLE_EQ(output_tax_amount, data_deposit.output_tax_amount_);
  EXPECT_DOUBLE_EQ(output_total_deposit_amount,
				   data_deposit.output_total_deposit_amount_);
}

TEST_F(Calculator_test, DebitCalculateMonthly1) {
  DataDeposit data_deposit(1500000.00, 25, MONTHLY, 10, 15, MONTHLY_CAP,
						   {1000, 10000}, {2000, 3000});

  double output_total_refills = 11000.00;
  double output_total_withdrawals = 5000.00;
  double output_interest_charges = 347225.00;
  double output_tax_amount = 25639.210271591222;
  double output_total_deposit_amount = 1506000.00;
  data_deposit = model.DebitCalculation(data_deposit);
  EXPECT_DOUBLE_EQ(output_total_refills, data_deposit.output_total_refills_);
  EXPECT_DOUBLE_EQ(output_total_withdrawals,
				   data_deposit.output_total_withdrawals_);
  EXPECT_DOUBLE_EQ(output_interest_charges,
				   data_deposit.output_interest_charges_);
  EXPECT_DOUBLE_EQ(output_tax_amount, data_deposit.output_tax_amount_);
  EXPECT_DOUBLE_EQ(output_total_deposit_amount,
				   data_deposit.output_total_deposit_amount_);
}

TEST_F(Calculator_test, ValidationException) {
  std::string expression = "sin(X)";
  EXPECT_ANY_THROW(model.Calculation(expression));
}

TEST_F(Calculator_test, ValidationException1) {
  std::string expression = "(1.1X)+3*2-5/2^X";
  EXPECT_ANY_THROW(model.Calculation(expression));
}

TEST_F(Calculator_test, ValidationException2) {
  std::string expression = "(1.1X)+3*2-5/2^X";
  EXPECT_ANY_THROW(model.Calculation(expression));
}

TEST_F(Calculator_test, ValidationException3) {
  std::string expression = "(X)+3*1.1*X*2-5/2^1.1X";
  EXPECT_ANY_THROW(model.Calculation(expression));
}

TEST_F(Calculator_test, ValidationException4) {
  std::string expression = "(X)+3*1.1*X1.1*2-5/2^1.1*X";
  EXPECT_ANY_THROW(model.Calculation(expression));
}
