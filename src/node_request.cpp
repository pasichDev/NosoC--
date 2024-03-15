#include "../include/node_request.hpp"

namespace NodeRequest {
const std::string getNodeStatus = "NODESTATUS\n";
const std::string getNodeList = "NSLMNS\n";
const std::string getPendingsList = "NSLPENDFULL\n";
const std::string getSummaryZip = "GETZIPSUMARY\n";

std::string getAddressBalance(const std::string &hash) {
  return "NSLBALANCE " + hash + "\n";
}
} // namespace NodeRequest
