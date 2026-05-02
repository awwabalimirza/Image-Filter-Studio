#include "FlipHorizontalFilter.h"

FlipHorizontalFilter::FlipHorizontalFilter() : Filter(9, "Flip Horizontal", "Geometric", true) {}
FlipHorizontalFilter::~FlipHorizontalFilter() {}

void FlipHorizontalFilter::apply(Image& img) {
    int rows = img.getrow();
    int cols = img.getcol();

    for (int r = 0; r < rows; ++r) {
        // Only go halfway across the columns
        for (int c = 0; c < cols / 2; ++c) {
            
            // Clean, object-level swap (No need for getR or setR!)
            Pixel temp = img.at(r, c);
            img.at(r, c) = img.at(r, cols - 1 - c);
            img.at(r, cols - 1 - c) = temp;
            
        }
    }
}