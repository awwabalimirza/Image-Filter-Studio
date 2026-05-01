#include "BlueChannelFilter.h"

BlueChannelFilter::BlueChannelFilter() : Filter(7, "Blue Channel Only", "Pixel Transform", true) {}
BlueChannelFilter::~BlueChannelFilter() {}

void BlueChannelFilter::apply(Image& img) {
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            // Keep blue intact, wipe out red and green
            img.at(r, c).setR(0);
            img.at(r, c).setG(0);
        }
    }
}