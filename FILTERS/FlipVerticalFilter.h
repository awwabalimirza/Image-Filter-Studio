#ifndef FLIPVERTICALFILTER_H
#define FLIPVERTICALFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class FlipVerticalFilter: public Filter{
public:    
    FlipVerticalFilter();
    FlipVerticalFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~FlipVerticalFilter();
};

#endif