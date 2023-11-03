#include <iostream>
#include <string>

using namespace std;

class Doctor {
public:
    Doctor() {
        // Constructor implementation
    }

void login() {
    string inputId, inputPass;
    const string correctId = "2";
    const string correctPass = "2222";
    bool loginSuccess = false;

    while (!loginSuccess) {
        system("clear");
        cout << "=================================" << endl;
        cout << "          Log in Doctor" << endl;
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
            cout << "        Main Menu (Doctor)\n";
            cout << "=================================" << endl;
            cout << "1. Manage profile Doctor\n";
            cout << "2. Report patient\n";
            cout << "3. View all Dengue cases\n";
            cout << "4. Find dengues of cases\n";
            cout << "5. Find Number of cases\n";
            cout << "6. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    manageProfile();
                    break;
                case 2:
                    reportPatient();
                    break;
                case 3:
                    viewAllDengueCases();
                    break;
                case 4:
                    findDenguesOfCases();
                    break;
                case 5:
                    findNumberOfCases();
                    break;
                case 6:
                    cout << "Logging out..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            }
        } while (choice != 6);
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
    string id;       // Note: No need for std:: prefix
    string password; // Note: No need for std:: prefix

    void manageProfile() {
        // Implement manage profile Doctor
        cout << "Managing Doctor profile..." << endl;
    }

    void reportPatient() {
        // Implement report patient
        cout << "Reporting patient..." << endl;
    }

    void viewAllDengueCases() {
        // Implement view all Dengue cases
        cout << "Viewing all Dengue cases..." << endl;
    }

    void findDenguesOfCases() {
        // Implement find dengues of cases
        cout << "Finding Dengues of cases..." << endl;
    }

    void findNumberOfCases() {
        // Implement find Number of cases
        cout << "Finding Number of cases..." << endl;
    }
};
