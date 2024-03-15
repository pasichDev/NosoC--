// Address.h
#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
  std::string hash;       // Unique identifier for the address
  std::string custom;     // Custom alias for the address (optional)
  std::string publicKey;  // Public key associated with the address
  std::string privateKey; // Private key associated with the address
  double balance;         // Current balance of the address
  int score;              // Token balance
  int lastOP;             // Last operation block
  bool isLocked;          // Indicates whether the address is locked
  double incoming;        // Total incoming transactions
  double outgoing;        // Total outgoing transactions

public:


  // Returns the hash or alias of the address.
  std::string getNameAddressFull() const {
    return custom.empty() ? hash : custom;
  }

  // Available balance to perform paid transactions.
  double getAvailableBalance() const {
    return outgoing > balance ? 0 : balance - outgoing;
  }

  // Constructor for creating an AddressObject.
  Address(const std::string &hash, const std::string &publicKey,
          const std::string &privateKey, const std::string &custom = "",
          double balance = 0, int score = 0, int lastOP = 0,
          bool isLocked = false, double incoming = 0, double outgoing = 0)
      : hash(hash), custom(custom), publicKey(publicKey),
        privateKey(privateKey), balance(balance), score(score), lastOP(lastOP),
        isLocked(isLocked), incoming(incoming), outgoing(outgoing) {}

  // Creates a new instance of AddressObject with optional modifications.
  Address copyWith(const std::string &hash, const std::string &custom,
                   double balance, int score, int lastOP, bool isLocked,
                   double incoming, double outgoing) const {
    return Address(hash.empty() ? this->hash : hash, publicKey, privateKey,
                   custom.empty() ? this->custom : custom,
                   balance == 0 ? this->balance : balance,
                   score == 0 ? this->score : score,
                   lastOP == 0 ? this->lastOP : lastOP,
                   isLocked == false ? this->isLocked : isLocked,
                   incoming == 0 ? this->incoming : incoming,
                   outgoing == 0 ? this->outgoing : outgoing);
  }
};
#endif
