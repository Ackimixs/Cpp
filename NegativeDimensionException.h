#ifndef TP10_NEGATIVEDIMENSIONEXCEPTION_H
#define TP10_NEGATIVEDIMENSIONEXCEPTION_H

#include "IllegalArgumentException.h"

class NegativeDimensionException : public IllegalArgumentException {
public:
    NegativeDimensionException(std::string context, std::string str, int value);

    virtual void print();
};


#endif //TP10_NEGATIVEDIMENSIONEXCEPTION_H
