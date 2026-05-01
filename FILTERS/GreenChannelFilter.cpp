#include "GreenChannelFilter.h"

GreenChannelFilter::GreenChannelFilter() : Filter(6, "Green Channel Only", "Pixel Transform", true) {}
GreenChannelFilter::~GreenChannelFilter() {}

void GreenChannelFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            // Keep green intact, wipe out red and blue
            img.at(r, c).setR(0);
            img.at(r, c).setB(0);
        }
    }
}