#include "calculation.h"
#include "../exprtk/exprtk.hpp"

double evaluate(const std::string &expressionText) {
    exprtk::expression<double> expression;
    exprtk::parser<double> parser;

    if (parser.compile(expressionText, expression)) {
        return expression.value();
    } else {
        throw std::invalid_argument("Invalid expression");
    }
}

