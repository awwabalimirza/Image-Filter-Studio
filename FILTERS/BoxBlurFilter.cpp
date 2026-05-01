#include "BoxBlurFilter.h"

BoxBlurFilter::BoxBlurFilter() : Filter(8, "Box Blur (3x3)", "Spatial Filter", true) {}
BoxBlurFilter::~BoxBlurFilter() {}

void BoxBlurFilter::apply(Image& img) {
    // 1. Create a deep copy using the Image copy constructor
    Image copy(img); 
    
    int rows = img.getrow();
    int cols = img.getcol();
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;
            
            // 2. Look at the 3x3 neighborhood (from -1 to +1)
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int neighborRow = r + i;
                    int neighborCol = c + j;
                    
                    // 3. Edge handling: Only process neighbors that actually exist inside the bounds
                    if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                        // Read from the UNMODIFIED copy
                        Pixel& p = copy.at(neighborRow, neighborCol);
                        sumR += p.getR();
                        sumG += p.getG();
                        sumB += p.getB();
                        count++;
                    }
                }
            }
            
            // 4. Calculate the average and write to the REAL image
            Pixel& target = img.at(r, c);
            target.setR(sumR / count);
            target.setG(sumG / count);
            target.setB(sumB / count);
        }
    }
}