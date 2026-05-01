#include "User.h"
#include<iostream>
using namespace std;

// Default Constructor
User::User() {
    username = "Unknown";
    password = "Unassigned";
}

// Parameterized Constructor
User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

// Getters
string User::getUsername() { return username; }
string User::getPassword() { return password; }

// Setters
void User::setUsername(string username) { this->username = username; }
void User::setPassword(string password) { this->password = password; }

User::~User() {}