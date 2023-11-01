#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct AnnualDataNode {
    string age;
    string state;
    int year;
    int numOfDengueCases;
    AnnualDataNode* next;
    AnnualDataNode* prev;
};

class AnnualDataList {
public:
    AnnualDataNode* head;
    AnnualDataNode* tail;

    static AnnualDataList* instance;

    AnnualDataList() : head(nullptr), tail(nullptr) {}

    static AnnualDataList* getInstance(){
        if(instance == nullptr){
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
            string age, year;
            int numOfDengueCases;

            while (getline(sline, cell, ',')) {
                if (row_index == 0) {
                    if (col_index >= 2) {
                        states.push_back(cell);
                    }
                } else {
                    if (col_index == 0) {
                        year = cell;
                    } else if (col_index == 1) {
                        age = cell;
                    } else {
                        numOfDengueCases = stoi(cell);
                        string state = states[col_index - 2];
                        insert(age, state, stoi(year), numOfDengueCases);
                    }
                }
                col_index++;
            }
            row_index++;
        }
        file.close();
    }

    // Function to insert a new node
    void insert(const string& age, const string& state, int year, int numOfDengueCases) {
        // Create a new node
        AnnualDataNode* newNode = new AnnualDataNode;
        newNode->age = age;
        newNode->state = state;
        newNode->year = year;
        newNode->numOfDengueCases = numOfDengueCases;
        newNode->next = nullptr; // New node will be the last node, so next is null
        newNode->prev = tail;    // Previous node is the current tail

        // If the list is empty, make the new node both head and tail
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, add the new node to the end of the list and update the tail
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        AnnualDataNode* current = head;
        while (current != nullptr) {
            cout << "Year: " << current->year
                 << ", Age: " << current->age
                 << ", State: " << current->state
                 << ", Number of Dengue Cases: " << current->numOfDengueCases << endl;
            current = current->next;
        }
    }

    void increaseDengueCases(int year, const string& age, const string& state) {
        AnnualDataNode* current = head;
        while (current != nullptr) {
            if (current->year == year && current->age == age && current->state == state) {
                current->numOfDengueCases++;
                cout << "Dengue cases updated successfully. New number of cases: " << current->numOfDengueCases << "\n";
                return;
            }
            current = current->next;
        }

        // If no matching data found, create a new node
        insert(age, state, year, 1);
        cout << "No matching data found. A new entry has been created with 1 dengue case.\n";
    }

    // Other functions (e.g., display, search, delete) go here
    int caseBasedOnAgeAndState(const string& inputage, const string& inputstate) {
        int totalCases = 0;
        AnnualDataNode* current = head;
        while (current != nullptr) {
            totalCases += current->numOfDengueCases;
            current = current->next;
        }
        return totalCases;
    }

    int getTotalDengueCasesForYear(int year) {
        int totalCases = 0;
        AnnualDataNode* current = head;
        while (current != nullptr) {
            if (current->year == year) {
                totalCases += current->numOfDengueCases;
            }
            current = current->next;
        }
        return totalCases;
    }

};

// Initializing the static instance
AnnualDataList* AnnualDataList::instance = nullptr;