#include <iostream>
#include <string>

using namespace std;

class MOHAdmin {
public:
    MOHAdmin() {
        // Constructor implementation
    }

    void login() {
        string id, pass;
        cout << "=================================" << endl;
        cout << "         Log in MOH admin" << endl;
        cout << "=================================" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Pass: ";
        cin >> pass;

        // Here you should verify the id and password
        // For now, let's assume it's always correct
        mainMenu();
    }

    void mainMenu() {
        int choice;
        do {
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
