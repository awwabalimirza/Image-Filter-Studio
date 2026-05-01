#ifndef GREENCHANNELFILTER_H
#define GREENCHANNELFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class GreenChannelFilter: public Filter{
public:    
    GreenChannelFilter();
    GreenChannelFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~GreenChannelFilter();
};

#endif