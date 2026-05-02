#ifndef ADMIN_H
#define ADMIN_H
#include "User.h" 
#include<iostream>
#include<string>
using namespace std;

class Admin: public User{
public:
    Admin();
    Admin(string password) : User("admin", password) {}; 
    void menu() override;
    void manageFilterCatalog();
    void manageCustomers();
    void viewAllSessions();
    
    ~Admin();
};

#endif