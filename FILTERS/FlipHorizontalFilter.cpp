#include "FlipHorizontalFilter.h"

FlipHorizontalFilter::FlipHorizontalFilter() : Filter(9, "Flip Horizontal", "Geometric", true) {}
FlipHorizontalFilter::~FlipHorizontalFilter() {}

void FlipHorizontalFilter::apply(Image& img) {
    int cols = img.getcol();
    for (int r = 0; r < img.getrow(); ++r) {
        // Only go halfway across the columns
        for (int c = 0; c < cols / 2; ++c) {
            Pixel& p1 = img.at(r, c);
            Pixel& p2 = img.at(r, cols - 1 - c);
            
            // Swap logic
            int tempR = p1.getR(), tempG = p1.getG(), tempB = p1.getB();
            
            p1.setR(p2.getR()); p1.setG(p2.getG()); p1.setB(p2.getB());
            p2.setR(tempR); p2.setG(tempG); p2.setB(tempB);
        }
    }
}