
#ifndef CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_

#include <string>

#include "../model/model.h"

#include "../model/data/data_credit.h"
#include "../model/data/data_deposit.h"
#include "../model/data/data_plot.h"

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
  double Calculation(QString &expression);

  /**
   * Выполняет расчет для отрисовки графика
   * @param data_plot класс который содержит данные для рсчета
   * @return пару с 2 векторами координа х, у для построения графика
   */
  std::pair<QVector < double>, QVector<double>> PlotCalculation(
  const DataPlot &data_plot
  );

  /**
   * Расчитывает платеж по кредиту за период
   * @param data_credit
   * @return
   */
  DataCredit CreditCalculation(DataCredit &data_credit) {
	return model_.CreditCalculation(data_credit);
  }

  /**
   * Расчитывает проценты по депозиту
   * @param data_deposit
   * @return
   */
  DataDeposit DepositCalculation(DataDeposit &data_deposit) {
	return model_.DepositCalculation(data_deposit);
  }

 private:
  Model model_{};
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
