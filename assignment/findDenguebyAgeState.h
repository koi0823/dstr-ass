#include <iostream>
#include <vector>
#include "LoadData.h"

using namespace std;

class FindDenguebyAgeState {
public:
    static void findDengueCasesByAgeAndState() {
        int ageOption;
        int stateOption;
        int yearIndex; // Declare yearIndex variable
        string yearNames[] = {"2018", "2019", "2020", "2021"};

        // Prompt the user to select a year
        cout << "Enter the year:" << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << yearNames[i] << endl;
        }

        do {
            cout << "Year choice (1-4): ";
            cin >> yearIndex;

            if (yearIndex < 1 || yearIndex > 4) {
                cout << "Invalid input. Please choose a valid year (1-4)." << endl;
            }
        } while (yearIndex < 1 || yearIndex > 4);

        // Convert the selected year to an integer
        int selectedYear = stoi(yearNames[yearIndex - 1]);

        system("clear");
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

        int numberOfCases = countCasesByAgeAndState(selectedYear, ageRange, stateRange); // Pass the selected year

        cout << "Selected Year: " << selectedYear << endl;
        cout << "Selected Age Range: " << ageRange << endl;
        cout << "Selected State Range: " << stateRange << endl;        
        cout << "Number of cases: " << numberOfCases << endl;
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

    static int countCasesByAgeAndState(int selectedYear, const string& ageRange, const string& stateRange) {
            // Access data from LoadData class and filter by selectedYear, ageRange, and stateRange
            LoadData loadData;
            loadData.dataload();
            AnnualDataList& annualDataList = loadData.getAnnualData();

            system("clear");

            int count = 0;

            for (const AnnualDataNode* current = annualDataList.head; current; current = current->next) {
                if (current->year == selectedYear && current->age == ageRange && current->state == stateRange) {
                    count += current->numOfDengueCases;
                }
            }

            return count;
        }
};
