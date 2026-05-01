#ifndef CONTRASTFILTER_H
#define CONTRASTFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class ContrastFilter: public Filter{
private:    
    int contrastLevel;
public:    
    ContrastFilter();
    ContrastFilter(int id, string name, string category, bool isEnabled, int contrastLevel) 
        : Filter(id, name, category, isEnabled), contrastLevel(contrastLevel) {}
    void apply(Image& img) override;
    ~ContrastFilter();
};

#endif