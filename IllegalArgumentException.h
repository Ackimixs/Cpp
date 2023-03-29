#ifndef TP10_ILLEGALARGUMENTEXCEPTION_H
#define TP10_ILLEGALARGUMENTEXCEPTION_H

#include "Point.h"
#include "Exception.h"

class IllegalArgumentException : public Exception {
public:
    IllegalArgumentException(std::string context, std::string str, int value);

    const std::string &getName() const;

    int getValue() const;

    virtual void print();
protected:
    std::string name;
    int value;
};


#endif //TP10_ILLEGALARGUMENTEXCEPTION_H
