#include "BrightnessFilter.h"

BrightnessFilter::BrightnessFilter() : Filter(3, "Brightness Adjust", "Pixel Transform", true), brightnessLevel(50) {}
BrightnessFilter::~BrightnessFilter() {}

void BrightnessFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p = img.at(r, c);
            p.setR(p.getR() + brightnessLevel);
            p.setG(p.getG() + brightnessLevel);
            p.setB(p.getB() + brightnessLevel);
        }
    }
}