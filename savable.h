#ifndef SAVABLE_H
#define SAVABLE_H
#include<iostream>
using namespace std;

class Savable{
    public:
    virtual void save(string path)=0;
};

#endif