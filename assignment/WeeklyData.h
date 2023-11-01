
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct WeeklyDataNode {
    std::string state;
    int year;
    int week;
    int numOfDengueCases;
    WeeklyDataNode* next;
    WeeklyDataNode* prev;
};

class WeeklyDataList {
public:
    WeeklyDataNode* head;
    WeeklyDataNode* tail;

    static WeeklyDataList* instance;

    WeeklyDataList() : head(nullptr), tail(nullptr) {}

public:
    static WeeklyDataList* getInstance() {
        if (instance == nullptr) {
            instance = new WeeklyDataList();
        }
        return instance;
    }

    //Insert
    void insert(const std::string& state, int year, int week, int numOfDengueCases) {
        // Create a new node
        WeeklyDataNode* newNode = new WeeklyDataNode;
        newNode->state = state;
        newNode->year = year;
        newNode->week = week;
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

    //Load Data to WeeklyDataList
    void loadFromCSV(const std::string& file_path) {
        std::ifstream file(file_path);
        if (!file.is_open()) {
            std::cerr << "Error opening file" << std::endl;
            return;
        }

        std::string line;
        std::vector<std::string> states;

        int row_index = 0;
        while (std::getline(file, line)) {
            std::istringstream sline(line);
            std::string cell;
            int col_index = 0;
            int year, week, numOfDengueCases;

            while (std::getline(sline, cell, ',')) {
                if (row_index == 0) {
                    if (col_index >= 2) {
                        states.push_back(cell);
                    }
                }else {
                    if (col_index == 0) {
                        year = std::stoi(cell);
                    } else if (col_index == 1) {
                        week = std::stoi(cell);
                    } else {
                        numOfDengueCases = std::stoi(cell);
                        std::string state = states[col_index - 2];
                        insert(state, year, week, numOfDengueCases);
                    }
                }
                col_index++;
            }
            row_index++;
        }

        file.close();
    }

    void display() {
        if (head == nullptr) {
            std::cout << "The list is empty." << std::endl;
            return;
        }

        WeeklyDataNode* current = head;
        while (current != nullptr) {
            std::cout << "State: " << current->state
                      << ", Year: " << current->year
                      << ", Week: " << current->week
                      << ", Number of Dengue Cases: " << current->numOfDengueCases
                      << std::endl;
            current = current->next;
        }
    }

    WeeklyDataList searchCasesMoreThan(int threshold) {
        WeeklyDataList result;

        WeeklyDataNode* current = head;
        while (current != nullptr) {
            if (current->numOfDengueCases > threshold) {
                result.insert(current->state, current->year, current->week , current->numOfDengueCases);
            }
            current = current->next;
        }

        return result;
    }

    bool empty(){
        if (head == nullptr){
            return true;
        }else{
            return false;
        }
    }
    // ... other functions
};

// Initializing the static instance
WeeklyDataList* WeeklyDataList::instance = nullptr;