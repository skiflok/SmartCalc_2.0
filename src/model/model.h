//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_

//#ifdef __cplusplus
extern "C" {
#include "s21_calc.h"
}
//#endif

#include <vector>
#include <string>
#include "../view/plot_struct.h"

//namespace s21 {

class Model {
 public:
  Model() {}

//  double* GetData() {
//	return data_;
//  }

  int Solution(char *str, double *data_) {
	return main_solution(str, data_);
  }

  int Plot(PlotStruct ps, int n, double x_begin, double x_end, double h, double x, std::string inputStr) {

	std::vector<double> x_vector, y_vector;
	double res = 0;
	int error_my = 0;
//	int plot_error = 0;
	std::string plotSrt;

//	n = (x_end - x_begin) / h + 2;

	if (!error_my) {

	  for (int X = x_begin; X <= x_end; X += h) {
		X = round(X * 1000000) / 1000000;
		plotSrt = inputStr;
		size_t pos;
		while ((pos = plotSrt.find("x")) != plotSrt.npos) {
		  plotSrt.replace(pos, pos + plotSrt.length(), std::to_string(X));
		}
//		if (plot_error) {
//		  continue;
//		}
		x_vector.push_back(X);
		y_vector.push_back(res);

	  }
	}
  }

 private:

};

//}

#endif //CPP3_SMARTCALC_V2_0_0_SRC_MODEL_MODEL_H_
