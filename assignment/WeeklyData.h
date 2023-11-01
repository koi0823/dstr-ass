#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

struct WeeklyDataNode {
    string state;
    int year, week, numOfDengueCases;
    shared_ptr<WeeklyDataNode> next;
    weak_ptr<WeeklyDataNode> prev;

    WeeklyDataNode(const string& state, int year, int week, int numOfDengueCases)
        : state(state), year(year), week(week), numOfDengueCases(numOfDengueCases), next(nullptr), prev() {}
};

class WeeklyDataList {
public:
    shared_ptr<WeeklyDataNode> head, tail;
    static shared_ptr<WeeklyDataList> instance;

    WeeklyDataList() : head(nullptr), tail(nullptr) {}

    static shared_ptr<WeeklyDataList> getInstance() {
        if (!instance) {
            instance = make_shared<WeeklyDataList>();
        }
        return instance;
    }

    void insert(const string& state, int year, int week, int numOfDengueCases) {
        shared_ptr<WeeklyDataNode> newNode = make_shared<WeeklyDataNode>(state, year, week, numOfDengueCases);
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
                    year = stoi(cell);
                } else if (col_index == 1) {
                    week = stoi(cell);
                } else {
                    numOfDengueCases = stoi(cell);
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

        shared_ptr<WeeklyDataNode> current = head;
        while (current) {
            cout << "State: " << current->state
                 << ", Year: " << current->year
                 << ", Week: " << current->week
                 << ", Number of Dengue Cases: " << current->numOfDengueCases
                 << endl;
            current = current->next;
        }
    }

    WeeklyDataList searchCasesMoreThan(int threshold) const {
        WeeklyDataList result;
        if (!head) return result;

        shared_ptr<WeeklyDataNode> current = head;
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
};

shared_ptr<WeeklyDataList> WeeklyDataList::instance = nullptr;
