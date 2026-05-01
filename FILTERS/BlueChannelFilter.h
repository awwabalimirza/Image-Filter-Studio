#ifndef BLUECHANNELFILTER_H
#define BLUECHANNELFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class BlueChannelFilter: public Filter{
public:
    BlueChannelFilter();
    BlueChannelFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~BlueChannelFilter();
};

#endif