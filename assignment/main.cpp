#include <iostream>
#include <string>
#include <algorithm> // for std::swap
#include <limits>    // for numeric_limits

using namespace std;

// Define a struct to store dengue patient information
struct DenguePatient {
    string name;
    int age;
    string address;
    int severity;
};

// Define a node for the doubly circular linked list
struct Node {
    DenguePatient data;
    Node* next;
    Node* prev;
};

// Global variables
Node* denguePatientsList = nullptr;
int numPatients = 0;

// Function to insert a new patient into the doubly circular linked list
void insertPatient(DenguePatient patient) {
    Node* newNode = new Node;
    newNode->data = patient;

    if (denguePatientsList == nullptr) {
        newNode->next = newNode->prev = newNode;
        denguePatientsList = newNode;
    } else {
        newNode->next = denguePatientsList;
        newNode->prev = denguePatientsList->prev;
        denguePatientsList->prev->next = newNode;
        denguePatientsList->prev = newNode;
    }

    numPatients++;
}

// Function to perform a linear search for a patient by name
int linearSearch(const string& name) {
    Node* current = denguePatientsList;
    int index = 0;

    if (current == nullptr) {
        return -1; // List is empty
    }

    do {
        if (current->data.name == name) {
            return index;
        }
        current = current->next;
        index++;
    } while (current != denguePatientsList);

    return -1; // Patient not found
}

// Function to partition the array for quick sort
int partition(DenguePatient arr[], int low, int high) {
    DenguePatient pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].severity < pivot.severity) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Function to perform quick sort
void quickSort(DenguePatient arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display patient information
void displayPatient(const DenguePatient& patient) {
    cout << "Name: " << patient.name << endl;
    cout << "Age: " << patient.age << endl;
    cout << "Address: " << patient.address << endl;
    cout << "Severity: " << patient.severity << endl;
    cout << "-------------------" << endl;
}

int main() {
    int choice;

    do {
        cout << "=================================" << endl;
        cout << "             Home Page           " << endl;
        cout << "=================================" << endl;
        cout << "1. User" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. MOH admin" << endl;
        cout << "0. Exit Program" << endl;
        cout << "Please select your choice: ";

        // Ensure the input is valid (an integer)
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid choice (0, 1, 2, 3): "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice < 0 || choice > 3) {
            cout << "Invalid choice. Please enter a valid choice (0, 1, 2, 3): "<<endl;
        } else {
            switch (choice) {
                case 1:
                    // User menu
                    // Implement user-related functionality here
                    break;
                case 2:
                    // Doctor menu
                    // Implement doctor-related functionality here
                    break;
                case 3:
                    // MOH admin menu
                    // Implement MOH admin-related functionality here
                    break;
                case 0:
                    cout << "Exiting program..." << endl;
                    break;
            }
        }
    } while (choice != 0);

    // Free memory allocated for the linked list (optional, as the program will exit)
    while (denguePatientsList != nullptr) {
        Node* temp = denguePatientsList;
        denguePatientsList = denguePatientsList->next;
        delete temp;
    }

    return 0;
}
