#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    int failedAttempts;

public:
    BankAccount();
    BankAccount(string accNum, string owner, double bal);

    string getAccountNumber() const;
    string getOwnerName() const;
    long long getBalance() const;

    bool deposit(double amount);
    bool withdraw(double amount);

    void increaseFailedAttempts();
    void resetFailedAttempts();
    bool isLocked() const;

    void displayInfo() const;
};

#endif