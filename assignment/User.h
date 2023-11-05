#include <iostream>
#include <string>
#include <vector>
#include <limits>
// #include "UserFunction.h"
#include "AnnualData.h"

using namespace std;

class User {
public:
    User() {}

    // New Method for initial menu
    void initialMenu() {
        int choice;
        do {
            system("clear");
            cout << "=================================" << endl;
            cout << "        Welcome Menu" << endl;
            cout << "=================================" << endl;
            cout << "1. Log in" << endl;
            cout << "2. Register New User ID" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    initializeCredentials();
                    break;
                case 3:
                    cout << "Exiting..." << endl;
                default:
                    cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                    break;
            }
        } while (choice != 3);
    }


    void initializeCredentials() {
        system("clear");
        string inputId, inputPass;
        cout << "=================================" << endl;
        cout << "     Register New User" << endl;
        cout << "=================================" << endl;

        cout << "Enter new ID: ";
        cin >> inputId;
        setId(inputId);

        cout << "Enter new Password: ";
        cin >> inputPass;
        setPassword(inputPass);
    }

    void login() {
        string inputId, inputPass;
        bool loginSuccess = false;

        while (!loginSuccess) {
            system("clear");
            cout << "=================================" << endl;
            cout << "          Log in User" << endl;
            cout << "=================================" << endl;

            cout << "ID: ";
            cin >> inputId;

            if (inputId == getId()) {
                cout << "Pass: ";
                cin >> inputPass;

                if (inputPass == getPassword()) {
                    loginSuccess = true;
                    mainMenu();
                } else {
                    cout << "Invalid Password. Please try again." << endl;
                }
            } else {
                cout << "Invalid ID. Please try again." << endl;
            }
        }
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

private:
    vector<string> credentials; // index 0 for ID, index 1 for Password
    string stateOfResidence;
    string phoneNumber;


    void manageProfile() {
        int choice;
    do {
        system("clear");
        // It's better to clear or print a header here to separate different interactions
        cout << "=================================" << endl;
        cout << "        Manage Profile" << endl;
        cout << "=================================" << endl;

        // Display the current information
        cout << "Current State of Residence: " << (stateOfResidence.empty() ? "Not Set" : stateOfResidence) << endl;
        cout << "Current Phone Number: " << (phoneNumber.empty() ? "Not Set" : phoneNumber) << endl;

        cout << "---------------------------------" << endl;
        cout << "1. Set State of Residence" << endl;
        cout << "2. Set Phone Number" << endl;
        cout << "3. Delete State of Residence" << endl;
        cout << "4. Delete Phone Number" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("clear");
                changeCurrentState();
                break;
            case 2:
                cout << "Enter new phone number: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush the newline out of the buffer
                getline(cin, phoneNumber);
                break;
            case 3:
                stateOfResidence.clear();
                cout << "State of residence deleted." << endl;
                break;
            case 4:
                phoneNumber.clear();
                cout << "Phone number deleted." << endl;
                break;
            case 5:
                // Return to the main menu
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);
}
     
    void changeCurrentState() {
    int option;
    do {
        cout << "Select the new Current State of Residence:" << endl;
        cout << "1. JOHOR\n";
        cout << "2. KEDAH\n";
        cout << "3. KELANTAN\n";
        cout << "4. MELAKA\n";
        cout << "5. NEGERI SEMBILAN\n";
        cout << "6. PAHANG\n";
        cout << "7. PERLIS\n";
        cout << "8. PULAU PINANG\n";
        cout << "9. SABAH\n";
        cout << "10. SARAWAK\n";
        cout << "11. SELANGOR\n";
        cout << "12. TERENGGANU\n";
        cout << "13. WP KUALA LUMPUR\n";
        cout << "14. WP LABUAN\n";
        cout << "Enter your choice: ";
        cin >> option;
        system("clear");

        if (option >= 1 && option <= 14) {
            const string states[] = {
                "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
                "PAHANG", "PERLIS", "PULAU PINANG", "SABAH", "SARAWAK", "SELANGOR",
                "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
            };
            stateOfResidence = states[option - 1];
            cout << "Current State of Residence changed to: " << stateOfResidence << endl;
            return;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 14." << endl;
        }
    } while (true);

}

    void viewTotalDengueCases() {
        cout << "Viewing total dengue cases..." << endl;

        AnnualDataList* dataList = AnnualDataList::getInstance();

        cout << "Would you like to view by (1) Year or (2) State? Enter the number: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            // View by year
            cout << "Enter the years you want to view, separated by space (type 'done' to finish): ";
            vector<int> years;
            string input;
            while (true) {
                cin >> input;
                if (input == "done") break;
                try {
                    years.push_back(stoi(input));
                } catch (...) {
                    cout << "Invalid input, please enter a number or 'done' to finish: ";
                }
            }

            // Calculate the total cases for selected years
            for (int year : years) {
                int totalCases = dataList->getTotalDengueCasesForYear(year);
                cout << "Total dengue cases for year " << year << ": " << totalCases << endl;
            }
        } else if (choice == 2) {
            // View by state
            cout << "Enter the states you want to view, separated by space (type 'done' to finish): ";
            vector<string> states;
            string state;
            while (true) {
                cin >> state;
                if (state == "done") break;
                states.push_back(state);
            }

            // You will need to implement a method in the AnnualDataList class to support getting total cases by state.
            // For now, let's assume there is a method called getTotalDengueCasesForState(const string& state)
            for (const string& state : states) {
                // This line assumes you have such a function defined and implemented in AnnualDataList
                int totalCases = dataList->getTotalDengueCasesForState(state);
                cout << "Total dengue cases for state " << state << ": " << totalCases << endl;
            }
        } else {
            cout << "Invalid choice." << endl;
        }
    
    }

    void viewDailyDengueCases() {
    }

    void viewDengueCasesAlertMessage() {
        //WAIT FOR ZK TO FINISH
        //Implement view dengue cases alert message
        cout << "Viewing dengue cases alert messages..." << endl;
    }

    void personalPastDengueFeverStatus() {
        //view personal's past dengue fever
        cout << "Viewing personal's past dengue cases..." << endl;
    }

    // Setter for id
    void setId(const string& newId) {
        if (credentials.size() < 1) credentials.push_back(newId);
        else credentials[0] = newId;
    }
    // Getter for id
    string getId() const {
        if (credentials.size() > 0) return credentials[0];
        return "";
    }

    // Setter for password
    void setPassword(const string& newPass) {
        if (credentials.size() < 2) {
            if (credentials.size() < 1) credentials.push_back("");
            credentials.push_back(newPass);
        } else {
            credentials[1] = newPass;
        }
    }
    // Getter for password
    string getPassword() const {
        if (credentials.size() > 1) return credentials[1];
        return "";
    }
};




