#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

class Constants {
public:
    inline static const std::string B58Alphabet = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
    inline static const std::string B36Alphabet = "0123456789abcdefghijklmnopqrstuvwxyz";
    inline static const std::string B64Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    inline static const std::string CoinChar = "N";
    inline static const std::string StringSignature = "VERIFICATION";
    inline static const std::string emsa = "EMSA1(SHA-1)";
};

#endif // CONSTANTS_H
