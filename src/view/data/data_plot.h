//
// Created by Violator Emilie on 3/14/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_VIEW_DATA_DATA_PLOT_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_VIEW_DATA_DATA_PLOT_H_

#include <string>

namespace s21 {

struct DataPlot {
  DataPlot(const std::string& expression, const double& x_begin,
           const double& x_end, const int& step_size)
      : expression_(expression),
        x_begin_(x_begin),
        x_end_(x_end),
        step_size_(step_size) {}

  //  const std::string& GetExpression() const {
  //    return expression_;
  //  }

  std::string expression_{};
  double x_begin_{}, x_end_{};
  int step_size_{};
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_0_SRC_VIEW_DATA_DATA_PLOT_H_
