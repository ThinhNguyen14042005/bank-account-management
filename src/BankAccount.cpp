#include "BankAccount.h"

BankAccount::BankAccount() {
    accountNumber = "";
    ownerName = "";
    balance = 0;
    failedAttempts = 0;
}

BankAccount::BankAccount(string accNum, string owner, double bal) {
    accountNumber = accNum;
    ownerName = owner;

    if (bal >= 0)
        balance = bal;
    else
        balance = 0;

    failedAttempts = 0;
}

string BankAccount::getAccountNumber() const {
    return accountNumber;
}

string BankAccount::getOwnerName() const {
    return ownerName;
}
string formatMoney(long long money) {
    string s = to_string(money);

    int pos = s.length() - 3;

    while (pos > 0) {
        s.insert(pos, ".");
        pos -= 3;
    }

    return s;
}

long long BankAccount::getBalance() const {
    return balance;
}

bool BankAccount::deposit(double amount) {
    if (amount <= 0)
        return false;

    balance += amount;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0 || amount > balance)
        return false;

    balance -= amount;
    return true;
}

void BankAccount::increaseFailedAttempts() {
    failedAttempts++;
}

void BankAccount::resetFailedAttempts() {
    failedAttempts = 0;
}

bool BankAccount::isLocked() const {
    return failedAttempts >= 5;
}

void BankAccount::displayInfo() const {
    cout << "So tai khoan: " << accountNumber << endl;
    cout << "Chu tai khoan: " << ownerName << endl;
    cout << "So du: " << formatMoney(balance) << " VND" << endl;
}