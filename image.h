#ifndef IMAGE_H
#define IMAGE_H
#include "pixel.h"
#include "savable.h"
#include<iostream>
using namespace std;

class Image: public Savable{
private:
    Pixel** grid;
    int row;
    int col;
public:
    Image(int row, int col);
    Image(const Image& other);
    int getrow() const;
    int getcol() const;
    Pixel& at(int row, int col);
    void displayASCII();
    void save(string path) override;
    friend class FilterSession;
    ~Image();
};

#endif