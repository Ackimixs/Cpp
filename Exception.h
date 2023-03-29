#ifndef TP10_EXCEPTION_H
#define TP10_EXCEPTION_H

#include <string>
#include <iostream>

class Exception {
protected:
    std::string context;
public:
    Exception(std::string context) : context(context) {}

    void print() {std::cout << context;}
};


#endif //TP10_EXCEPTION_H
