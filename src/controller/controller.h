//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"
#include "../view/data/data_plot.h"
#include "../view/data/data_credit.h"
#include "../view/data/data_deposit.h"
#include <string>

//namespace s21{

class Controller {
 public:

  /**
   * старая реализация
   * @param str
   * @param res
   * @return
   */
  int Calculation(char *str, double *res) {
	return model_->Solution(str, res);
  }

  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @return результат расчета
   */
  double Calculation(std::string &expression) {
	return 0;
  }

  /**
   * Выполняет расчет выражения
   * @param expression строка с математическим выражением в прямой форме
   * @param x значение, если выражение пришло в виде функции
   * @return результат расчета
   */
  double Calculation(std::string &expression, double &x) {
	return 0;
  }

/**
 * Выполняет расчет для отрисовки графика
 * @param data_plot класс который содержит данные для рсчета
 * @return пару с 2 векторами координа х, у для построения графика
 */
  std::pair<std::vector<double>, std::vector<double>> PlotCalculation(DataPlot data_plot);

  DataCredit CreditCalculation(DataCredit &data_credit);

  DataDeposit DebitCalculation(DataDeposit &data_deposit);

 private:
  Model *model_ = new Model();
};

//}



#endif //CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
