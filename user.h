#ifndef USER_H
#define USER_H
#include<iostream>
#include<string>
using namespace std;

class User{
private:
    string username;
    string password;
public:
    User();
    User(string username, string password);
    string getUsername();
    string getPassword();
    void setUsername(string username);
    void setPassword(string password);
    virtual void menu() = 0;
    virtual ~User();
};

#endif