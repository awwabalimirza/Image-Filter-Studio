#include "RedChannelFilter.h"

RedChannelFilter::RedChannelFilter() : Filter(5, "Red Channel Only", "Pixel Transform", true) {}
RedChannelFilter::~RedChannelFilter() {}

void RedChannelFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            // Keep red intact, wipe out green and blue
            img.at(r, c).setG(0);
            img.at(r, c).setB(0);
        }
    }
}