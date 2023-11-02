#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct WeeklyDataNode {
    string state;
    int year, week, numOfDengueCases;
    WeeklyDataNode* next;
    WeeklyDataNode* prev;

    WeeklyDataNode(const string& state, int year, int week, int numOfDengueCases)
        : state(state), year(year), week(week), numOfDengueCases(numOfDengueCases), next(nullptr), prev(nullptr) {}
};

class WeeklyDataList {
public:
    WeeklyDataNode* head;
    WeeklyDataNode* tail;
    static WeeklyDataList* instance;

    WeeklyDataList() : head(nullptr), tail(nullptr) {}

    static WeeklyDataList* getInstance() {
        if (!instance) {
            instance = new WeeklyDataList();
        }
        return instance;
    }

    void insert(const string& state, int year, int week, int numOfDengueCases) {
        WeeklyDataNode* newNode = new WeeklyDataNode(state, year, week, numOfDengueCases);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void loadFromCSV(const string& file_path) {
        ifstream file(file_path);
        if (!file.is_open()) {
            cerr << "Error opening file" << endl;
            return;
        }

        string line;
        vector<string> states;
        int row_index = 0;

        while (getline(file, line)) {
            istringstream sline(line);
            string cell;
            int col_index = 0, year, week, numOfDengueCases;

            while (getline(sline, cell, ',')) {
                if (row_index == 0 && col_index >= 2) {
                    states.push_back(cell);
                } else if (col_index == 0) {
                    try {
                        year = stoi(cell);
                    } catch (const std::invalid_argument& e) {
                        cerr << "Invalid year: " << cell << endl;
                        year = 0; // Handle the error by setting a default value.
                    }
                } else if (col_index == 1) {
                    try {
                        week = stoi(cell);
                        
                    } catch (const std::invalid_argument& e) {
                        cerr << "Invalid week: " << cell << endl;
                        week = 0; // Handle the error by setting a default value.
                    }
                } else {
                    try {
                        numOfDengueCases = stoi(cell);
                    } catch (const std::invalid_argument& e) {
                        cerr << "Invalid number of dengue cases: " << cell << endl;
                        numOfDengueCases = 0; // Handle the error by setting a default value.
                    }
                    insert(states[col_index - 2], year, week, numOfDengueCases);
                }
                col_index++;
            }
            row_index++;
        }
        file.close();
    }

void display() const {
    if (!head) {
        cout << "The list is empty." << endl;
        return;
    }

    WeeklyDataNode* current = head;
    while (current) {
        cout << "State: " << current->state
             << ", Year: " << current->year
             << ", Week: " << current->week
             << ", Number Dengue Cases: " << current->numOfDengueCases;

        // Check if the "Number Dengue Cases" value contains a line break character
        if (current->numOfDengueCases >= 10) {
            cout << "\n";
        } else {
            cout << endl;
        }

        current = current->next;
    }
}


    WeeklyDataList searchCasesMoreThan(int threshold) const {
        WeeklyDataList result;
        if (!head) return result;

        WeeklyDataNode* current = head;
        while (current) {
            if (current->numOfDengueCases > threshold) {
                result.insert(current->state, current->year, current->week, current->numOfDengueCases);
            }
            current = current->next;
        }
        return result;
    }

    bool empty() const {
        return !head;
    }

    ~WeeklyDataList() {
        while (head) {
            WeeklyDataNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

WeeklyDataList* WeeklyDataList::instance = nullptr;