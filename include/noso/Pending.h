// Pending.h
#ifndef PENDING_H
#define PENDING_H

#include <string>

class Pending {
private:
  std::string orderId;
  std::string orderType;
  std::string sender;
  std::string receiver;
  double amountTransfer;
  double amountFee;

public:
  Pending(const std::string &orderId = "", const std::string &orderType = "",
          const std::string &sender = "", const std::string &receiver = "",
          double amountTransfer = 0, double amountFee = 0)
      : orderId(orderId), orderType(orderType), sender(sender),
        receiver(receiver), amountTransfer(amountTransfer),
        amountFee(amountFee) {}

  Pending copyWith(const std::string &orderId, const std::string &orderType,
                   const std::string &sender, const std::string &receiver,
                   double amountTransfer, double amountFee) const {
    return Pending(orderId.empty() ? this->orderId : orderId,
                   orderType.empty() ? this->orderType : orderType,
                   sender.empty() ? this->sender : sender,
                   receiver.empty() ? this->receiver : receiver,
                   amountTransfer == 0 ? this->amountTransfer : amountTransfer,
                   amountFee == 0 ? this->amountFee : amountFee);
  }
};
#endif