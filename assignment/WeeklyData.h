#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // Added for find

using namespace std;

struct WeeklyDataNode {
    string state;
    int year, week, numOfDengueCases;
    WeeklyDataNode* left;
    WeeklyDataNode* right;

    WeeklyDataNode(const string& state, int year, int week, int numOfDengueCases)
        : state(state), year(year), week(week), numOfDengueCases(numOfDengueCases), left(nullptr), right(nullptr) {}

    string getKey() const {
        return state + to_string(year);
    }
};

class WeeklyDataBST {
private:
    WeeklyDataNode* root;

    void insert(WeeklyDataNode*& node, const string& state, int year, int week, int numOfDengueCases) {
        string key = state + to_string(year);
        if (!node) {
            node = new WeeklyDataNode(state, year, week, numOfDengueCases);
        } else if (key < node->getKey()) {
            insert(node->left, state, year, week, numOfDengueCases);
        } else if (key > node->getKey()) {
            insert(node->right, state, year, week, numOfDengueCases);
        } else {
            // Handle the case where the key is the same. You might want to update the data or handle it differently.
        }
    }

    void collectUniqueYears(WeeklyDataNode* node, vector<int>& years) const {
        if (!node) return;
        collectUniqueYears(node->left, years);
        if (find(years.begin(), years.end(), node->year) == years.end()) {
            years.push_back(node->year);
        }
        collectUniqueYears(node->right, years);
    }

    void displayWeekData(WeeklyDataNode* node, int year, int week) const {
        if (!node) return;

        // Display data for the current node if it belongs to the current year and week
        if (node->year == year && node->week == week) {
            cout << "Week: " << node->week;
            cout << ", State: " << node->state;
            cout << ", Number Dengue Cases: " << node->numOfDengueCases << endl;
        }

        // Recursively display data for left and right subtrees
        displayWeekData(node->left, year, week);
        displayWeekData(node->right, year, week);
    }

    void clear(WeeklyDataNode*& node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
        node = nullptr;
    }

public:
    WeeklyDataBST() : root(nullptr) {}

    void insert(const string& state, int year, int week, int numOfDengueCases) {
        insert(root, state, year, week, numOfDengueCases);
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
        int year_col = -1;
        int week_col = -1;

        while (getline(file, line)) {
            istringstream sline(line);
            string cell;
            int col_index = 0, year, week, numOfDengueCases;
            string state;

            while (getline(sline, cell, ',')) {
                if (row_index == 0) {
                    if (cell == "TAHUN") {
                        year_col = col_index;
                    } else if (cell == "MINGGU EPID") {
                        week_col = col_index;
                    } else if (col_index >= 2) {
                        states.push_back(cell);
                    }
                } else {
                    if (col_index == year_col) {
                        try {
                            year = stoi(cell);
                        } catch (const std::invalid_argument& e) {
                            cerr << "Invalid year: " << cell << endl;
                            year = 0; // Handle the error by setting a default value.
                        }
                    } else if (col_index == week_col) {
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
                }
                col_index++;
            }
            row_index++;
        }
        file.close();
    }

    void displayAllData() const {
        vector<int> years; // Store unique years
        collectUniqueYears(root, years); // Collect unique years in the BST

        for (int year : years) {
            cout << "Year: " << year << endl;
            for (int week = 1; week <= 52; week++) { // Assuming there are 52 weeks in a year
                cout << "Week: " << week << endl;
                displayWeekData(root, year, week); // Display data for the current year and week
                cout << endl;
            }
        }
    }

    ~WeeklyDataBST() {
        clear(root);
    }
};