#ifndef FLIPHORIZONTALFILTER_H
#define FLIPHORIZONTALFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class FlipHorizontalFilter: public Filter{
public:    
    FlipHorizontalFilter();
    FlipHorizontalFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~FlipHorizontalFilter();
};

#endif