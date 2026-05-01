#include "Customer.h"
#include<iostream>
using namespace std;

// Default Constructor
Customer::Customer() : User() {
    cnic = "Unknown";
    fullName = "Unknown";
    gender = "Unknown";
    phoneNumber = "Unknown";
    city = "Unknown";
    isBlocked = false;
}

// Parameterized Constructor
Customer::Customer(string username, string password, string cnic, string fullName, string gender, string phoneNumber, string city) 
    : User(username, password) 
{
    this->cnic = cnic;
    this->fullName = fullName;
    this->gender = gender;
    this->phoneNumber = phoneNumber;
    this->city = city;
    this->isBlocked = false; // New customers are never blocked by default
}

// Getters
string Customer::getCnic() { return cnic; }
string Customer::getFullName() { return fullName; }
string Customer::getGender() { return gender; }
string Customer::getPhoneNumber() { return phoneNumber; }
string Customer::getCity() { return city; }
bool Customer::getIsBlocked() { return isBlocked; }

// Setter
void Customer::setIsBlocked(bool isBlocked) { 
    this->isBlocked = isBlocked; 
}

//virtual function from user.h
void Customer::menu() {
    int choice = 0;
    while (choice != 6) {
        cout << "\n=== Customer Panel ===" << endl;
        cout << "Welcome, " << getFullName() << " (" << getCnic() << ")" << endl;
        cout << "1. Browse Filter Catalog" << endl;
        cout << "2. Load Image" << endl;
        cout << "3. Build Filter Pipeline" << endl;
        cout << "4. Apply Filter & Save Result" << endl;
        cout << "5. View My Session History" << endl;
        cout << "6. Logout" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Opening Filter Catalog..." << endl;
                break;
            case 2:
                loadImage();
                break;
            case 3:
                cout << "Entering Pipeline Builder..." << endl;
                break;
            case 4:
                cout << "Applying filters and saving..." << endl;
                break;
            case 5:
                viewHistory();
                break;
            case 6:
                cout << "Logging out. Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    }
}

void Customer::loadImage() {
    string path;
    cout << "\nEnter path to image file (JPG/PNG): ";
    cin >> path;
    
    // Once the File Managers and FilterSession are fully wired up, 
    // this is where you will instantiate the new Image(path) object.
    cout << "[System] Attempting to load image from: " << path << endl;
}

// Method to read from sessions.txt
void Customer::viewHistory() {
    cout << "\n=== Your Session History ===" << endl;
    
    // Once the Session Manager is built, it will search sessions.txt 
    // for lines starting with this->cnic and print them here.
    cout << "Searching database for CNIC: " << getCnic() << "..." << endl;
    cout << "(Session history will be displayed here)" << endl;
}