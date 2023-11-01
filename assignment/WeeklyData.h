#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct WeeklyDataNode {
    string state;
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

    // Insert
    void insert(const string& state, int year, int week, int numOfDengueCases) {
        WeeklyDataNode* newNode = new WeeklyDataNode{state, year, week, numOfDengueCases, nullptr, nullptr};
        if (tail == nullptr) {
            head = tail = newNode;
            newNode->next = newNode;  // Point to itself to make the list circular
            newNode->prev = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;  // Point to the head to make the list circular
            head->prev = newNode;  // Update the previous of head node
            tail = newNode;
        }
    }

    void loadFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        getline(file, line);  // skip header line

        while (getline(file, line)) {
            istringstream iss(line);
            vector<string> tokens;
            string token;
            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() >= 4) {
                string state = tokens[0];
                int year = stoi(tokens[1]);
                int week = stoi(tokens[2]);
                int numOfDengueCases = stoi(tokens[3]);
                insert(state, year, week, numOfDengueCases);
            }
        }

        file.close();
    }

    // Display (for demonstration)
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        WeeklyDataNode* current = head;
        do {
            cout << "State: " << current->state 
                 << ", Year: " << current->year
                 << ", Week: " << current->week 
                 << ", Dengue Cases: " << current->numOfDengueCases << endl;
            current = current->next;
        } while (current != head);
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
};

// Initializing the static instance
WeeklyDataList* WeeklyDataList::instance = nullptr;

// Basic Binary Search Tree Node Structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class WeeklyDataTree {
public:
    TreeNode* root;

    WeeklyDataTree() : root(nullptr) {}

    // Insert (for demonstration)
    void insert(int data) {
        root = insertRec(root, data);
    }

private:
    TreeNode* insertRec(TreeNode* node, int data) {
        if (node == nullptr) {
            return new TreeNode{data, nullptr, nullptr};
        }
        if (data < node->data) {
            node->left = insertRec(node->left, data);
        } else if (data > node->data) {
            node->right = insertRec(node->right, data);
        }
        return node;
    }
};

#endif // WEEKLYDATA_H
