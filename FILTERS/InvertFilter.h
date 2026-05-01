#ifndef INVERTFILTER_H
#define INVERTFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class InvertFilter: public Filter{
public:    
    InvertFilter();
    InvertFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~InvertFilter();
};

#endif