#include <iostream>
#include <string>
#include <limits>

using namespace std;

class User {
public:
    User() : id(""), password("") {}

void login() {
    string inputId, inputPass;
    const string correctId = "1";
    const string correctPass = "1111";
    bool loginSuccess = false;

    while (!loginSuccess) {
        system("clear");
        cout << "=================================" << endl;
        cout << "          Log in User" << endl;
        cout << "=================================" << endl;

        while (true) {
            cout << "ID: ";
            cin >> inputId;

            if (inputId == correctId) {
                break;
            } else {
                cout << "Invalid ID. Please try again." << endl;
            }
        }

        while (true) {
            cout << "Pass: ";
            cin >> inputPass;

            if (inputPass == correctPass) {
                loginSuccess = true;
                setId(inputId);
                setPassword(inputPass);
                mainMenu();
                break;
            } else {
                cout << "Invalid Password. Please try again." << endl;
            }
        }
    }
}

    void mainMenu() {
        int choice;
        do {
            system("clear");
            // system("clear");

            cout << "=================================" << endl;
            cout << "        Main Menu (User)" << endl;
            cout << "=================================" << endl;
            cout << "1. Manage profile User" << endl;
            cout << "2. View total dengue cases" << endl;
            cout << "3. View daily dengue cases" << endl;
            cout << "4. View dengue cases alert message" << endl;
            cout << "5. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    manageProfile();
                    break;
                case 2:
                    viewTotalDengueCases();
                    break;
                case 3:
                    viewDailyDengueCases();
                    break;
                case 4:
                    viewDengueCasesAlertMessage();
                    break;
                case 5:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        } while (choice != 5);
    }

    // Getter and Setter for id
    void setId(const string& newId) {
        id = newId;
    }
    string getId() const {
        return id;
    }

    // Getter and Setter for password
    void setPassword(const string& newPass) {
        password = newPass;
    }
    string getPassword() const {
        return password;
    }

private:
    string id;
    string password;

    void manageProfile() {
        // Implement manage profile User
        cout << "Managing profile..." << endl;
    }

    void viewTotalDengueCases() {
        // Implement view total dengue cases
        cout << "Viewing total dengue cases..." << endl;
    }

    void viewDailyDengueCases() {
        // Implement view daily dengue cases
        cout << "Viewing daily dengue cases..." << endl;
    }

    void viewDengueCasesAlertMessage() {
        // Implement view dengue cases alert message
        cout << "Viewing dengue cases alert messages..." << endl;
    }
};