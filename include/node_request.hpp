// Signer.h
#ifndef NODE_REQUEST_H
#define NODE_REQUEST_H

#include <string>

namespace NodeRequest {
// Returns information about the node according to node.dart
extern const std::string getNodeStatus;

// Method that returns a list of working nodes in the current block
extern const std::string getNodeList;

// Returns the list of pendings in the network, if there are none, returns an
// empty string. According to the pending.dart model
extern const std::string getPendingsList;

// Returns a summary.zip in bytes to be unpacked and written according to the
// summary.dart model
extern const std::string getSummaryZip;

// Returns the actual balance of the address
std::string getAddressBalance(const std::string &hash);
} // namespace NodeRequest
#endif // SIGNER_H