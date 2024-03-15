#include "../include/NosoCrypto.h"


using namespace std;

DivResult NosoCrypto::DivideBigInt(const Botan::BigInt &numerator,
                                   const Botan::BigInt &denominator) {
  DivResult result;
  result.Quotient = numerator / denominator;
  result.Remainder = numerator % denominator;
  return result;
}

int NosoCrypto::B58Sum(const string &number58) {
  int total = 0;

  for (size_t i = 0; i < number58.length(); i++) {
    char currentChar = number58[i];
    size_t foundIndex = Constants::B58Alphabet.find(currentChar);

    if (foundIndex != string::npos) {
      total += static_cast<int>(foundIndex);
    }
  }

  return total;
}

string NosoCrypto::DecTo58(const string &number) {
  Botan::BigInt decimalValue = Botan::BigInt(number);
  DivResult resultDiv;
  string remainder;
  string result = "";

  while (decimalValue.bits() >= 2) {
    resultDiv = DivideBigInt(decimalValue, 58);
    decimalValue = resultDiv.Quotient;
    remainder = to_string(resultDiv.Remainder.to_u32bit());
    result = Constants::B58Alphabet[std::stoi(remainder)] + result;
  }

  if (decimalValue.cmp(58) >= 0) {
    resultDiv = DivideBigInt(decimalValue, 58);
    decimalValue = resultDiv.Quotient;
    remainder = to_string(resultDiv.Remainder.to_u32bit());
    result = Constants::B58Alphabet[std::stoi(remainder)] + result;
  }

  if (decimalValue.cmp(0) > 0) {
    result = Constants::B58Alphabet[decimalValue.to_u32bit()] + result;
  }

  return result;
}

Botan::BigInt NosoCrypto::HexToDec(std::string numerohex) {
  vector<uint8_t> bytes;
  for (size_t i = 0; i < numerohex.size(); i += 2) {
    string byteString = numerohex.substr(i, 2);
    uint8_t byte = static_cast<uint8_t>(std::stoi(byteString, nullptr, 16));
    bytes.push_back(byte);
  }
  return Botan::BigInt(bytes.data(), bytes.size());
}

string NosoCrypto::BMHexto58(const string &numerohex,
                             const Botan::BigInt &alphabetnumber) {

  Botan::BigInt decimalValue = HexToDec(numerohex);
  string Result = "";
  string AlphabetUsed;

  if (alphabetnumber == 36) {
    AlphabetUsed = Constants::B36Alphabet;
  } else {
    AlphabetUsed = Constants::B58Alphabet;
  }

  while (decimalValue.bits() >= 2) {
    DivResult ResultDiv = DivideBigInt(decimalValue, alphabetnumber);
    decimalValue = ResultDiv.Quotient;
    int remainder = ResultDiv.Remainder.to_u32bit();
    Result = AlphabetUsed[remainder] + Result;
  }

  if (decimalValue >= alphabetnumber.to_u32bit()) {
    DivResult ResultDiv = DivideBigInt(decimalValue, alphabetnumber);
    decimalValue = ResultDiv.Quotient;
    int remainder = ResultDiv.Remainder.to_u32bit();
    Result = AlphabetUsed[remainder] + Result;
  }

  if (decimalValue > 0) {
    int value = decimalValue.to_u32bit();
    Result = AlphabetUsed[value] + Result;
  }

  return Result;
}

string NosoCrypto::getHashSha256ToString(const string &publicKey) {
  Botan::SHA_256 sha256;
  sha256.update(reinterpret_cast<const Botan::byte *>(publicKey.c_str()),
                publicKey.length());
  Botan::secure_vector<Botan::byte> digest = sha256.final();

  string result = Botan::hex_encode(digest);

  for (char &c : result) {
    if (c == '-')
      c = ' ';
    c = toupper(c);
  }

  return result;
}

string NosoCrypto::getHashMD160ToString(const string &pubSHAHashed) {
  Botan::RIPEMD_160 hash;
  Botan::secure_vector<uint8_t> hashResult =
      hash.process(reinterpret_cast<const uint8_t *>(pubSHAHashed.data()),
                   pubSHAHashed.size());
  string hashHex = Botan::hex_encode(hashResult);

  for (char &c : hashHex) {
    c = toupper(c);
  }

  return hashHex;
}
