#include "WeeklyData.h"
#include "AnnualData.h"


class LoadData{
private:
    UserList* userList = UserList::getInstance();
    
public:
    void dataload() {
        
        // Load Weekly Data
        WeeklyDataList* weeklyDataList = WeeklyDataList::getInstance();
        std::string file_path1 = "/Users/klin/Downloads/Data Structure/Number of dengue fever cases weekly by state.csv";
        weeklyDataList->loadFromCSV(file_path1);
        
        // Load Annual Data
        AnnualDataList* annualDataList = AnnualDataList::getInstance();
        std::string file_path2 = "/Users/klin/Downloads/Data Structure/Annual number of dengue cases by state.csv";
        annualDataList->loadFromCSV(file_path2);

    }

};