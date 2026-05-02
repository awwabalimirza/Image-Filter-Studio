#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CustomerManager {
public:
    bool isValidCNIC(string cnic);
    bool isCNICUnique(string cnic);
    bool isCNICBlocked(string cnic);
    bool isValidPassword(string password);
    bool registerCustomer(string cnic, string password, string fullName, string gender, string phone, string city);
};

#endif