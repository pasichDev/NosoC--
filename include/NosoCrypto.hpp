// NosoCrypto.h
#ifndef NOSOCRYPTO_H
#define NOSOCRYPTO_H

#include <botan/base58.h>
#include <botan/base64.h>
#include <botan/bigint.h>
#include <botan/hex.h>
#include <botan/rmd160.h>
#include <botan/sha2_32.h>
#include "LibStruct.hpp"
#include "Constants.hpp"

#include <string>
#include <bitset>
#include <cstdint>

class NosoCrypto {
public:

  int B58Sum(const std::string &number58);
  std::string DecTo58(const std::string &number);
  DivResult DivideBigInt(const Botan::BigInt &numerator,
                         const Botan::BigInt &denominator);
  Botan::BigInt HexToDec(std::string numerohex);
  std::string BMHexto58(const std::string &numerohex,
                        const Botan::BigInt &alphabetnumber);
  std::string getHashSha256ToString(const std::string &publicKey);
  std::string getHashMD160ToString(const std::string &pubSHAHashed);
};

#endif // NOSOCRYPTO_H
