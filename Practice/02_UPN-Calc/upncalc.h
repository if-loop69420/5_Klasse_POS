#ifndef UPNCALC_H
#define UPNCALC_H

#include <stack>
#include <memory>
#include <stdexcept>
#include <string>
#include <regex>

enum Operation {
    MUL,
    SUB,
    ADD,
    DIV
};

class UPNCalc
{
public:
    UPNCalc();
    void add(int number);
    int do_operation(Operation o);
    Operation resolve_operation(std::string to_resolve);
private:
    std::unique_ptr<std::stack<int>> num_stack;
};

#endif // UPNCALC_H
