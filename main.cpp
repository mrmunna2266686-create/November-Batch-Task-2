
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password, confirmPassword;

    cout << "\n========== REGISTRATION ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream checkFile("users.txt");
    string savedUser, savedPass;

    while (checkFile >> savedUser >> savedPass) {
        if (savedUser == username) {
            cout << "Username already exists!\n";
            checkFile.close();
            return;
        }
    }
    checkFile.close();

    cout << "Enter Password: ";
    cin >> password;

    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if (password != confirmPassword) {
        cout << "Passwords do not match!\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration Successful!\n";
}

void loginUser() {
    string username, password;
    string savedUser, savedPass;

    cout << "\n========== LOGIN ==========\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    if (!file) {
        cout << "No registered users found!\n";
        return;
    }

    while (file >> savedUser >> savedPass) {
        if (savedUser == username &&
            savedPass == password) {

            cout << "\nLogin Successful!\n";
            cout << "Welcome, " << username << "!\n";

            file.close();
            return;
        }
    }

    file.close();
    cout << "\nInvalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n================================\n";
        cout << "   REGISTRATION AND LOGIN SYSTEM\n";
        cout << "================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using our system!\n";
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 3);

    return 0;
}
