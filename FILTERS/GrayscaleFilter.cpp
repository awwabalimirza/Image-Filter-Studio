#include "GrayscaleFilter.h"

GrayscaleFilter::GrayscaleFilter() : Filter(1, "Grayscale", "Pixel Transform", true) {}

void GrayscaleFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p = img.at(r, c);
            // Grayscale is the average of the three channels
            int avg = (p.getR() + p.getG() + p.getB()) / 3; 
            p.setR(avg);
            p.setG(avg);
            p.setB(avg);
        }
    }
}

GrayscaleFilter::~GrayscaleFilter() {}