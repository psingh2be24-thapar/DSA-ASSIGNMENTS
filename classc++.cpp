#include <iostream>
using namespace std;

class Student {
private:
    // Private Data Members
    char name[50];
    int rollNo;
    char degree[30];
    char hostel[30];
    float currentCGPA;

    // Private Helper Function to input data
    void inputDetails() {
        cout << "Enter Name (no spaces): ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Degree (no spaces): ";
        cin >> degree;
        cout << "Enter Hostel (no spaces): ";
        cin >> hostel;
        cout << "Enter Current CGPA: ";
        cin >> currentCGPA;
    }

public:
    // Public Function to add initial details
    void addDetails() {
        cout << "\n--- Adding Student Details ---\n";
        inputDetails();  // Call private function
    }

    // Public function to update entire details
    void updateDetails() {
        cout << "\n--- Updating All Student Details ---\n";
        inputDetails();  // Call private function
    }

    // Public function to update CGPA
    void updateCGPA() {
        cout << "Enter New CGPA: ";
        cin >> currentCGPA;
    }

    // Public function to update Hostel
    void updateHostel() {
        cout << "Enter New Hostel (no spaces): ";
        cin >> hostel;
    }

    // Public function to display student details
    void displayDetails() {
        cout << "\n--- Student Details ---\n";
        cout << "Name        : " << name << endl;
        cout << "Roll No     : " << rollNo << endl;
        cout << "Degree      : " << degree << endl;
        cout << "Hostel      : " << hostel << endl;
        cout << "Current CGPA: " << currentCGPA << endl;
    }
};

// Main function
int main() {
    Student s;

    s.addDetails();
    s.displayDetails();

    s.updateCGPA();
    s.updateHostel();

    s.displayDetails();

    return 0;
}
