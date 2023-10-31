#include <iostream>
#include <string>
#include "user.h"
#include "doctor.h"
#include "moh_admin.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "=================================" << endl;
        cout << "             Home Page           " << endl;
        cout << "=================================" << endl;
        cout << "1. User" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. MOH admin" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Please select your choice: ";

        // Ensure the input is valid (an integer)
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid choice (0, 1, 2, 3): "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice < 0 || choice > 3) {
            cout << "Invalid choice. Please enter a valid choice (0, 1, 2, 3): "<<endl;
        } else {
            switch (choice) {
                case 1:
                    // User menu
                    // Implement user-related functionality here
                    break;
                case 2:
                    // Doctor menu
                    // Implement doctor-related functionality here
                    break;
                case 3:
                    // MOH admin menu
                    // Implement MOH admin-related functionality here
                    break;
                case 0:
                    cout << "Exiting program..." << endl;
                    break;
            }
        }
    } while (choice != 0);

    return 0;
}
