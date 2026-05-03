#include "Customer.h"
#include <fstream>

//Default Constructor
Customer::Customer() : User("Unknown", "Unassigned") {
    this->fullName = "Unknown";
    this->gender = "Unknown";
    this->phoneNumber = "Unknown";
    this->city = "Unknown";
    this->isBlocked = false;
}

//Getters
string Customer::getFullName() const { return fullName; }
string Customer::getGender() const { return gender; }
string Customer::getPhoneNumber() const { return phoneNumber; }
string Customer::getCity() const { return city; }
bool Customer::getIsBlocked() const { return isBlocked; }

//Setters
void Customer::setIsBlocked(bool isBlocked) { 
    this->isBlocked = isBlocked; 
}

void Customer::menu() {
    int sessionsCompleted = 0;
    
    //Scan sessions.txt to count this user's completed sessions
    ifstream file("sessions.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            bool match = true;
            //Manually check if the start of the line matches this customer's CNIC (ID)
            for (int i = 0; ID[i] != '\0'; i++) {
                if (line[i] != ID[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                sessionsCompleted++;
            }
        }
        file.close();
    }
    cout << endl;
    cout << "╔════════════════════════════════════════════════╗\n";
    cout << "║    Welcome, " << fullName << "                    ║"<< endl;
    cout << "║    Sessions completed: " << sessionsCompleted << "                       ║" << endl;
    cout << "╠════════════════════════════════════════════════╣\n";
    cout << "║    1.  Browse Filter Catalog                   ║\n";
    cout << "║    2.  Load Image                              ║\n";
    cout << "║    3.  Build Filter Pipeline                   ║\n";
    cout << "║    4.  Apply Pipeline & Save Result            ║\n";
    cout << "║    5.  View My Session History                 ║\n";
    cout << "║    6.  Logout                                  ║\n";
    cout << "╚════════════════════════════════════════════════╝\n";
}

void Customer::loadImage() {
    cout << "Load Image function will be handled by the session manager." << endl;
}

void Customer::viewHistory() {
    cout << "\n=== My Session History ===" << endl;
    ifstream file("sessions.txt");
    if (!file.is_open()) {
        cout << "No history found." << endl;
        return;
    }

    string line;
    bool foundAny = false;
    while (getline(file, line)) {
        bool match = true;
        for (int i = 0; ID[i] != '\0'; i++) {
            if (line[i] != ID[i]) {
                match = false;
                break;
            }
        }
        if (match) {
            cout << line << endl;
            foundAny = true;
        }
    }
    file.close();

    if (!foundAny) {
        cout << "You have not completed any sessions yet." << endl;
    }
}