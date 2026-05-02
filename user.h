#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

class User{
protected:
    string ID;
    string password;
public:
    User();
    User(string ID, string password);
    string getID() const;
    string getPassword() const;
    void setID(string ID);
    void setPassword(string password);
    virtual void menu() = 0;
    virtual ~User();
};

#endif