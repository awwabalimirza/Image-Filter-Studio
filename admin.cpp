#include "Admin.h"
#include <iostream>
#include <vector>
#include <fstream>

Admin::Admin() : User("admin", "admin123") {}
Admin::~Admin() {}

void Admin::menu() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════╗\n";
    cout << "║       ADMIN PANEL - Image Filter Studio        ║\n";
    cout << "╠════════════════════════════════════════════════╣\n";
    cout << "║    1. Manage Filter Catalog                    ║\n";
    cout << "║    2. Manage Customers                         ║\n";
    cout << "║    3. View All Sessions                        ║\n";
    cout << "║    4. Logout                                   ║\n";
    cout << "╚════════════════════════════════════════════════╝\n";
}

void Admin::viewAllSessions() {
    cout << "\n=========== All System Sessions ============\n";
    
    ifstream file("sessions.txt");
    if (!file.is_open()) {
        cout << "No sessions have been recorded yet." << endl;
        return;
    }

    string line;
    bool hasData = false;
    while (getline(file, line)) {
        cout << line << endl;
        hasData = true;
    }
    file.close();

    if (!hasData) {
        cout << "The sessions file is empty." << endl;
    }
}

void Admin::manageFilterCatalog() {
    int choice = 0;
    
    while (choice != 3) {
        cout << "\n╔════════════════════════════════════════════════╗\n";
        cout << "║           MANAGE FILTER CATALOG                ║\n";
        cout << "╠════════════════════════════════════════════════╣\n";
        cout << "║    1. View Catalog                             ║\n";
        cout << "║    2. Toggle Filter (Enable/Disable)           ║\n";
        cout << "║    3. Back to Admin Panel                      ║\n";
        cout << "╚════════════════════════════════════════════════╝\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // --- VIEW CATALOG (List Format) ---
            cout << "\n--- Filter Catalog ---\n";
            
            ifstream inFile("catalog.txt");
            string line;
            bool hasData = false;
            
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    hasData = true;
                    string displayLine = "";
                    
                    // Replace the '|' with ' - ' for a cleaner list view
                    for (int i = 0; i < line.length(); i++) {
                        if (line[i] == '|') {
                            displayLine += " - ";
                        } else {
                            displayLine += line[i];
                        }
                    }
                    
                    cout << displayLine << endl;
                }
                inFile.close();
            }
            if (!hasData) cout << "Catalog is empty or missing.\n";

        } else if (choice == 2) {
            // --- TOGGLE FILTER ENABLE/DISABLE ---
            string targetID;
            cout << "Enter 2-digit Filter ID to toggle (e.g., 01, 10): ";
            cin >> targetID;

            vector<string> lines;
            string line;
            bool found = false;

            // 1. Read file into memory using .push_back()
            ifstream inFile("catalog.txt");
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    lines.push_back(line);
                }
                inFile.close();
            } else {
                cout << "Error: Could not open catalog.txt.\n";
                continue;
            }

            // 2. Find, modify, and rewrite using .size() and .length()
            ofstream outFile("catalog.txt", ios::trunc);
            for (int i = 0; i < lines.size(); i++) {
                
                // Extract Filter ID (the characters before the first '|')
                string currentID = "";
                for(int j = 0; j < lines[i].length() && lines[i][j] != '|'; j++){
                    currentID += lines[i][j];
                }

                if (currentID == targetID) {
                    found = true;
                    
                    // Use .length() to easily target the last character
                    int lastIndex = lines[i].length() - 1;

                    // Toggle the flag
                    if (lines[i][lastIndex] == '1') {
                        lines[i][lastIndex] = '0';
                        cout << "Filter " << targetID << " is now DISABLED.\n";
                    } else if (lines[i][lastIndex] == '0') {
                        lines[i][lastIndex] = '1';
                        cout << "Filter " << targetID << " is now ENABLED.\n";
                    }
                }
                outFile << lines[i] << endl;
            }
            outFile.close();
            
            if (!found) cout << "Filter ID not found.\n";
        }
    }
}

void Admin::manageCustomers() {
    int choice = 0;
    
    while (choice != 5) {
        cout << "\n╔════════════════════════════════════════════════╗\n";
        cout << "║             MANAGE CUSTOMERS                   ║\n";
        cout << "╠════════════════════════════════════════════════╣\n";
        cout << "║    1. View All Customers                       ║\n";
        cout << "║    2. Search Customer                          ║\n";
        cout << "║    3. Block Customer                           ║\n";
        cout << "║    4. Delete Customer                          ║\n";
        cout << "║    5. Back to Admin Panel                      ║\n";
        cout << "╚════════════════════════════════════════════════╝\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // --- VIEW ALL CUSTOMERS ---
            cout << "\n--- Registered Customers ---\n";
            ifstream inFile("customers.txt");
            string line;
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    cout << line << endl;
                }
                inFile.close();
            } else {
                cout << "No customers found.\n";
            }

        } else if (choice == 2) {
            // --- SEARCH CUSTOMER ---
            string searchCnic;
            cout << "Enter 13-digit CNIC to search: ";
            cin >> searchCnic;
            
            ifstream inFile("customers.txt");
            string line;
            bool found = false;
            
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    // Manually check if the first 13 characters match the CNIC
                    bool match = true;
                    for (int i = 0; i < 13 ; i++) {
                        if (line[i] != searchCnic[i]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        cout << "Customer Found: " << line << endl;
                        found = true;
                        break;
                    }
                }
                inFile.close();
            }
            if (!found) cout << "Customer not found.\n";

        } else if (choice == 3) {
            // --- BLOCK CUSTOMER ---
            string targetCnic;
            cout << "Enter CNIC of customer to block: ";
            cin >> targetCnic;

            vector<string> lines;
            string line;
            bool found = false;

            // Read all lines
            ifstream inFile("customers.txt");
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    lines.push_back(line);
                }
                inFile.close();
            }

            // Rewrite file, modifying the target customer
            ofstream outFile("customers.txt", ios::trunc);
            for (int i = 0; i < lines.size(); i++) {
                bool match = true;
                for (int j = 0; j < 13 && j < targetCnic.length(); j++) {
                    if (lines[i][j] != targetCnic[j]) match = false;
                }

                if (match) {
                    found = true;
                    // Change the last character (IsBlocked) from 0 to 1
                    int lastIndex = lines[i].length() - 1;
                    if (lines[i][lastIndex] == '0') {
                        lines[i][lastIndex] = '1';
                    }
                    outFile << lines[i] << endl;
                    
                    // Add to blocked_cnics.txt
                    ofstream blockFile("blocked_cnics.txt", ios::app);
                    blockFile << targetCnic << endl;
                    blockFile.close();
                    
                    cout << "Customer " << targetCnic << " has been blocked.\n";
                } else {
                    outFile << lines[i] << endl;
                }
            }
            outFile.close();
            if (!found) cout << "Customer not found.\n";

        } else if (choice == 4) {
            // --- DELETE CUSTOMER (Using vector<string> exactly as requested) ---
            string targetCnic;
            cout << "Enter CNIC of customer to entirely delete: ";
            cin >> targetCnic;

            vector<string> lines;
            string line;
            bool found = false;

            // 1. Read all lines into the vector[cite: 1]
            ifstream inFile("customers.txt");
            if (inFile.is_open()) {
                while (getline(inFile, line)) {
                    lines.push_back(line);
                }
                inFile.close();
            } else {
                cout << "Error: Could not open database.\n";
                continue; // Skip the rest of the loop
            }

            // 2. Rewrite the file, skipping the deleted one[cite: 1]
            ofstream outFile("customers.txt", ios::trunc); // ios::trunc wipes the file clean
            for (int i = 0; i < lines.size(); i++) {
                bool match = true;
                // Check if the line starts with our target CNIC
                for (int j = 0; j < 13 ; j++) {
                    if (lines[i][j] != targetCnic[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    found = true; 
                    // We DO NOT write this line to the file, effectively deleting it[cite: 1]
                } else {
                    outFile << lines[i] << endl; // Keep all other lines
                }
            }
            outFile.close();

            if (found) {
                cout << "Customer " << targetCnic << " deleted successfully.\n";
            } else {
                cout << "Customer not found.\n";
            }
        }
    }
}