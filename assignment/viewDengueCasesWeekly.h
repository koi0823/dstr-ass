#include <iostream>
#include <iomanip> // Include for setw and setfill
#include <string>
#include "LoadData.h"

using namespace std;

class DengueCaseViewer {
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
        system("clear");

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
        system("clear");

        // Display the data for the selected year and week
        displayWeeklyDataForYearAndWeek(selectedYear, week);
    }

    void displayWeeklyDataForYearAndWeek(int year, int week) {
        bool found = false;

        // Temporary stack to reverse the order of filtered data
        WeeklyDataStack reverseStack;

        // Iterate through the stack to find and push the data for the selected year and week onto the reverse stack
        WeeklyDataNode* current = myWeeklyData.top;
        while (current != nullptr) {
            if (current->year == year && current->week == week) {
                reverseStack.push(current->state, current->year, current->week, current->numOfDengueCases);
                found = true;
            }
            current = current->next;
        }
        cout << "=========================================" << endl;
        cout << "  view all Dengue cases by "<< year << ", week " << week << endl;
        cout << "=========================================" << endl;
        // Now pop from the reverse stack to display the data in reverse order
        while (!reverseStack.empty()) {
            WeeklyDataNode* node = reverseStack.pop();
            cout << "State: " << node->state << ", Cases: " << node->numOfDengueCases << endl;
            // Here you should handle the node memory if you're not using it elsewhere
        }
        cout << ""<< endl;
        if (!found) {
            cout << "No data found for year " << year << " and week " << week << "." << endl;
        }
    }

    

};
