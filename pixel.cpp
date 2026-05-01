#include "Pixel.h"
#include<iostream>
using namespace std;
// Default constructor
Pixel::Pixel() {
    r = 0;
    g = 0;
    b = 0;
}

// Parameterized constructor
Pixel::Pixel(int r, int g, int b) {
    this->r = clamp(r);
    this->g = clamp(g);
    this->b = clamp(b);
}

// Getters
int Pixel::getR() { return r; }
int Pixel::getG() { return g; }
int Pixel::getB() { return b; }

// Setters
void Pixel::setR(int r) { this->r = clamp(r); }
void Pixel::setG(int g) { this->g = clamp(g); }
void Pixel::setB(int b) { this->b = clamp(b); }

//Keeps channel values strictly within 0-255
int Pixel::clamp(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

//+ Overloading
Pixel Pixel::operator+(const Pixel& other) {
    return Pixel(
        clamp(this->r + other.r),
        clamp(this->g + other.g),
        clamp(this->b + other.b)
    );
}

ostream& operator<<(ostream& os, const Pixel& pixel) {
    //brightness is the average of the three channels
    int brightness = (pixel.r + pixel.g + pixel.b) / 3;
    char asciiChar;

    if (brightness < 28) {
        asciiChar = ' ';
    } else if (brightness < 57) {
        asciiChar = '.';
    } else if (brightness < 85) {
        asciiChar = ':';
    } else if (brightness < 114) {
        asciiChar = '-';
    } else if (brightness < 142) {
        asciiChar = '=';
    } else if (brightness < 170) {
        asciiChar = '+';
    } else if (brightness < 199) {
        asciiChar = '*';
    } else if (brightness < 227) {
        asciiChar = '#';
    } else {
        asciiChar = '@'; 
    }

    os << asciiChar;
    return os;
}