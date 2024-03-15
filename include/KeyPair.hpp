// KayPair.h
#ifndef KEYPAIR_H
#define KEYPAIR_H

#include <string>

class KeyPair {
public:
  std::string PublicKey;
  std::string PrivateKey;

  KeyPair() = default;

  KeyPair(const std::string &publicKey, const std::string &privateKey)
      : PublicKey(publicKey), PrivateKey(privateKey) {}
};

#endif 
