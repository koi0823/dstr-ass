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

    WeeklyDataNode(const string& state, int year, int week, int numOfDengueCases)
        : state(state), year(year), week(week), numOfDengueCases(numOfDengueCases), next(nullptr) {}
};

class WeeklyDataStack {
public:
    WeeklyDataNode* top;

    WeeklyDataStack() : top(nullptr) {}

    void push(const string& state, int year, int week, int numOfDengueCases) {
        WeeklyDataNode* newNode = new WeeklyDataNode(state, year, week, numOfDengueCases);
        newNode->next = top;
        top = newNode;
    }

    WeeklyDataNode* pop() {
        if (!top) {
            cout << "Stack is empty. Cannot pop." << endl;
            return nullptr;
        }
        WeeklyDataNode* nodeToRemove = top;
        top = top->next;
        nodeToRemove->next = nullptr;  // Disconnect the node from the stack
        return nodeToRemove;  // In a real stack, you would perform a delete operation here.
    }

    WeeklyDataNode* peek() const {
        return top;
    }

    bool empty() const {
        return !top;
    }

    ~WeeklyDataStack() {
        while (top) {
            WeeklyDataNode* temp = pop();
            delete temp;
        }
    }

    void loadFromCSV(const string& file_path) {
        ifstream file(file_path);
        if (!file.is_open()) {
            cerr << "Error opening file: " << file_path << endl;
            return;
        }

        string line;
        vector<string> states;
        int row_index = 0;
        int year, week, numOfDengueCases;

        while (getline(file, line)) {
            if (row_index == 0) { // Process the header row
                // Debug: Print the header row
                cout << "Header row: " << line << endl;

                istringstream sline(line);
                string cell;
                int col_index = 0; // Initialize col_index here

                while (getline(sline, cell, ',')) {
                    if (col_index >= 2) {
                        states.push_back(cell);
                    }
                    col_index++;
                }
            } else { // Process data rows
                // Debug: Print the data rows
                cout << "Data row: " << line << endl;

                istringstream sline(line);
                string cell;
                int col_index = 0;

                while (getline(sline, cell, ',')) {
                    if (col_index == 0) {
                        year = stoi(cell);
                    } else if (col_index == 1) {
                        week = stoi(cell);
                    } else if (col_index >= 2) {
                        numOfDengueCases = stoi(cell);
                        // Here we're using the state name from the header, matched with the index of the current cell.
                        push(states[col_index - 2], year, week, numOfDengueCases);
                    }
                    col_index++;
                }
            }
            row_index++;
        }
        file.close();

        // Debug output
        cout << "Loaded " << row_index << " rows of data." << endl;
    }
    void debugDisplay() const {
        WeeklyDataNode* current = top;
        while (current) {
            cout << "Year: " << current->year << ", Week: " << current->week << ", State: " << current->state << ", Cases: " << current->numOfDengueCases << endl;
            current = current->next;
        }
    }


    void display(int year, int week) const {
        if (!top) {
            cout << "The stack is empty." << endl;
            return;
        }

        // Set the width for each column
        const int stateWidth = 20; // Increased width for state to accommodate longer names
        const int yearWidth = 6;
        const int weekWidth = 6;
        const int casesWidth = 6; // Reduced width for cases since the numbers are small

        // Set the headers
        cout << left << setw(stateWidth) << setfill(' ') << "State"
            << left << setw(yearWidth) << "Year"
            << left << setw(weekWidth) << "Week"
            << left << setw(casesWidth) << "Case" << endl;

        // Draw a line under the headers
        cout << setfill('-') << setw(stateWidth + yearWidth + weekWidth + casesWidth) << "-" << endl;
        cout << setfill(' '); // Reset fill to space for the data rows

        // Use the auxiliary stack to reverse the data
        WeeklyDataStack auxStack;
        WeeklyDataNode* current = top;
        while (current) {
            if (current->year == year && current->week == week) {
                auxStack.push(current->state, current->year, current->week, current->numOfDengueCases);
            }
            current = current->next;
        }

        // Temporary vector to store and reverse the stack elements
        vector<WeeklyDataNode*> tempNodes;

        // Move items from auxStack back to main stack and simultaneously print them
        while (!auxStack.empty()) {
            WeeklyDataNode* node = auxStack.pop();
            tempNodes.push_back(node); // Save node pointers to avoid memory leaks
            cout << left << setw(stateWidth) << node->state
                << left << setw(yearWidth) << node->year
                << left << setw(weekWidth) << node->week
                << left << setw(casesWidth) << node->numOfDengueCases << endl;
        }

        // Cleanup tempNodes to avoid memory leaks
        for (WeeklyDataNode* node : tempNodes) {
            delete node;
        }
    }
};

