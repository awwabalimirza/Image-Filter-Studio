#include "user.h"
#include<iostream>
using namespace std;

// Default Constructor
User::User() {
    ID = "Unknown";
    password = "Unassigned";
}

// Parameterized Constructor
User::User(string ID, string password) {
    this->ID = ID;
    this->password = password;
}

// Getters
string User::getID() const{ return ID  ; }
string User::getPassword() const{ return password; }

// Setters
void User::setID(string ID) { this->ID = ID; }
void User::setPassword(string password) { this->password = password; }

User::~User() {}