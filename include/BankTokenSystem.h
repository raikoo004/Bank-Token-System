#ifndef BANK_TOKEN_SYSTEM_H
#define BANK_TOKEN_SYSTEM_H

#include <queue>
#include <vector>
#include <string>
#include <ctime>

#include "Token.h"
#include "ComparePriority.h"

class BankTokenSystem {
private:
    // Core data structures
    std::priority_queue<Token*, std::vector<Token*>, ComparePriority> waitingQueue;
    std::queue<Token*> servingQueue;
    std::vector<Token*> completedQueue;

    // Statistics
    int tokenCounter;
    int totalIssued;
    int totalServed;
    time_t sessionStartTime;

    // Helpers
    void clearAll();
    std::string formatDuration(int seconds) const;

public:
    BankTokenSystem();
    ~BankTokenSystem();

    // Core operations
    void issueToken();
    void callNext();
    void completeService();

    // Display operations
    void displayWaitingQueue() const;
    void displayCurrentlyServing() const;
    void displayCompletedJobs() const;
    void displayStatistics() const;
};

#endif
