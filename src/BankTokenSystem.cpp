#include <iostream>
#include <queue>
#include "../include/BankTokenSystem.h"
#include "../include/Token.h"
#include "../include/ComparePriority.h"



#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <ctime>

using namespace std;

// =======================
// Constructor / Destructor
// =======================

BankTokenSystem::BankTokenSystem()
    : tokenCounter(1),
      totalIssued(0),
      totalServed(0),
      sessionStartTime(time(nullptr)) {}

BankTokenSystem::~BankTokenSystem() {
    clearAll();
}

// =======================
// Private Helpers
// =======================

void BankTokenSystem::clearAll() {
    while (!waitingQueue.empty()) {
        delete waitingQueue.top();
        waitingQueue.pop();
    }

    while (!servingQueue.empty()) {
        delete servingQueue.front();
        servingQueue.pop();
    }

    for (Token* t : completedQueue) {
        delete t;
    }
    completedQueue.clear();
}

string BankTokenSystem::formatDuration(int seconds) const {
    int mins = seconds / 60;
    int secs = seconds % 60;
    stringstream ss;
    ss << mins << "m " << secs << "s";
    return ss.str();
}

// =======================
// Core Operations
// =======================

void BankTokenSystem::issueToken() {
    string name, service;
    int serviceChoice;

    cout << "\n--- Issue New Token ---\n";
    cout << "Enter customer name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "[X] Name cannot be empty!\n";
        return;
    }

    cout << "\nSelect Service:\n";
    cout << "1. Cash Service\n";
    cout << "2. Account Services\n";
    cout << "3. Loan Services\n";
    cout << "4. Other Services\n";
    cout << "Choice: ";
    cin >> serviceChoice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (serviceChoice) {
        case 1: service = "Cash Service"; break;
        case 2: service = "Account Services"; break;
        case 3: service = "Loan Services"; break;
        case 4: service = "Other Services"; break;
        default:
            cout << "[X] Invalid choice!\n";
            return;
    }

    char pr;
    int priority = 2;
    cout << "Senior Citizen / Disabled? (y/n): ";
    cin >> pr;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (pr == 'y' || pr == 'Y')
        priority = 1;

    Token* t = new Token(tokenCounter++, name, service, priority);
    waitingQueue.push(t);
    totalIssued++;

    cout << "\n[+] Token #" << setw(3) << setfill('0') << t->tokenNumber
         << " issued (" << (priority == 1 ? "HIGH" : "NORMAL") << " priority)\n";
}

void BankTokenSystem::callNext() {
    if (waitingQueue.empty()) {
        cout << "[!] No customers waiting.\n";
        return;
    }

    Token* t = waitingQueue.top();
    waitingQueue.pop();

    t->serviceStartTime = time(nullptr);
    servingQueue.push(t);

    cout << "\n=================================\n";
    cout << " NOW SERVING TOKEN #" << setw(3) << setfill('0') << t->tokenNumber << "\n";
    cout << " Customer : " << t->customerName << "\n";
    cout << " Service  : " << t->serviceType << "\n";
    cout << " Priority : " << (t->priority == 1 ? "HIGH" : "NORMAL") << "\n";
    cout << " Waited   : " << formatDuration(t->getWaitTime()) << "\n";
    cout << "=================================\n";
}

void BankTokenSystem::completeService() {
    if (servingQueue.empty()) {
        cout << "[!] No active service.\n";
        return;
    }

    Token* t = servingQueue.front();
    servingQueue.pop();

    t->serviceEndTime = time(nullptr);
    completedQueue.push_back(t);
    totalServed++;

    cout << "\n[✓] Service completed for Token #"
         << setw(3) << setfill('0') << t->tokenNumber << "\n";
    cout << " Service Time: "
         << formatDuration(t->getServiceDuration()) << "\n";
}

// =======================
// Display Functions
// =======================

void BankTokenSystem::displayWaitingQueue() const {
    if (waitingQueue.empty()) {
        cout << "\n[Waiting Queue] Empty\n";
        return;
    }

    priority_queue<Token*, vector<Token*>, ComparePriority> temp = waitingQueue;
    int pos = 1;

    cout << "\n--- WAITING QUEUE ---\n";
    while (!temp.empty()) {
        Token* t = temp.top();
        temp.pop();

        cout << pos++ << ". Token #"
             << setw(3) << setfill('0') << t->tokenNumber
             << " | " << setw(20) << left << t->customerName
             << " | " << (t->priority == 1 ? "HIGH" : "NORMAL") << "\n";
    }
}

void BankTokenSystem::displayCurrentlyServing() const {
    if (servingQueue.empty()) {
        cout << "\n[Currently Serving] None\n";
        return;
    }

    cout << "\n--- CURRENTLY SERVING ---\n";
    queue<Token*> temp = servingQueue;

    while (!temp.empty()) {
        Token* t = temp.front();
        temp.pop();

        int elapsed = static_cast<int>(
            difftime(time(nullptr), t->serviceStartTime));

        cout << "Token #" << setw(3) << setfill('0') << t->tokenNumber
             << " | " << t->customerName
             << " | Elapsed: " << formatDuration(elapsed) << "\n";
    }
}

void BankTokenSystem::displayCompletedJobs() const {
    if (completedQueue.empty()) {
        cout << "\n[Completed] None\n";
        return;
    }

    cout << "\n--- COMPLETED SERVICES ---\n";
    for (Token* t : completedQueue) {
        cout << "Token #" << setw(3) << setfill('0') << t->tokenNumber
             << " | " << setw(20) << left << t->customerName
             << " | Service: "
             << formatDuration(t->getServiceDuration()) << "\n";
    }
}

void BankTokenSystem::displayStatistics() const {
    time_t now = time(nullptr);
    int duration = static_cast<int>(difftime(now, sessionStartTime));

    cout << "\n--- SYSTEM STATISTICS ---\n";
    cout << "Total Issued      : " << totalIssued << "\n";
    cout << "Total Served      : " << totalServed << "\n";
    cout << "Waiting           : " << waitingQueue.size() << "\n";
    cout << "Being Served      : " << servingQueue.size() << "\n";
    cout << "Completed         : " << completedQueue.size() << "\n";
    cout << "Session Duration  : " << formatDuration(duration) << "\n";
}
