#include <iostream>
#include <string>

using namespace std; // You already have this, no need for std::cout

class User {
public:
    User() {
        // Constructor implementation
    }

    void login() {
        string inputId, inputPass;
        cout << "" <<endl;
        cout << "=================================" << endl;
        cout << "          Log in User" << endl;
        cout << "=================================" << endl;
        cout << "ID: ";
        cin >> inputId;
        cout << "Pass: ";
        cin >> inputPass;

        // Here you should verify the id and password
        // For now, let's assume it's always correct
        setId(inputId);
        setPassword(inputPass);
        mainMenu();
    }

    void mainMenu() {
        int choice;
        do {
            system("clear");
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
    void setId(const std::string& newId) {
        id = newId;
    }
    std::string getId() const {
        return id;
    }

    // Getter and Setter for password
    void setPassword(const std::string& newPass) {
        password = newPass;
    }
    std::string getPassword() const {
        return password;
    }

private:
    std::string id;
    std::string password;

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
