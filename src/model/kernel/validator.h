//
// Created by Qyburn Bongo on 3/11/23.
//

#ifndef GOOGLE_TESTS_VALIDATION_H
#define GOOGLE_TESTS_VALIDATION_H

#include <string>


namespace s21 {

    class Validator {

    public:

        explicit Validator(const std::string &expression) : expression_(expression) {}

        ~Validator() = default;


        bool IsValid() const;


    private:

        bool CheckNumber(size_t &index) const;
        std::string expression_;

    };
}

#endif //GOOGLE_TESTS_VALIDATION_H
