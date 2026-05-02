#include "CustomerManager.h"

bool CustomerManager::isValidCNIC(string cnic) {
    int count = 0;
    for (int i = 0; cnic[i] != '\0'; i++) {
        count++;
        if (cnic[i] < '0' || cnic[i] > '9') {
            return false; 
        }
    }
    return count == 13;
}

bool CustomerManager::isCNICUnique(string cnic) {
    ifstream file("customers.txt");
    if (!file.is_open()) return true; // If file doesn't exist yet, the CNIC is unique

    string line;
    while (getline(file, line)) {
        string fileCnic = "";
        
        // Extract the CNIC manually by reading up to the first '|' character
        for (int i = 0; line[i] != '|' && line[i] != '\0'; i++) {
            fileCnic += line[i];
        }
        
        if (fileCnic == cnic) {
            file.close();
            return false; 
        }
    }
    file.close();
    return true;
}

bool CustomerManager::isCNICBlocked(string cnic) {
    ifstream file("blocked_cnics.txt");
    if (!file.is_open()) return false; 

    string line;
    while (getline(file, line)) {
        if (line == cnic) {
            file.close();
            return true; // Found in the blocked list
        }
    }
    file.close();
    return false;
}

bool CustomerManager::isValidPassword(string password) {
    int count = 0;
    bool hasUpper = false;
    bool hasDigit = false;

    for (int i = 0; password[i] != '\0'; i++) {
        count++;
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = true;
        if (password[i] >= '0' && password[i] <= '9') hasDigit = true;
    }
    return (count == 9 && hasUpper && hasDigit);
}

bool CustomerManager::registerCustomer(string cnic, string password, string fullName, string gender, string phone, string city) {
    if (!isValidCNIC(cnic)) {
        cout << "Error: CNIC must be exactly 13 numeric digits." << endl;
        return false;
    }
    if (isCNICBlocked(cnic)) {
        cout << "Error: Registration denied. This CNIC is blocked." << endl;
        return false;
    }
    if (!isCNICUnique(cnic)) {
        cout << "Error: This CNIC is already registered." << endl;
        return false;
    }
    if (!isValidPassword(password)) {
        cout << "Error: Password must be exactly 9 characters, including at least 1 uppercase letter and 1 digit." << endl;
        return false;
    }

    ofstream file("customers.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: Could not open customers.txt for writing." << endl;
        return false;
    }

    file << cnic << "|" << password << "|" << fullName << "|" 
         << gender << "|" << phone << "|" << city << "|0" << endl;
    
    file.close();
    cout << "Registration successful! You may now log in." << endl;
    return true;
}