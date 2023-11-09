#ifndef MANAGE_ACCOUNT_H
#define MANAGE_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class manageAccount {
public:
    manageAccount(string& docId, string& password, string& currentState, string& phoneNumber)
        : docId(docId), password(password), currentState(currentState), phoneNumber(phoneNumber) {
    }

    void manageProfile() {
        int choice;
        do {
            cout << "=================================" << endl;
            cout << "      Manage Profile (Doctor)\n";
            cout << "=================================" << endl;
            cout << "What would you like to do?" << endl;
            cout << "1. Update Profile\n";
            cout << "2. Delete Profile\n";
            cout << "3. Go back to Main Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                int action;
                    do {
                        cout << "=================================" << endl;
                        cout << "      Manage Profile (Doctor)\n";
                        cout << "=================================" << endl;
                        cout << "What would you like to do?" << endl;
                        cout << "1. Update ID\n";
                        cout << "2. Update Password\n";
                        cout << "3. Go back to Main Menu\n";
                        cout << "Select an action: ";
                        cin >> action;
                        system("clear");

                        switch (action)
                        {
                        case 1:
                            changeDocId();
                            break;
                        
                        case 2:
                            changePassword();
                            break;

                        case 3:
                            return; // Go back to the main menu
                        
                        default:
                            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                    }
                } while (choice != 3);
                    break;

                case 2:
                    deleteDocAcc();
                    break;

                case 3:
                    return; // Go back to the main menu

                default:
                    cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            }
        } while (choice != 3);
    }

    void deleteDocAcc() {
        string newId;
        // cout << "Enter the new User ID: ";
        newId = 5;
        docId = newId;
        cout << "Account Deleted" << endl;
    }

    void changeDocId() {
        string newId;
        cout << "Enter the new User ID: ";
        cin >> newId;
        docId = newId;
        cout << "User ID changed to: " << docId << endl;
    }

    void changePassword() {
        string newPassword;
        cout << "Enter the new Password: ";
        cin >> newPassword;
        password = newPassword;
        cout << "Password changed" << endl;
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
            currentState = states[option - 1];
            cout << "Current State of Residence changed to: " << currentState << endl;
            return;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 14." << endl;
        }
    } while (true);

}

    void changePhoneNumber() {
    string newPhoneNumber;
    while (true) {
        cout << "Enter the new Phone Number (10 digits, ex. 0178901000): ";
        cin >> newPhoneNumber;
        
        if (newPhoneNumber.length() == 10 && isNumeric(newPhoneNumber)) {
            phoneNumber = newPhoneNumber;
            cout << "Phone Number changed to: " << phoneNumber << endl;
            break;
        } else {
            cout << "Invalid phone number. Please enter a 10-digit number." << endl;
        }
    }
}

bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

const string& getDocId() const {
        return docId;
}

private:
    string& docId;
    string& password;
    string& currentState;
    string& phoneNumber;
};

#endif // MANAGE_ACCOUNT_H