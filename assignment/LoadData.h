#include "WeeklyData.h"
#include "AnnualData.h"

using namespace std;

class LoadData{
    
public:
    void dataload() {
        
        WeeklyDataBST weeklyDataTree;
        string file_path1 = "/Users/klin/Documents/GitHub/dstr-ass/assignment/Number of dengue fever cases weekly by state.csv";
        weeklyDataTree.loadFromCSV(file_path1);

        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        weeklyDataTree.displayAllData();
        cout << "=======================================================" << endl;



        // int weekToDisplay = 2; // Change this to the week you want to display

        // // Iterate over the years and display data for the specified week
        // vector<int> years;
        // weeklyData.collectUniqueYears(weeklyData.getRoot(), years); // Collect unique years in the BST

        // for (int year : years) {
        //     cout << "Year: " << year << endl;
        //     cout << "Week: " << weekToDisplay << endl;
        //     weeklyData.displayWeekData(year, weekToDisplay);
        //     cout << endl;
        // }
        
        // // Load Annual Data
        // AnnualDataList* annualDataList = AnnualDataList::getInstance();
        // string file_path2 = "/Users/klin/Documents/GitHub/dstr-ass/assignment/Annual number of dengue cases by state.csv";
        // annualDataList->loadFromCSV(file_path2);

        // // Display the loaded data
        // cout << "=======================================================" << endl;
        // cout << "                   Data Loaded           " << endl;
        // cout << "=======================================================" << endl;
        // annualDataList->display();
        // cout << "=======================================================" << endl;

    }

};