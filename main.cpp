#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// --- CORE CLASSES ---
#include "Admin.h"
#include "Customer.h"
#include "CustomerManager.h"
#include "FilterSession.h"
#include "Image.h"

// --- ALL 10 FILTER CLASSES ---
#include "FILTERS/GrayscaleFilter.h"
#include "FILTERS/InvertFilter.h"
#include "FILTERS/BrightnessFilter.h"
#include "FILTERS/ContrastFilter.h"
#include "FILTERS/RedChannelFilter.h"
#include "FILTERS/GreenChannelFilter.h"
#include "FILTERS/BlueChannelFilter.h"
#include "FILTERS/BoxBlurFilter.h"
#include "FILTERS/FlipHorizontalFilter.h"
#include "FILTERS/FlipVerticalFilter.h"         
using namespace std;

bool authenticateCustomer(string cnic, string password, Customer& loggedInUser) {
    ifstream file("customers.txt");
    if (!file.is_open()) return false;

    string line;
    while (getline(file, line)) {
        vector<string> fields;
        string currentField = "";
        
        // Parse the | delimited line using permitted .length() and .push_back()
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '|') {
                fields.push_back(currentField);
                currentField = "";
            } else {
                currentField += line[i];
            }
        }
        fields.push_back(currentField); // Push the last field (IsBlocked flag)

        // Check if CNIC and Password match
        if (fields[0] == cnic && fields[1] == password) {
            // Check if blocked
            if (fields[6] == "1") {
                cout << "\nAccess Denied: Your account has been blocked by an Admin.\n";
                file.close();
                return false;
            }
            
            // Populate the Customer object
            loggedInUser = Customer(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5], false);
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

int main() {
    CustomerManager customerManager;
    int mainChoice = 0;

    while (mainChoice != 4) {
        cout << "\n╔════════════════════════════════════════════════╗\n";
        cout << "║             IMAGE FILTER STUDIO                ║\n";
        cout << "╠════════════════════════════════════════════════╣\n";
        cout << "║    1. Admin Login                              ║\n";
        cout << "║    2. Customer Login                           ║\n";
        cout << "║    3. New Customer? Register here              ║\n";
        cout << "║    4. Exit                                     ║\n";
        cout << "╚════════════════════════════════════════════════╝\n";
        cout << "Your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            // --- ADMIN LOGIN ---
            string password;
            cout << "\nEnter Admin Password: ";
            cin >> password;

            Admin adminUser; 
            
            if (password == adminUser.getPassword()) {
                int adminChoice = 0;
                while (adminChoice != 4) {
                    adminUser.menu();
                    cout << "Enter choice: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) adminUser.manageFilterCatalog();
                    else if (adminChoice == 2) adminUser.manageCustomers();
                    else if (adminChoice == 3) adminUser.viewAllSessions();
                }
            } else {
                cout << "\nIncorrect Admin password!\n";
            }

        } else if (mainChoice == 2) {
            // --- CUSTOMER LOGIN (3 Attempt Lockout) ---
            string cnic, password;
            bool loggedIn = false;
            Customer activeCustomer;

            for (int attempts = 1; attempts <= 3; attempts++) {
                cout << "\n--- Customer Login (Attempt " << attempts << " of 3) ---\n";
                cout << "Enter CNIC: ";
                cin >> cnic;
                cout << "Enter Password: ";
                cin >> password;

                if (authenticateCustomer(cnic, password, activeCustomer)) {
                    loggedIn = true;
                    break; 
                } else {
                    cout << "Invalid credentials or account blocked.\n";
                }
            }

            if (!loggedIn) {
                cout << "\nMaximum login attempts reached. Returning to main menu.\n";
                continue; 
            }

            // --- ACTIVE CUSTOMER WORKFLOW ---
            int custChoice = 0;
            Image* currentImage = nullptr;

            while (custChoice != 6) {
                activeCustomer.menu();
                cout << "Enter choice: ";
                cin >> custChoice;

                if (custChoice == 1) {
                    // Quick view of the catalog
                    cout << "\n--- Available Filters ---\n";
                    ifstream cat("catalog.txt");
                    string catLine;
                    if (cat.is_open()) {
                        while(getline(cat, catLine)) {
                            string displayLine = "";
                            for(int i = 0; i < catLine.length(); i++) {
                                if (catLine[i] == '|') displayLine += " - ";
                                else displayLine += catLine[i];
                            }
                            cout << displayLine << endl;
                        }
                        cat.close();
                    } else {
                        cout << "Catalog file not found.\n";
                    }

                } else if (custChoice == 2) {
                    // Load Image
                    string imagePath;
                    cout << "Enter path to image file (e.g., photo.jpg): ";
                    cin >> imagePath;
                    
                    if (currentImage != nullptr) delete currentImage; 
                    
                    currentImage = new Image(imagePath);
                    if (currentImage->getrow() > 0) {
                        cout << "Image loaded successfully: " << currentImage->getcol() << " x " << currentImage->getrow() << " pixels.\n";
                        currentImage->displayASCII();
                    }

                } else if (custChoice == 3) {
                    // Build & Apply Pipeline
                    if (currentImage == nullptr || currentImage->getrow() == 0) {
                        cout << "Error: You must load an image first (Option 2).\n";
                        continue;
                    }

                    // FIX 1: Pass the local 'cnic' string variable directly to bypass Customer memory issues
                    FilterSession session(currentImage, cnic);
                    int filterID = -1;

                    // FIX 2: Replaced \n with endl to force the console to print immediately
                    cout << "\n=== Build Filter Pipeline ===" << endl; 
                    
                    while (filterID != 0) {
                        cout << "Enter Filter ID to add (0 to finish building): ";
                        cin >> filterID;

                        if (filterID == 0) break;

                        // MAP IDs TO SPECIFIC FILTER CLASSES
                        if (filterID == 1) session.addFilter(new GrayscaleFilter());
                        else if (filterID == 2) session.addFilter(new InvertFilter());
                        else if (filterID == 3) session.addFilter(new BrightnessFilter());
                        else if (filterID == 4) session.addFilter(new ContrastFilter());
                        else if (filterID == 5) session.addFilter(new RedChannelFilter());
                        else if (filterID == 6) session.addFilter(new GreenChannelFilter());
                        else if (filterID == 7) session.addFilter(new BlueChannelFilter());
                        else if (filterID == 8) session.addFilter(new BoxBlurFilter());
                        else if (filterID == 9) session.addFilter(new FlipHorizontalFilter());
                        else if (filterID == 10) session.addFilter(new FlipVerticalFilter());
                        else {
                            cout << "Invalid Filter ID. Please check the catalog.\n";
                        }
                    }

                    if (session.getPipelineSize() > 0) {
                        session.applyPipeline();
                        
                        char saveChoice;
                        cout << "Pipeline complete. Save result? (y/n): ";
                        cin >> saveChoice;
                        
                        if (saveChoice == 'y' || saveChoice == 'Y') {
                            session.saveResult("png");
                            session.recordSession();
                        }
                    } else {
                        cout << "Pipeline empty. No filters applied.\n";
                    }

                } else if (custChoice == 4) {
                    cout << "Use Option 3 to build, apply, and save the pipeline at once.\n";
                } else if (custChoice == 5) {
                    activeCustomer.viewHistory();
                }
            }
            
            // Clean up image memory when customer logs out
            if (currentImage != nullptr) {
                delete currentImage;
                currentImage = nullptr;
            }

        } else if (mainChoice == 3) {
            // --- REGISTRATION ---
            string cnic, pass, name, gender, phone, city;
            cout << "\n--- New Customer Registration ---\n";
            cout << "Enter 13-digit CNIC: "; cin >> cnic;
            cout << "Enter 9-char Password (1 uppercase, 1 digit): "; cin >> pass;
            
            cin.ignore(); 
            cout << "Enter Full Name: "; getline(cin, name);
            cout << "Enter Gender (M/F/Other): "; cin >> gender;
            cout << "Enter Phone Number: "; cin >> phone;
            cout << "Enter City: "; cin >> city;

            customerManager.registerCustomer(cnic, pass, name, gender, phone, city);
        }
    }

    cout << "\nExiting Image Filter Studio. Goodbye!\n";
    return 0;
}