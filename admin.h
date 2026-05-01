#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include<iostream>
#include<string>
using namespace std;

class Admin: public User{
public:
    Admin();
    Admin(string username, string password) : User(username, password) {};
    void menu() override;
    void manageFilterCatalog();
    void manageCustomers();
    void viewAllSessions();
    ~Admin();
};

#endif