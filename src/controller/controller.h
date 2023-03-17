//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_

#include <string>

#include "../model/model.h"
#include "../view/data/data_credit.h"
#include "../view/data/data_deposit.h"
#include "../view/data/data_plot.h"
#include <QString>
#include <QVector>
#include <vector>

namespace s21 {

class Controller {
 public:
  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @return результат расчета
   */
  double Calculation(QString &expression) {
	// TODO try catch???
	double result{};

	std::string expressionToString = expression.toStdString();

	try {
	  result = model_.Calculation(expressionToString);
	} catch (...) {
	  throw std::invalid_argument("Invalid input");
	}
	return result;
  }

  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @param x значение, если выражение пришло в виде функции
   * @return результат расчета
   */
//  double Calculation(std::string &expression, double &x) { return 0; }

  /**
   * Выполняет расчет для отрисовки графика
   * @param data_plot класс который содержит данные для рсчета
   * @return пару с 2 векторами координа х, у для построения графика
   */
  std::pair<QVector < double>, QVector<double>> PlotCalculation(
  const DataPlot &data_plot
  ) {

	std::pair<QVector < double>, QVector < double >> castQvector;

	try {
	  std::pair<std::vector<double>, std::vector<double>> temp = model_.PlotCalculation(data_plot);
	  castQvector.first = QVector<double>(temp.first.begin(), temp.first.end());
	  castQvector.second = QVector<double>(temp.second.begin(), temp.second.end());
	} catch (...) {
	}

	return castQvector;
  }

  /**
   * Расчитывает платеж по кредиту за период
   * @param data_credit
   * @return
   */
  DataCredit& CreditCalculation(DataCredit &data_credit) {
	return model_.CreditCalculation(data_credit);
  }

  /**
   * Расчитывает проценты по депозиту
   * @param data_deposit
   * @return
   */
  DataDeposit DebitCalculation(DataDeposit &data_deposit);

 private:
  Model model_{};
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
