#include <iostream>
#include <limits>
#include "../include/BankTokenSystem.h"



using namespace std;

void printMenu() {
    cout << "\n========================================\n";
    cout << "   BANK TOKEN MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << " 1. Issue New Token\n";
    cout << " 2. Call Next Customer\n";
    cout << " 3. Complete Service\n";
    cout << " 4. Display Waiting Queue\n";
    cout << " 5. Display Currently Serving\n";
    cout << " 6. Display Completed Services\n";
    cout << " 7. View Statistics\n";
    cout << " 0. Exit\n";
    cout << "========================================\n";
    cout << "Enter choice: ";
}

int main() {
    BankTokenSystem bank;
    int choice;

    do {
        printMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[X] Invalid input!\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                bank.issueToken();
                break;

            case 2:
                bank.callNext();
                break;

            case 3:
                bank.completeService();
                break;

            case 4:
                bank.displayWaitingQueue();
                break;

            case 5:
                bank.displayCurrentlyServing();
                break;

            case 6:
                bank.displayCompletedJobs();
                break;

            case 7:
                bank.displayStatistics();
                break;

            case 0:
                cout << "\nShutting down system...\n";
                break;

            default:
                cout << "[X] Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    cout << "\n✓ Thank you for using Bank Token Management System!\n";
    return 0;
}
