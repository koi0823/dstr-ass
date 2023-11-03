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
    loadData.dataload();
    int choice;
    do {
        // system("clear");
        cout << "=================================" << endl;
        cout << "           Home Page           " << endl;
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
                    {
                        User user;
                        user.login();
                        
                    }
                    break;
                case 2:
                    {
                        Doctor doctor;
                        doctor.login();
                    }
                    break;
                case 3:
                    {
                        MOHAdmin mohAdmin;
                        mohAdmin.login();
                    }
                    break;
                case 0:
                    cout << "" << endl;
                    cout << "Thank You for using our system" << endl;
                    cout << "Exiting program..." << endl;
                    break;
            }
        }
    } while (choice != 0);

    return 0;
}
