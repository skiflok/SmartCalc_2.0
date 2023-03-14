//
// Created by Violator Emilie on 3/12/23.
//

#ifndef CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

//namespace s21{

class Controller {
 public:

    int Calculation(char *str, double* res) {
        return model_->Solution(str, res);
    }

 private:
  Model *model_ = new Model();
};

//}



#endif //CPP3_SMARTCALC_V2_0_0_SRC_CONTROLLER_CONTROLLER_H_
