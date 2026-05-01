#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "user.h"
#include<iostream>
using namespace std;
#include<string>

class Customer: public User{
private:
    string cnic;
    string fullName;
    string gender;
    string phoneNumber;
    string city;
    bool isBlocked;
public:
    Customer();
    Customer(string username, string password, string cnic, string fullName, string gender, string phoneNumber, string city) : User(username, password) {}
    void menu() override;
    string getCnic();
    string getFullName();
    string getGender();
    string getPhoneNumber();
    string getCity();
    bool getIsBlocked();
    void setIsBlocked(bool isBlocked);
    void loadImage();
    void viewHistory();
};

#endif