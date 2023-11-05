#include<iostream>
#include "patientReport.h" // Include the patient report header file

class FindDenguebyName {
public:
    // Function to find dengue fever cases based on patient name
    static void findDenguesOfCases(const string& patientName, const vector<PatientReport>& cases) {
        bool found = false;
        for (const PatientReport& report : cases) {
            if (report.getPatientName() == patientName) {
                report.reportPatient(); // Display the patient's information
                found = true;
            }
        }

        if (!found) {
            cout << "No dengue fever cases found for patient: " << patientName << endl;
        }
    }
};

