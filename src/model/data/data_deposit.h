
#ifndef SMARTCALC_2_0_SRC_VIEW_DATA_DATA_DEPOSIT_H_
#define SMARTCALC_2_0_SRC_VIEW_DATA_DATA_DEPOSIT_H_

#include <string>

namespace s21 {

enum Periodicity { DAY, MONTH, CUARTER };

enum Capitalization { YES, NO };

struct DataDeposit {
  DataDeposit(Periodicity periodicity, Capitalization capitalization,
              const double input_deposit, const int input_term,
              const double input_percent, const double input_tax,
              const double rep_minus_with)
      : periodicity_(periodicity),
        capitalization_(capitalization),
        input_deposit_(input_deposit),
        input_term_(input_term),
        input_percent_(input_percent),
        input_tax_(input_tax),
        rep_minus_with_(rep_minus_with) {}

  //----INPUT----
  Periodicity periodicity_;
  Capitalization capitalization_;
  double input_deposit_;
  int input_term_;
  double input_percent_;
  double input_tax_;
  double rep_minus_with_;

  //----OUTPUT----

  double out_total_{};
  double out_total_percent_{};
  double out_total_tax_{};
};

}  // namespace s21

#endif  // SMARTCALC_2_0_SRC_VIEW_DATA_DATA_DEPOSIT_H_
