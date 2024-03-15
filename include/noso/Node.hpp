// Node.h
#ifndef NODE_H
#define NODE_H

#include "Seed.hpp"
#include <string>

class Node {
private:
  Seed seed;
  int connections;
  int lastblock;
  int pendings;
  int delta;
  std::string branch;
  std::string version;
  int utcTime;

public:
  Node(const Seed &seed, int connections = 0, int lastblock = 0,
       int pendings = 0, int delta = 0, const std::string &branch = "",
       const std::string &version = "", int utcTime = 0)
      : seed(seed), connections(connections), lastblock(lastblock),
        pendings(pendings), delta(delta), branch(branch), version(version),
        utcTime(utcTime) {}

  Node copyWith(const Seed &seed, int connections, int lastblock, int pendings,
                int delta, const std::string &branch,
                const std::string &version, int utcTime) const {
    return Node(seed, connections == 0 ? this->connections : connections,
                lastblock == 0 ? this->lastblock : lastblock,
                pendings == 0 ? this->pendings : pendings,
                delta == 0 ? this->delta : delta,
                branch.empty() ? this->branch : branch,
                version.empty() ? this->version : version,
                utcTime == 0 ? this->utcTime : utcTime);
  }
};
#endif
