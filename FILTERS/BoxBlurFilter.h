#ifndef BOXBLURFILTER_H
#define BOXBLURFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class BoxBlurFilter: public Filter{
public:   
    BoxBlurFilter();
    BoxBlurFilter(int id, string name, string category, bool isEnabled) : Filter(id, name, category, isEnabled) {}
    void apply(Image& img) override;
    ~BoxBlurFilter();
};

#endif