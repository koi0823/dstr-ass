#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct AnnualDataNode {
    string age, state;
    int year, numOfDengueCases;
    shared_ptr<AnnualDataNode> next;
    weak_ptr<AnnualDataNode> prev;

    AnnualDataNode(const string& age, const string& state, int year, int numOfDengueCases)
        : age(age), state(state), year(year), numOfDengueCases(numOfDengueCases), next(nullptr), prev() {}
};

class AnnualDataList {
public:
    shared_ptr<AnnualDataNode> head, tail;
    static shared_ptr<AnnualDataList> instance;

    AnnualDataList() : head(nullptr), tail(nullptr) {}

    static shared_ptr<AnnualDataList> getInstance() {
        if (!instance) {
            instance = make_shared<AnnualDataList>();
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
                    year = stoi(cell);
                } else if (col_index == 1) {
                    age = cell;
                } else {
                    numOfDengueCases = stoi(cell);
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
        shared_ptr<AnnualDataNode> newNode = make_shared<AnnualDataNode>(age, state, year, numOfDengueCases);
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

        for (shared_ptr<AnnualDataNode> current = head; current; current = current->next) {
            cout << "Year: " << current->year
                 << ", Age: " << current->age
                 << ", State: " << current->state
                 << ", Number of Dengue Cases: " << current->numOfDengueCases << endl;
        }
    }

    void increaseDengueCases(int year, const string& age, const string& state) {
        for (shared_ptr<AnnualDataNode> current = head; current; current = current->next) {
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
        for (shared_ptr<AnnualDataNode> current = head; current; current = current->next) {
            if (current->age == inputage && current->state == inputstate) {
                totalCases += current->numOfDengueCases;
            }
        }
        return totalCases;
    }

    int getTotalDengueCasesForYear(int year) const {
        int totalCases = 0;
        for (shared_ptr<AnnualDataNode> current = head; current; current = current->next) {
            if (current->year == year) {
                totalCases += current->numOfDengueCases;
            }
        }
        return totalCases;
    }
};

shared_ptr<AnnualDataList> AnnualDataList::instance = nullptr;
