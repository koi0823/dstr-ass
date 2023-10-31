#include <iostream>
#include <string>

using namespace std;

class MOHAdmin {
public:
    MOHAdmin() {
        // Constructor implementation
    }

void login() {
    string inputId, inputPass;
    const string correctId = "3";
    const string correctPass = "3333";
    bool loginSuccess = false;

    while (!loginSuccess) {
        system("clear");  // Clear screen for Windows
        // system("clear");  // Clear screen for Linux/Mac

        cout << "=================================" << endl;
        cout << "         Log in MOH admin" << endl;
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
            cout << "=================================" << endl;
            cout << "      Main Menu (MOH_admin)" << endl;
            cout << "=================================" << endl;
            cout << "1. View all state dengue cases" << endl;
            cout << "2. Send alert message to user" << endl;
            cout << "3. Manage doctor account" << endl;
            cout << "4. Manage User account" << endl;
            cout << "5. Logout" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    viewAllStateDengueCases();
                    break;
                case 2:
                    sendAlertMessageToUser();
                    break;
                case 3:
                    manageDoctorAccount();
                    break;
                case 4:
                    manageUserAccount();
                    break;
                case 5:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        } while (choice != 5);
    }

    void setId(const string& newId) {
        id = newId;
    }

    string getId() const {
        return id;
    }

    void setPassword(const string& newPassword) {
        password = newPassword;
    }

    string getPassword() const {
        return password;
    }

private:
    string id;
    string password;

    void viewAllStateDengueCases() {
        // Implement view all state dengue cases
        cout << "Viewing all state dengue cases..." << endl;
    }

    void sendAlertMessageToUser() {
        // Implement send alert message to user
        cout << "Sending alert message to user..." << endl;
    }

    void manageDoctorAccount() {
        // Implement manage doctor account
        cout << "Managing doctor account..." << endl;
    }

    void manageUserAccount() {
        // Implement manage User account
        cout << "Managing User account..." << endl;
    }
};
