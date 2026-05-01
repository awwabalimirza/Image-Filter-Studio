#ifndef PIXEL_H
#define PIXEL_H
#include<iostream>
using namespace std;

class Pixel{
private:
    int r;
    int g;
    int b;
public:
    Pixel();
    Pixel(int r, int g, int b);
    int getR();
    int getG();
    int getB();
    void setR(int r);
    void setG(int g);
    void setB(int b);
    static int clamp(int value);
    Pixel operator+(const Pixel& other);
    friend ostream& operator<<(ostream& os, const Pixel& pixel);
};

#endif