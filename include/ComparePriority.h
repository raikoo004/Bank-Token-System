#ifndef COMPARE_PRIORITY_H
#define COMPARE_PRIORITY_H

#include "Token.h"

struct ComparePriority {
    bool operator()(Token* a, Token* b) const {
        if (a->priority != b->priority)
            return a->priority > b->priority;
        return a->tokenNumber > b->tokenNumber;
    }
};

#endif
