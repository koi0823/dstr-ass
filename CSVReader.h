#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <sstream>
#include <vector>
#include "DoublyCircularLinkedList.h"
#include "DynamicArray.h"
#include "Case.h"

namespace CSVReader {

    std::vector<std::string> parseCSVLine(const std::string& line) {
        std::vector<std::string> result;
        std::string value;
        bool inQuotes = false;

        for (char c : line) {
            if (c == '\"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                result.push_back(value);
                value.clear();
            } else {
                value.push_back(c);
            }
        }
        result.push_back(value);  // Add the last value

        return result;
    }

    template <typename CaseType>
    void readCSV(const std::string& filename, DoublyCircularLinkedList<CaseType>& content) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Failed to open the file: " << filename << std::endl;
            return;
        }

        std::string line;
        std::getline(file, line); // Skip the header line

        while (std::getline(file, line)) {
            std::vector<std::string> attributes = parseCSVLine(line);
            CaseType caseEntry(attributes);
            content.insertAtEnd(caseEntry);
        }

        file.close();
    }
};

