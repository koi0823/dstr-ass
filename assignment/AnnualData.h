#ifndef ANNUALDATA_H
#define ANNUALDATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct AnnualDataNode {
    string age, state;
    int year, numOfDengueCases;
    AnnualDataNode* next;
    AnnualDataNode* prev;

    AnnualDataNode(const string& age, const string& state, int year, int numOfDengueCases)
        : age(age), state(state), year(year), numOfDengueCases(numOfDengueCases), next(nullptr), prev(nullptr) {}
};

class AnnualDataList {
public:
    AnnualDataNode* head;
    AnnualDataNode* tail;
    static AnnualDataList* instance;

    AnnualDataList() : head(nullptr), tail(nullptr) {}

    static AnnualDataList* getInstance() {
        if (!instance) {
            instance = new AnnualDataList();
        }
        return instance;
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
        int col_index = 0;
        string age, state;
        int year, numOfDengueCases;

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
                age = cell;
            } else {
                try {
                    numOfDengueCases = stoi(cell);
                } catch (const std::invalid_argument& e) {
                    cerr << "Invalid number of dengue cases: " << cell << endl;
                    numOfDengueCases = 0; // Handle the error by setting a default value.
                }
                state = states[col_index - 2];
                insert(age, state, year, numOfDengueCases);
            }
            col_index++;
        }
        row_index++;
    }
    file.close();
}


    void insert(const string& age, const string& state, int year, int numOfDengueCases) {
        AnnualDataNode* newNode = new AnnualDataNode(age, state, year, numOfDengueCases);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() const {
        if (!head) {
            cout << "The list is empty." << endl;
            return;
        }

        for (AnnualDataNode* current = head; current; current = current->next) {
            cout << "Year: " << current->year
                << ", Age: " << current->age
                << ", State: " << current->state
                << ", annual Dengue Cases: " << current->numOfDengueCases;

            // Check if the "annual Dengue Cases" contains a line break character
            if (current->numOfDengueCases >= 10) {
                cout << "\n";
            } else {
                cout << endl;
            }
        }
    }


    void increaseDengueCases(int year, const string& age, const string& state) {
        for (AnnualDataNode* current = head; current; current = current->next) {
            if (current->year == year && current->age == age && current->state == state) {
                current->numOfDengueCases++;
                cout << "Dengue cases updated successfully. New number of cases: " << current->numOfDengueCases << "\n";
                return;
            }
        }

        // If no matching data found, create a new node
        insert(age, state, year, 1);
        cout << "No matching data found. A new entry has been created with 1 dengue case.\n";
    }

    int caseBasedOnAgeAndState(const string& inputage, const string& inputstate) const {
        int totalCases = 0;
        for (AnnualDataNode* current = head; current; current = current->next) {
            if (current->age == inputage && current->state == inputstate) {
                totalCases += current->numOfDengueCases;
            }
        }
        return totalCases;
    }

    int getTotalDengueCasesForYear(int year) const {
        int totalCases = 0;
        for (AnnualDataNode* current = head; current; current = current->next) {
            if (current->year == year) {
                totalCases += current->numOfDengueCases;
            }
        }
        return totalCases;
    }
};

AnnualDataList* AnnualDataList::instance = nullptr;

#endif // ANNUALDATA_H