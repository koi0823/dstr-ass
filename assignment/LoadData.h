#ifndef LOADDATA_H
#define LOADDATA_H

#include "WeeklyData.h"
#include "AnnualData.h"

using namespace std;

class LoadData{

private:
    string weeklyDataFilePath;
    string annualDataFilePath;

public:
    WeeklyDataStack weeklyData;

    void dataload() {

        setWeeklyDataFilePath("/Users/klin/Documents/GitHub/dstr-ass/assignment/Number of dengue fever cases weekly by state.csv");
        setAnnualDataFilePath("/Users/klin/Documents/GitHub/dstr-ass/assignment/Annual number of dengue cases by state.csv");
        
        weeklyData.loadFromCSV(getWeeklyDataFilePath());
        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        weeklyData.display();
        cout << "=======================================================" << endl;

        
        // Load Annual Data
        AnnualDataList* annualDataList = AnnualDataList::getInstance();
        annualDataList->loadFromCSV(getAnnualDataFilePath());
        // Display the loaded data
        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        annualDataList->display();
        cout << "=======================================================" << endl;

    }
    void setWeeklyDataFilePath(const string& path) {
        weeklyDataFilePath = path;
    }

    void setAnnualDataFilePath(const string& path) {
        annualDataFilePath = path;
    }

    const string& getWeeklyDataFilePath() const {
        return weeklyDataFilePath;
    }

    const string& getAnnualDataFilePath() const {
        return annualDataFilePath;
    }
    
        WeeklyDataStack& getWeeklyData() {
        return weeklyData;
    }
};

#endif // LOADDATA_H