#ifndef REDCHANNELFILTER_H
#define REDCHANNELFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class RedChannelFilter: public Filter{
public:    
    RedChannelFilter();
    RedChannelFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~RedChannelFilter();
}; 

#endif