#include "NegativeDimensionException.h"

NegativeDimensionException::NegativeDimensionException(std::string context, std::string str, int value) : IllegalArgumentException(context, str, value) {}

void NegativeDimensionException::print() {
    Exception::print();
    std::cout << "Unexpected negative value for dimension " << name << " : " << value << std::endl;
}