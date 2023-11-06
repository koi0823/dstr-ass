#ifndef LOADDATA_H
#define LOADDATA_H

#include "WeeklyData.h"
#include "AnnualData.h"

using namespace std;

class LoadData {

private:
    string weeklyDataFilePath;
    string annualDataFilePath;
    AnnualDataList annualDataListNoPtr; // Add an instance without a pointer

public:
    WeeklyDataStack weeklyData;
    AnnualDataList annualDataList;

    void dataload() {
        setWeeklyDataFilePath("/Users/klin/Documents/GitHub/dstr-ass/assignment/Number of dengue fever cases weekly by state.csv");
        setAnnualDataFilePath("/Users/klin/Documents/GitHub/dstr-ass/assignment/Annual number of dengue cases by state.csv");

        weeklyData.loadFromCSV(getWeeklyDataFilePath());
        cout << "=======================================================" << endl;
        cout << "                   Data Loaded           " << endl;
        cout << "=======================================================" << endl;
        weeklyData.display();
        cout << "=======================================================" << endl;

        // Load Annual Data into both annualDataList and annualDataListNoPtr
        AnnualDataList* annualDataList = AnnualDataList::getInstance();
        annualDataList->loadFromCSV(getAnnualDataFilePath());
        annualDataListNoPtr.loadFromCSV(getAnnualDataFilePath());

        // Display the loaded data
        cout << "=======================================================" << endl;
        cout << "                   Data Loaded (Using Pointer)          " << endl;
        cout << "=======================================================" << endl;
        annualDataList->display();

        cout << "=======================================================" << endl;
        cout << "                   Data Loaded (Without Pointer)       " << endl;
        cout << "=======================================================" << endl;
        annualDataListNoPtr.display();
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

    AnnualDataList& getAnnualData() {
        return annualDataList;
    }

    void setAnnualDataListNoPtr(const AnnualDataList& data) {
        annualDataListNoPtr = data;
    }

    AnnualDataList& getAnnualDataListNoPtr() {
        return annualDataListNoPtr;
    }
};

#endif // LOADDATA_H
