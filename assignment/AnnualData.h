#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct AnnualDataNode {
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

public:
    static AnnualDataList* getInstance() {
        if (instance == nullptr) {
            instance = new AnnualDataList();
        }
        return instance;
    }

    // Insert
    void insert(const string& state, int year, int numOfDengueCases) {
        AnnualDataNode* newNode = new AnnualDataNode{state, year, numOfDengueCases, nullptr, nullptr};
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

    // Display (for demonstration)
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        AnnualDataNode* current = head;
        do {
            cout << "State: " << current->state << ", Year: " << current->year
                      << ", Dengue Cases: " << current->numOfDengueCases << endl;
            current = current->next;
        } while (current != head);
    }

    void increaseDengueCases(int year, const std::string& age, const std::string& state) {
        AnnualDataNode* current = head;
        while (current != nullptr) {
            if (current->year == year && current->age == age && current->state == state) {
                current->numOfDengueCases++;
                std::cout << "Dengue cases updated successfully. New number of cases: " << current->numOfDengueCases << "\n";
                return;
            }
            current = current->next;
        }

        // If no matching data found, create a new node
        insert(age, state, year, 1);
        std::cout << "No matching data found. A new entry has been created with 1 dengue case.\n";
    }

    // Other functions (e.g., display, search, delete) go here
    int caseBasedOnAgeAndState(const std::string& inputage, const std::string& inputstate) {
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

// Basic Binary Search Tree Node Structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

class AnnualDataTree {
public:
    TreeNode* root;

    AnnualDataTree() : root(nullptr) {}

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

#endif // ANNUALDATA_H
