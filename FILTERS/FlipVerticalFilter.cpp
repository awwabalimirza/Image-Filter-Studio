#include "FlipVerticalFilter.h"

FlipVerticalFilter::FlipVerticalFilter() : Filter(10, "Flip Vertical", "Geometric", true) {}
FlipVerticalFilter::~FlipVerticalFilter() {}

void FlipVerticalFilter::apply(Image& img) {
    int rows = img.getrow();
    int cols = img.getcol();

    // Only go halfway DOWN the rows
    for (int r = 0; r < rows / 2; ++r) {
        for (int c = 0; c < cols; ++c) {
            
            // Swap the top pixel with the bottom pixel
            Pixel temp = img.at(r, c);
            img.at(r, c) = img.at(rows - 1 - r, c);
            img.at(rows - 1 - r, c) = temp;
            
        }
    }
}