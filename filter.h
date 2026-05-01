#ifndef FILTER_H
#define FILTER_H   
#include<iostream>
#include "image.h"
using namespace std;

class Filter{
private:
    int id; 
    string name;
    string category;
    bool isEnabled;
public:
    Filter();
    Filter(int id, string name, string category, bool isEnalbed);
    void setIsEnabled(bool isEnabled);
    int getId();
    string getName();
    string getCategory();
    bool getIsEnabled();
    virtual void apply(Image& img)=0;
    virtual ~Filter();
};

#endif