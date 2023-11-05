#include <iostream>
#include <string>
#include "LoadData.h"
#include "DoctorProfileManager.h"
#include "patientReport.h"
#include "findDenguebyName.h"
#include "findDenguebyAgeState.h"
#include "viewDengueCasesWeekly.h"
#include <vector>
#include <algorithm>

using namespace std;

class Doctor {
WeeklyDataStack myWeeklyData;

public:
     Doctor()
        : id("2"), password("2222"), currentState("SABAH"), phoneNumber("0178901000"), doctorProfile(id, password, currentState, phoneNumber) {
        // Default constructor implementation
    }

    void login() {
        string inputId, inputPass;
        bool loginSuccess = false;

        while (!loginSuccess) {
            system("clear");
            cout << "=================================" << endl;
            cout << "          Log in Doctor" << endl;
            cout << "=================================" << endl;

            while (true) {
                cout << "ID: ";
                cin >> inputId;

                if (inputId == id) {
                    break;
                } else {
                    cout << "Invalid ID. Please try again." << endl;
                }
            }

            while (true) {
                cout << "Pass: ";
                cin >> inputPass;

                if (inputPass == password) {
                    loginSuccess = true;
                    setId(inputId);
                    setPassword(inputPass);
                    system("clear");
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
            cout << "=================================" << endl;
            cout << "        Main Menu (Doctor)\n";
            cout << "=================================" << endl;
            cout << "1. Manage profile Doctor\n";
            cout << "2. Report patient\n";
            cout << "3. View all Dengue cases\n";
            cout << "4. Find number of dengues cases base by patient name\n";
            cout << "5. Find number of dengue cases base by age and range\n";
            cout << "6. Logout\n";
            cout << "Enter your choice: ";
            cin >> choice;
            system("clear");

            switch (choice) {
                case 1:
                    manageProfile();
                    break;
                case 2:
                    reportPatient();
                    break;
                case 3:
                    loadDataAndDisplay();
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

private :
    string id;
    string password;
    string currentState;
    string phoneNumber;
    string patientName;
    string patientAge;
    string infectionDate;
    string patientState;
    string doctorId;
    string fever;
    vector<PatientReport> cases;
    DoctorProfileManager doctorProfile;
    void manageProfile() {
        cout << "Managing Doctor profile..." << endl;
        DoctorProfileManager profileManager(id, password, currentState, phoneNumber);
        profileManager.manageProfile();
    }

    void reportPatient() {
        cout << "Reporting patient..." << endl;
    
        // Create an instance of the PatientReport class and call the reportPatient method
        PatientReport patientReport(patientName, patientAge, infectionDate, patientState, doctorProfile, fever);
        cases.push_back(patientReport);
    }

    void loadDataAndDisplay() {
        
    // Implement view all Dengue cases
    cout << "Viewing all Dengue cases..." << endl;
    DengueCaseViewer viewDengueWeekly;
    viewDengueWeekly.viewWeeklyCases();

    }


    void findDenguesOfCases() {
        
        // Implement find dengues of cases
        cout << "Finding Dengues of cases..." << endl;
        // Populate the patientCases vector with patient data
        cout << "Enter the patient name to search for: ";
        cin >> patientName;

        for (const PatientReport& report : cases) {
            cout << "Patient Name: " << report.getPatientName() << endl;
    }

        FindDenguebyName::findDenguesOfCases(patientName, cases);
    }

    void findNumberOfCases() {
        // Implement find Number of cases
        cout << "Finding Number of cases..." << endl;

        // Create an instance of the FindDenguebyAgeState class
        FindDenguebyAgeState findDengueCasesAgeState;

        // Call the function to find cases by age and state
        findDengueCasesAgeState.findDengueCasesByAgeAndState();
    }
};
