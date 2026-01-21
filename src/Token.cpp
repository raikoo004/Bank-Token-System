#include "Token.h"
#include <ctime>

Token::Token(int number, std::string name, std::string service, int prio)
    : tokenNumber(number),
      customerName(name),
      serviceType(service),
      priority(prio),
      issueTime(time(nullptr)),
      serviceStartTime(0),
      serviceEndTime(0) {}

int Token::getWaitTime() const {
    time_t endTime = serviceStartTime ? serviceStartTime : time(nullptr);
    return static_cast<int>(difftime(endTime, issueTime));
}

int Token::getServiceDuration() const {
    if (serviceStartTime && serviceEndTime)
        return static_cast<int>(difftime(serviceEndTime, serviceStartTime));
    return 0;
}
