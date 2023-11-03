#include "WeeklyData.h"
#include "AnnualData.h"

using namespace std;

class LoadData{
    
public:
    void dataload() {
        
        WeeklyDataStack weeklyDataTree;
        string file_path1 = "/Users/klin/Documents/GitHub/dstr-ass/assignment/Number of dengue fever cases weekly by state.csv";
        weeklyDataTree.loadFromCSV(file_path1);

        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        weeklyDataTree.display();
        cout << "=======================================================" << endl;

        
        // Load Annual Data
        AnnualDataList* annualDataList = AnnualDataList::getInstance();
        string file_path2 = "/Users/klin/Documents/GitHub/dstr-ass/assignment/Annual number of dengue cases by state.csv";
        annualDataList->loadFromCSV(file_path2);

        // Display the loaded data
        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        annualDataList->display();
        cout << "=======================================================" << endl;

    }

};