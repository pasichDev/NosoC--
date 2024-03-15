#include "../include/Signer.h"

std::vector<unsigned char>
NosoSigner::nosoBase64Decode(const std::string &input) {

  std::vector<int> indexList;
  for (char c : input) {
    auto it = Constants::B64Alphabet.find(c);
    if (it != std::string::npos) {
      indexList.push_back(static_cast<int>(it));
    }
  }

  std::string binaryString;
  for (int i : indexList) {
    std::string binary = std::bitset<6>(i).to_string();
    binaryString += binary;
  }

  std::string strAux = binaryString;
  std::vector<unsigned char> tempByteArray;

  while (strAux.length() >= 8) {
    std::string currentGroup = strAux.substr(0, 8);
    int intVal = stoi(currentGroup, nullptr, 2);
    tempByteArray.push_back(static_cast<unsigned char>(intVal));
    strAux = strAux.substr(8);
  }

  return tempByteArray;
}

std::string NosoSigner::signMessage(const std::string &message,
                                    const std::string &privateKey) {
  try {
    Botan::AutoSeeded_RNG rng;
    std::vector<unsigned char> messages = nosoBase64Decode(message);
    Botan::secure_vector<uint8_t> decodedPrivatKey =
        Botan::base64_decode(privateKey);
    Botan::AlgorithmIdentifier alg_id(
        "ECDSA", Botan::AlgorithmIdentifier::USE_NULL_PARAM);

    Botan::BigInt private_key_value =
        Botan::BigInt::decode(decodedPrivatKey.data(), decodedPrivatKey.size());
    Botan::EC_Group secp256k1("secp256k1");
    Botan::ECDSA_PrivateKey private_key(rng, secp256k1, private_key_value);

    Botan::PK_Signer signer(private_key, rng, "EMSA1(SHA-1)",
                            Botan::DER_SEQUENCE);
    signer.update(messages);
    std::vector<uint8_t> signature = signer.signature(rng);

    std::string signature_base64 =
        Botan::base64_encode(signature.data(), signature.size());
    return signature_base64;

  }

  catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return ex.what();
  }
}

bool NosoSigner::verifyMessage(const std::string &message,
                               const std::string &signatureBase64,
                               const std::string &publicKey) {
  Botan::AutoSeeded_RNG rng;
  Botan::secure_vector<uint8_t> decodedPublicKey =
      Botan::base64_decode(publicKey);
  Botan::secure_vector<uint8_t> signature =
      Botan::base64_decode(signatureBase64.data(), signatureBase64.size());
  std::vector<unsigned char> messages = nosoBase64Decode(message);

  if (decodedPublicKey.size() != 65) {
    std::cerr << "Invalid UNCOMPRESSED public key format" << std::endl;
    return false;
  }
  try {
    std::vector<uint8_t> xCoord(decodedPublicKey.begin() + 1,
                                decodedPublicKey.begin() + 33);
    std::vector<uint8_t> yCoord(decodedPublicKey.begin() + 33,
                                decodedPublicKey.end());

    Botan::BigInt x_bigint(xCoord.data(), xCoord.size());
    Botan::BigInt y_bigint(yCoord.data(), yCoord.size());

    Botan::EC_Group secp256k1("secp256k1");

    Botan::PointGFp point = secp256k1.point(x_bigint, y_bigint);

    Botan::ECDSA_PublicKey publicKey(secp256k1, point);
    Botan::PK_Verifier verifier(publicKey, "EMSA1(SHA-256)",
                                Botan::DER_SEQUENCE);
    verifier.update(messages);

    return verifier.check_signature(signature);
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return false;
  }
}
