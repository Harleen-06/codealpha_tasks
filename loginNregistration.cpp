#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string FILENAME = "users.txt";

bool isDuplicate(string username) {
    ifstream file(FILENAME);
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) return true;
    }
    return false;
}

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    if (isDuplicate(username)) {
        cout << " Username already exists. Try another.\n";
        return;
    }
    ofstream file(FILENAME, ios::app);
    file << username << " " << password << endl;
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(FILENAME);
    string user, pass;
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            cout << " Login successful! Welcome, " << username << ".\n";
            return;
        }
    }

    cout << " Invalid username or password.\n";
}
int main() {
    int choice;

    while (true) {
        cout << "\n~Login and Registration System~\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            loginUser();
        } else if (choice == 3) {
            cout << "Thank you for using the system.\n";
            break; 
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
