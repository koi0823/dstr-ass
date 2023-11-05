#include <iostream>
#include <string>
#include "LoadData.h"

using namespace std;

class DengueCaseViewer {

WeeklyDataStack myWeeklyData;

public:

void viewWeeklyCases() {
    int year;
    int week;

    LoadData loadData;
    loadData.dataload(); // Load the data
    system("clear");

    // Array of year names
    string yearNames[] = {"2018", "2019", "2020", "2021"};

    // Prompt the user to select a year
    cout << "Enter the year:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << yearNames[i] << endl;
    }

    do {
        cout << "Year choice: ";
        cin >> year;

        if (year < 1 || year > 4) {
            cout << "Invalid input. Please choose a valid year (1-4)." << endl;
        }
    } while (year < 1 || year > 4);
    cout << " " << endl;
    system("clear");

    // Determine the number of weeks for the selected year
    int weeksInYear = (year == 3) ? 53 : 52;

    // Prompt the user to select a week
    cout << yearNames[year - 1] << " is chosen" << endl;
    cout << " " << endl;
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

    // Display the selected year and week
    system("clear");
    cout << "Displaying the amount of cases in the year " << yearNames[year - 1] << ", week " << week << ":" << endl;

    // Create a copy of myWeeklyData to maintain the original stack
    // Create a copy of myWeeklyData to maintain the original stack
    WeeklyDataStack tempStack = myWeeklyData;

    // Filter and display data for the selected year and week
    bool found = false; // To check if any data was found
    while (!tempStack.empty()) {
        WeeklyDataNode* weeklyRecord = tempStack.pop();
        if (weeklyRecord->year == year && weeklyRecord->week == week) {
            // Display the data for this record
            cout << "Week " << weeklyRecord->week << " (" << weeklyRecord->year << "): " << weeklyRecord->numOfDengueCases << " cases" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No data found for the selected year and week." << endl;
    }

}


};


