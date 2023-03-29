#include "IllegalArgumentException.h"

IllegalArgumentException::IllegalArgumentException(std::string context, std::string str, int value) : Exception(context), name(str), value(value) {}

const std::string &IllegalArgumentException::getName() const {
    return name;
}

int IllegalArgumentException::getValue() const {
    return value;
}

void IllegalArgumentException::print() {
    Exception::print();
    std::cout << " Invalid value for parameter " << name << " : " << value << std::endl;
}
