// LibStruct.h
#ifndef LIBSTRUCT_H
#define LIBSTRUCT_H

#include <botan/bigint.h>

class DivResult {
public:
    Botan::BigInt Quotient;
    Botan::BigInt Remainder;
};

#endif // DIVRES