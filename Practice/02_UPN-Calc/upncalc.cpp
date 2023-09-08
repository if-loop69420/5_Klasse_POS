#include "upncalc.h"

UPNCalc::UPNCalc()
{
    this->num_stack = std::unique_ptr<std::stack<int>>();
}

void UPNCalc::add(int number) {
    this->num_stack->push(number);
}


Operation UPNCalc::resolve_operation(std::string to_resolve) {
    std::regex is_operand("[+-\*\/]");
    std::regex is_plus("[+]");
    std::regex is_minus("[-]");
    std::regex is_multiply("[\*]");
    std::regex is_divide("[\/");
    if(!std::regex_match(to_resolve,is_operand)) {
        throw std::invalid_argument("Input is not an operand");
    }
    if(std::regex_match(to_resolve,is_plus)){
        return Operation::ADD;
    } else if(std::regex_match(to_resolve,is_minus)){
        return Operation::SUB;
    } else if(std::regex_match(to_resolve,is_multiply)) {
        return Operation::MUL;
    } else {
        return Operation::DIV;
    }

}


int UPNCalc::do_operation(Operation op) {
    int num1 = this->num_stack->top();
    this->num_stack->pop();
    int num2 = this->num_stack->top();
    this->num_stack->pop();
    if(num1 == NULL || num2 == NULL) {
        throw std::logic_error("Not enough numbers on stack for working");
    }
    switch(op) {
        case Operation::ADD:
            this->num_stack->push((int)(num1 + num2));
            break;
        case Operation::SUB:
            this->num_stack->push((int)(num1 - num2));
            break;
        case Operation::MUL:
            this->num_stack->push((int)(num1 * num2));
            break;
        case Operation::DIV:
            this->num_stack->push((int)(num1/num2));
            break;
    }
}
