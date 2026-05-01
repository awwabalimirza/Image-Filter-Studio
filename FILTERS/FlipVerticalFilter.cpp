#include "FlipVerticalFilter.h"

FlipVerticalFilter::FlipVerticalFilter() : Filter(10, "Flip Vertical", "Geometric", true) {}
FlipVerticalFilter::~FlipVerticalFilter() {}

void FlipVerticalFilter::apply(Image& img) {
    int rows = img.getrow();
    // Only go halfway down the rows
    for (int r = 0; r < rows / 2; ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p1 = img.at(r, c);
            Pixel& p2 = img.at(rows - 1 - r, c);
            
            // Swap logic
            int tempR = p1.getR(), tempG = p1.getG(), tempB = p1.getB();
            
            p1.setR(p2.getR()); p1.setG(p2.getG()); p1.setB(p2.getB());
            p2.setR(tempR); p2.setG(tempG); p2.setB(tempB);
        }
    }
}