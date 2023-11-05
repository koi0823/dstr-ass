#include <iostream>
#include <string>
#include "LoadData.h"

using namespace std;

class DengueCaseViewer {

// WeeklyDataStack myWeeklyData;
public:
    void viewWeeklyCases() {
        int year;
        int week;

        // LoadData loadData;
        // loadData.dataload(); // Load the data
        // system("clear");
        // myWeeklyData = loadData.getWeeklyData(); // Load the weekly data

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
        cout <<" "<<endl;
        system("clear");
        // Determine the number of weeks for the selected year
        int weeksInYear = (year == 3) ? 53 : 52;

        // Prompt the user to select a week
        cout << yearNames[year - 1] << " is chosen" << endl;
        cout << " " <<endl;
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
        cout << "Displaying the amount of cases in the year " << yearNames[year - 1] << ", week " << week << ": " <<endl;//<< /* Add your case data display logic here */ << endl;
        cout << "" <<endl;
    }
};


