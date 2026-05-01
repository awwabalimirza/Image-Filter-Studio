#include "Image.h"
#include<iostream>
using namespace std;

// Parameterized Constructor
Image::Image(int row, int col) {
    this->row = row;
    this->col = col;

    //allocation of new 2d array
    grid = new Pixel*[row];
    for (int i = 0; i < row; ++i) {
        grid[i] = new Pixel[col];
    }
}

// Copy Constructor
Image::Image(const Image& other) {
    this->row = other.row;
    this->col = other.col;

    //allocation of new 2d array
    grid = new Pixel*[row];
    for (int i = 0; i < row; ++i) {
        grid[i] = new Pixel[col];
        
        //copying values from the other grid to new grid
        for (int j = 0; j < col; ++j) {
            this->grid[i][j] = other.grid[i][j];
        }
    }
}

// Destructor
Image::~Image() {
    for (int i = 0; i < row; ++i) {
        delete[] grid[i];
    }
    
    delete[] grid;
}

//getters
int Image::getrow() const { return row; }
int Image::getcol() const { return col; }

// Returns a reference to a specific pixel so it can be modified
Pixel& Image::at(int r, int c) {
    // bounds checking
    if (r < 0) r = 0;
    if (r >= row) r = row - 1;
    if (c < 0) c = 0;
    if (c >= col) c = col - 1;
    
    return grid[r][c];
}


