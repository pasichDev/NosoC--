// Seed.h
#ifndef SEED_H
#define SEED_H

#include <string>

class Seed {
private:
  std::string ip;
  int port;
  std::string address;
  int ping;
  bool online;

public:
  Seed(const std::string &ip = "127.0.0.1", int port = 8080,
       const std::string &address = "", int ping = 0, bool online = false)
      : ip(ip), port(port), address(address), ping(ping), online(online) {}

  Seed tokenizer(const std::string &verSeed,
                 const std::string &rawString = "") const {
    if (rawString.empty() || rawString.length() <= 5) {
      if (verSeed.empty() || verSeed.length() <= 5) {
        return *this;
      } else {
        return tokenizer(verSeed);
      }
    }

    size_t pos = rawString.find(":");
    if (pos != std::string::npos) {
      return copyWith(rawString.substr(0, pos),
                      stoi(rawString.substr(pos + 1)));
    }

    return *this;
  }

  std::string toTokenizer() const { return ip + ":" + std::to_string(port); }

  Seed copyWith(const std::string &ip = "", int port = 0,
                const std::string &address = "") const {
    return Seed(ip.empty() ? this->ip : ip, port == 0 ? this->port : port,
                address.empty() ? this->address : address);
  }
};
#endif