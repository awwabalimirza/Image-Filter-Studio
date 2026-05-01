#include "ContrastFilter.h"

ContrastFilter::ContrastFilter() : Filter(4, "Contrast Stretch", "Pixel Transform", true), contrastLevel(0) {}
ContrastFilter::~ContrastFilter() {}

void ContrastFilter::apply(Image& img) {
    int minR = 255, maxR = 0, minG = 255, maxG = 0, minB = 255, maxB = 0;

    //Finding the min and max for each channel
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p = img.at(r, c);
            if (p.getR() < minR) minR = p.getR();
            if (p.getR() > maxR) maxR = p.getR();
            if (p.getG() < minG) minG = p.getG();
            if (p.getG() > maxG) maxG = p.getG();
            if (p.getB() < minB) minB = p.getB();
            if (p.getB() > maxB) maxB = p.getB();
        }
    }

    //Applying the contrast stretch formula
    for (int r = 0; r < img.getrow(); ++r) {
        for (int c = 0; c < img.getcol(); ++c) {
            Pixel& p = img.at(r, c);
            if (maxR > minR) p.setR((p.getR() - minR) * 255 / (maxR - minR));
            if (maxG > minG) p.setG((p.getG() - minG) * 255 / (maxG - minG));
            if (maxB > minB) p.setB((p.getB() - minB) * 255 / (maxB - minB));
        }
    }
}