#include <iostream>
#include <vector>
#include <limits>
#include "BankAccount.h"

using namespace std;

int findAccountIndex(const vector<BankAccount>& accounts, string accNum) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNum)
            return i;
    }
    return -1;
}

double inputMoney() {
    double amount;

    while (true) {
        cin >> amount;

        if (cin.fail() || amount < 0) {
            cout << "Du lieu khong hop le. Vui long nhap lai: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return amount;
        }
    }
}

int main() {

    vector<BankAccount> accounts;
    int choice;

    do {

        cout << "\n========== QUAN LY TAI KHOAN NGAN HANG ==========\n";
        cout << "1. Tao tai khoan moi\n";
        cout << "2. Nap tien\n";
        cout << "3. Rut tien\n";
        cout << "4. Xem thong tin tai khoan\n";
        cout << "5. Tim tai khoan theo so tai khoan\n";
        cout << "6. Hien thi danh sach tai khoan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";

        cin >> choice;

        switch(choice) {

        case 1: {

            string accNum, owner;
            double balance;

            cout << "Nhap so tai khoan: ";
            cin >> accNum;

            if (findAccountIndex(accounts, accNum) != -1) {
                cout << "So tai khoan da ton tai!\n";
                break;
            }

            cin.ignore();

            cout << "Nhap ten chu tai khoan: ";
            getline(cin, owner);

            cout << "Nhap so du ban dau: ";
            balance = inputMoney();

            accounts.push_back(
                BankAccount(accNum, owner, balance)
            );

            cout << "Tao tai khoan thanh cong!\n";
            break;
        }

        case 2: {

            string accNum;

            cout << "Nhap so tai khoan: ";
            cin >> accNum;

            int idx = findAccountIndex(accounts, accNum);

            if (idx == -1) {
                cout << "Khong tim thay tai khoan!\n";
                break;
            }

            double amount;

            cout << "Nhap so tien nap: ";
            cin >> amount;

            if (!accounts[idx].deposit(amount)) {

                accounts[idx].increaseFailedAttempts();

                cout << "So tien nap phai lon hon 0!\n";
                cout << "So lan sai: "
                     << accounts[idx].isLocked()
                     << "/5\n";

                if (accounts[idx].isLocked()) {

                    cout << "Tai khoan da bi khoa va xoa khoi he thong!\n";

                    accounts.erase(accounts.begin() + idx);
                }

            } else {

                accounts[idx].resetFailedAttempts();

                cout << "Nap tien thanh cong!\n";
            }

            break;
        }

        case 3: {

            string accNum;

            cout << "Nhap so tai khoan: ";
            cin >> accNum;

            int idx = findAccountIndex(accounts, accNum);

            if (idx == -1) {
                cout << "Khong tim thay tai khoan!\n";
                break;
            }

            double amount;

            cout << "Nhap so tien rut: ";
            cin >> amount;

            if (!accounts[idx].withdraw(amount)) {

                accounts[idx].increaseFailedAttempts();

                cout << "Rut tien that bai!\n";

                if (accounts[idx].isLocked()) {

                    cout << "Tai khoan da bi khoa va xoa khoi he thong!\n";

                    accounts.erase(accounts.begin() + idx);
                }

            } else {

                accounts[idx].resetFailedAttempts();

                cout << "Rut tien thanh cong!\n";
            }

            break;
        }

        case 4: {

            string accNum;

            cout << "Nhap so tai khoan: ";
            cin >> accNum;

            int idx = findAccountIndex(accounts, accNum);

            if (idx == -1)
                cout << "Khong tim thay tai khoan!\n";
            else
                accounts[idx].displayInfo();

            break;
        }

        case 5: {

            string accNum;

            cout << "Nhap so tai khoan can tim: ";
            cin >> accNum;

            int idx = findAccountIndex(accounts, accNum);

            if (idx == -1)
                cout << "Khong tim thay tai khoan!\n";
            else
                accounts[idx].displayInfo();

            break;
        }

        case 6: {

            if (accounts.empty()) {
                cout << "Danh sach tai khoan rong!\n";
                break;
            }

            cout << "\n===== DANH SACH TAI KHOAN =====\n";

            for (const auto& acc : accounts) {

                acc.displayInfo();
                cout << "-----------------------------\n";
            }

            break;
        }

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}