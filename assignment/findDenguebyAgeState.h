#include <iostream>
#include <vector>
#include "patientReport.h"

using namespace std;

class FindDenguebyAgeState {
public:
    static void findDengueCasesByAgeAndState(const vector<PatientReport>& cases) {
        int ageOption;
        int stateOption;

        // Display age range options
        cout << "Input the age range:" << endl;
        displayAgeOptions();

        // Get the user's age range option
        ageOption = getUserOption(1, 16);

        // Display state options
        cout << "Input the state range:" << endl;
        displayStateOptions();


        // Get the user's state range option
        stateOption = getUserOption(1, 14);

        // Find and display the number of cases
        string ageRange = getAgeRange(ageOption);
        string stateRange = getStateRange(stateOption);

        int numberOfCases = countCasesByAgeAndState(cases, ageRange, stateRange);

        cout << "Displaying the number of cases in the age of " << ageRange << " and in " << stateRange << ": " << numberOfCases << "." << endl;
    }

private:
    static void displayAgeOptions() {
        const string ageRanges[] = {
            "0-4", "5-9", "10-14", "15-19", "20-24",
            "25-29", "30-34", "35-39", "40-44", "45-49",
            "50-54", "55-59", "60-64", "65-69", "70-74", ">75"
        };

        for (int i = 0; i < 16; i++) {
            cout << i + 1 << ". " << ageRanges[i] << endl;
        }
    }

    static void displayStateOptions() {
        const string stateRanges[] = {
            "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
            "PAHANG", "PERLIS", "PULAU PINANG", "SABAH", "SARAWAK",
            "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
        };

        for (int i = 0; i < 14; i++) {
            cout << i + 1 << ". " << stateRanges[i] << endl;
        }
    }

    static int getUserOption(int min, int max) {
        int option;
        bool isValidOption = false;

        while (!isValidOption) {
            cout << "Enter your choice: ";
            cin >> option;

            if (cin.fail() || option < min || option > max) {
                cout << "Invalid choice. Please enter a number between " << min << " and " << max << "." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                isValidOption = true;
            }
        }

        system("clear"); // Clear the screen once more before returning the valid option
        return option;
    }

    static string getAgeRange(int ageOption) {
        const string ageRanges[] = {
            "0-4", "5-9", "10-14", "15-19", "20-24",
            "25-29", "30-34", "35-39", "40-44", "45-49",
            "50-54", "55-59", "60-64", "65-69", "70-74", ">75"
        };

        return ageRanges[ageOption - 1];
    }

    static string getStateRange(int stateOption) {
        const string stateRanges[] = {
            "JOHOR", "KEDAH", "KELANTAN", "MELAKA", "NEGERI SEMBILAN",
            "PAHANG", "PERLIS", "PULAU PINANG", "SABAH", "SARAWAK",
            "SELANGOR", "TERENGGANU", "WP KUALA LUMPUR", "WP LABUAN"
        };

        return stateRanges[stateOption - 1];
    }

    static int countCasesByAgeAndState(const vector<PatientReport>& cases, const string& ageRange, const string& stateRange) {
        int count = 0;

        for (const PatientReport& report : cases) {
            if (report.getPatientAge() == ageRange && report.getPatientState() == stateRange) {
                count++;
            }
        }

        return count;
    }
};


