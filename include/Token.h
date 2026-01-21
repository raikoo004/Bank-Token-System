#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ctime>

class Token {
public:
    int tokenNumber;
    std::string customerName;
    std::string serviceType;
    int priority;

    time_t issueTime;
    time_t serviceStartTime;
    time_t serviceEndTime;

    Token(int number, std::string name, std::string service, int prio);

    int getWaitTime() const;
    int getServiceDuration() const;
};

#endif
