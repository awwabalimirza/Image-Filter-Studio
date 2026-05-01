#ifndef BRIGHTNESSFILTER_H
#define BRIGHTNESSFILTER_H
#include "filter.h"
#include "image.h"
#include<iostream>
using namespace std;

class BrightnessFilter: public Filter{
private:    
    int brightnessLevel;    
public:    
    BrightnessFilter();
    BrightnessFilter(int id, string name, string category, bool isEnabled, int brightnessLevel) 
        : Filter(id, name, category, isEnabled), brightnessLevel(brightnessLevel) {}
    void apply(Image& img) override;
    ~BrightnessFilter();
};

#endif