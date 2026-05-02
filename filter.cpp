#include "Filter.h"
#include<iostream>
using namespace std;

// Default Constructor
Filter::Filter() {
    id = 0;
    name = "Unknown";
    category = "Uncategorized";
    isEnabled = false;
}

// Parameterized Constructor
Filter::Filter(int id, string name, string category, bool isEnabled) {
    this->id = id;
    this->name = name;
    this->category = category;
    this->isEnabled = isEnabled;
}

// Setter
void Filter::setIsEnabled(bool isEnabled) {
    this->isEnabled = isEnabled;
}

// Getters
int Filter::getId() { return id; }
string Filter::getName() { return name; }
string Filter::getCategory() { return category; }
bool Filter::getIsEnabled() { return isEnabled; }
string Filter::getFilterName() const { return name; }
Filter::~Filter() {}