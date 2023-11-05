#ifndef PATIENT_REPORT_H
#define PATIENT_REPORT_H

#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include "DoctorProfileManager.h"

using namespace std;

class PatientReport {
public:
    PatientReport(const string& patientName, const string& patientAge, const string& infectionDate, const string& patientState, const DoctorProfileManager& doctorProfile, const string& fever)
        : doctorId(doctorProfile.getDocId()), patientState(patientState), fever(fever) {
    
        displayPatientInfo();
        feverLevel();
        system("clear");
        selectState();
        system("clear");
        reportPatient();
    }

    void displayPatientInfo() {
        cout << "Enter patient's name: ";
        cin >> patientName;

        while (!setPatientName(patientName)) {
            cout << "Patient name is invalid. Please use only alphabetic characters and spaces." << endl;
            cout << "Enter patient's name: ";
            cin >> patientName;
        }
        system("clear");
        cout << "Enter patient's age: ";
        cin >> patientAge;

        while (!setPatientAge(patientAge)) {
            cout << "Invalid age. Age must be between 1 and 99 years." << endl;
            cout << "Enter patient's age: ";
            cin >> patientAge;
        }
        system("clear");
        cout << "Enter infection date (dd/mm/yy ex. 20/10/23): ";
        cin >> infectionDate;

        while (!setInfectionDate(infectionDate)) {
            cout << "Invalid date format. Please use dd/mm/yy format." << endl;
            cout << "Enter infection date (dd/mm/yy ex. 20/10/23): ";
            cin >> infectionDate;
        }
        system("clear");

    }

    void reportPatient() const{
        cout << "" <<endl;
        cout << "Patient Information:" << endl;
        cout << "Name: " << patientName << endl;
        cout << "Age: " << patientAge << " years" << endl;
        cout << "Infection Date(dd/mm/yy ex. 20/10/23): " << infectionDate << endl;
        cout<< "Fever Level: "<< fever<< endl;
        cout << "Patient State: " << patientState << endl;
        cout << "Doctor ID: " << doctorId << endl;
        cout << "" <<endl;

    }

    string getPatientName() const {
            return patientName;
    }

    string getPatientAge() const {
            return patientAge;
    }

    string getInfectionDate() const {
            return infectionDate;
    }

    string getFever()const{
        return fever;
    }

    string getPatientState()const{
        return patientState;
    }


    private:
        string doctorId;
        string patientName;
        string patientAge;
        string infectionDate;
        string patientState;
        string fever;

        vector<PatientReport> cases;


    bool isAlpha(const string& str) {
            return regex_match(str, regex("^[A-Za-z ]+$"));
    }

    bool isValidAge(const string& str) {
            try {
                int age = stoi(str);
                return age >= 1 && age <= 99;
            } catch (const invalid_argument&) {
                return false;
            }
    }

    bool isValidDate(const string& str) {
            return regex_match(str, regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{2}$"));
    }

    bool setPatientName(const string& name) {
            if (isAlpha(name)) {
                patientName = name;
                return true;
            } else {
                return false;
            }
    }

    bool setPatientAge(const string& age) {
            if (isValidAge(age)) {
                patientAge = age;
                return true;
            } else {
                return false;
            }
    }

    bool setInfectionDate(const string& date) {
            if (isValidDate(date)) {
                infectionDate = date;
                return true;
            } else {
                return false;
            }
    }

    void selectState() {
        int choice;

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

        while (true) {
            if (cin >> choice && choice >= 1 && choice <= 14) {
                const string states[] = {
                    "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
                    "PAHANG", "PERLIS", "PULAU PINANG", "SABAH", "SARAWAK", "SELANGOR",
                    "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
                };
                patientState = states[choice - 1];
                cout << "Current State of Residence changed to: " << patientState << endl;
                return;
            } else {
                cout << "Invalid choice. Please enter a number between 1 and 14." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    void feverLevel() {
        int choice;

        cout << "Choose fever level:" << endl;
        cout << "1. High (>41.5 Celcius)" << endl;
        cout << "2. Medium (<41.5 Celcius)" << endl;
        cout << "3. Low (37.5 Celcius - 38.3 Celcius)" << endl;
        cout << "Enter your choice: ";

        while (true) {
            cin >> choice;

            switch (choice) {
                case 1:
                    fever = "High fever (>41.5 Celcius)";
                    cout << fever << " selected." << endl;
                    return;
                case 2:
                    fever = "Medium fever (<41.5 Celcius)";
                    cout << fever << " selected." << endl;
                    return;
                case 3:
                    fever = "Low fever (37.5 Celcius-38.3 Celcius)";
                    cout << fever << " selected." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            }
        }
    }



};

#endif // PATIENT_REPORT_H
