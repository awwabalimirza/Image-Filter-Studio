#include "InvertFilter.h"

InvertFilter::InvertFilter() : Filter(2, "Invert", "Pixel Transform", true) {}
InvertFilter::~InvertFilter() {}

void InvertFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p = img.at(r, c);
            // Invert subtracts the current value from 255
            p.setR(255 - p.getR());
            p.setG(255 - p.getG());
            p.setB(255 - p.getB());
        }
    }
}