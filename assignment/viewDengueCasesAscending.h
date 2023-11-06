#include <iostream>
#include <iomanip> // Include for setw and setfill
#include <string>
#include <algorithm> // Include for sorting
#include "LoadData.h"

using namespace std;

class DengueViewer {
    WeeklyDataStack myWeeklyData;

public:
    void viewWeeklyCases() {
        int yearIndex;
        int week;

        LoadData loadData;

        // Load the data if it hasn't been loaded yet
        if (myWeeklyData.empty()) {
            loadData.dataload(); // Load the data
            myWeeklyData = loadData.getWeeklyData();
        }
        system("cls");

        // Array of year names
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

        // Convert the year choice to an actual year
        int selectedYear = stoi(yearNames[yearIndex - 1]);

        // Determine the number of weeks for the selected year
        int weeksInYear = (yearIndex == 3) ? 53 : 52;

        // Prompt the user to select a week
        cout << yearNames[yearIndex - 1] << " is chosen" << endl;
        cout << "Enter the week:" << endl;
        for (int i = 1; i <= weeksInYear; i++) {
            cout << i << ". Week " << i << endl;
        }

        do {
            cout << "Week choice: ";
            cin >> week;

            if (week < 1 || week > weeksInYear) {
                cout << "Invalid input. Please choose a valid week (1-" << weeksInYear << ")." << endl;
            }
        } while (week < 1 || week > weeksInYear);
        system("cls");

        // Display the data for the selected year and week
        displayWeeklyDataForYearAndWeek(selectedYear, week);
    }

    void displayWeeklyDataForYearAndWeek(int year, int week) {
        // Create a vector to store data for the selected year and week
        vector<WeeklyDataNode*> selectedData;

        // Assuming myWeeklyData is a custom structure with an iterable 'top' pointer
        WeeklyDataNode* current = myWeeklyData.top;
        while (current != nullptr) {
            if (current->year == year && current->week == week) {
                selectedData.push_back(current);
            }
            current = current->next; // Assume that 'next' is the way to get to the next item
        }

        // Check if data was found
        if (selectedData.empty()) {
            cout << "No data found for year " << year << " and week " << week << "." << endl;
            return;
        }


        cout << "=========================================" << endl;
        cout << "  View all Dengue cases by " << year << ", week " << week << " (Sorted by Cases)" << endl;
        cout << "=========================================" << endl;

        for (const WeeklyDataNode* node : selectedData) {
            cout << "State: " << node->state << ", Cases: " << node->numOfDengueCases << endl;
        }
        cout << endl; // It's more standard to use 'endl' here for a new line
    }

};

