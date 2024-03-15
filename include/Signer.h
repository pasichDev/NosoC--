// Signer.h
#ifndef SIGNER_H
#define SIGNER_H

#include "Compiler.h"
#include "Constants.h"
#include <bitset>
#include <botan/base64.h>
#include <botan/bigint.h>
#include <botan/botan.h>
#include <botan/ecdsa.h>
#include <botan/hex.h>
#include <botan/pubkey.h>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

class EXPORT NosoSigner {
public:
  EXPORT bool verifyMessage(const std::string &message,
                            const std::string &signatureBase64,
                            const std::string &publicKey);
  EXPORT std::string signMessage(const std::string &message,
                                 const std::string &privateKey);

private:
  std::vector<unsigned char> nosoBase64Decode(const std::string &input);
};
#endif // SIGNER_H