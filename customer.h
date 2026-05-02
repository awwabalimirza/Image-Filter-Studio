#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
#include<iostream>
#include<string>
using namespace std;

class Customer: public User{
private:
    string fullName;
    string gender;
    string phoneNumber;
    string city;
    bool isBlocked;

public:
    Customer();
    Customer(string cnic, string password, string fullName, string gender, string phoneNumber, string city, bool isBlocked = false) : User(cnic, password){
        this->fullName = fullName;
        this->gender = gender;
        this->phoneNumber = phoneNumber;    
        this->city = city;
        this->isBlocked = isBlocked;
        }

    void menu() override;
    
    // Getters
    string getCnic() const {} 
    string getFullName() const;
    string getGender() const;
    string getPhoneNumber() const;
    string getCity() const;
    bool getIsBlocked() const;
    
    // Setters
    void setIsBlocked(bool isBlocked);

    void loadImage();
    void viewHistory();
};

#endif