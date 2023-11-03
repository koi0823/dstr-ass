#include <iostream>
#include <string>
#include <limits>
#include "User.h"
#include "Doctor.h"
#include "MOH_admin.h"
#include "LoadData.h"

using namespace std;

int main() {
    LoadData loadData;
    loadData.dataload();  // Assuming this initializes some data needed for login
    int choice;
    // system("clear");
    do {
        cout << "=================================" << endl;
        cout << "           Home Page             " << endl;
        cout << "=================================" << endl;
        cout << "1. User" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. MOH admin" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Please select your choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 0 and 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                {
                    User user;
                    user.login();
                }
                break;
            case 2:
                {
                    Doctor doctor;
                    doctor.login(loadData);
                }
                break;
            case 3:
                {
                    MOHAdmin mohAdmin;
                    mohAdmin.login(loadData);
                }
                break;
            case 0:
                cout << "\nThank You for using our system!" << endl;
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
