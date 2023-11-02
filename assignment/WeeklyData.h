#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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


    void display(WeeklyDataNode* node) const {
        if (!node) return;
        display(node->left);
        cout << "State: " << node->state
             << ", Year: " << node->year
             << ", Week: " << node->week
             << ", Number Dengue Cases: " << node->numOfDengueCases << endl;
        display(node->right);
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

    void display() const {
        if (!root) {
            cout << "The tree is empty." << endl;
        } else {
            display(root);
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
            string state;

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

    ~WeeklyDataBST() {
        clear(root);
    }
};
