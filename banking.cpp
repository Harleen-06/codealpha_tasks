#include <iostream>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
    double balance = 0;
    vector<Transaction> history;

public:
    void deposit(double amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
    }

    void withdraw(double amt) {
        if (amt > balance) cout << "Insufficient funds!\n";
        else {
            balance -= amt;
            history.push_back(Transaction("Withdraw", amt));
        }
    }

    void transfer(Account &to, double amt) {
        if (amt > balance) cout << "Insufficient funds!\n";
        else {
            balance -= amt; to.balance += amt;
            history.push_back(Transaction("Transfer To", amt));
            to.history.push_back(Transaction("Transfer From", amt));
        }
    }

    void showBalance() const {
        cout << "Current Balance: Rs. " << balance << "\n";
    }

    void showHistory() const {
        cout << "\n--- Transaction History ---\n";
        for (const auto &t : history)
            cout << t.type << ": Rs. " << t.amount << "\n";
    }
};

class Customer {
public:
    string name;
    Account acc;
    Customer(string n) : name(n) {}
};

int main() {
    string name1, name2;
    cout << "Enter your name: ";
    cin >> name1;
    cout << "Enter second customer's name: ";
    cin >> name2;

    Customer c1(name1), c2(name2);

    int ch;
    double amt;

    do {
        cout << "\n1.Deposit  2.Withdraw  3.Transfer  4.Balance  5.History  6.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Amount to deposit: Rs. "; cin >> amt;
                c1.acc.deposit(amt); break;
            case 2:
                cout << "Amount to withdraw: Rs. "; cin >> amt;
                c1.acc.withdraw(amt); break;
            case 3:
                cout << "Amount to transfer to " << c2.name << ": Rs. "; cin >> amt;
                c1.acc.transfer(c2.acc, amt); break;
            case 4:
                cout << c1.name << "'s "; c1.acc.showBalance(); break;
            case 5:
                cout << c1.name << "'s "; c1.acc.showHistory(); break;
            case 6:
                cout << "Thank you!\n"; break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 6);

    return 0;
}

