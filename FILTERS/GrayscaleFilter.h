#ifndef GRAYSCALEFILTER_H
#define GRAYSCALEFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class GrayscaleFilter: public Filter{
public:    
    GrayscaleFilter();
    GrayscaleFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~GrayscaleFilter();
};

#endif