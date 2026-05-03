#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "Image.h"
#include<iostream>
using namespace std;

// Parameterized Constructor
Image::Image(int row, int col) {
    this->row = row;
    this->col = col;

    //allocation of dynamic 2d array
    grid = new Pixel*[row];
    for (int i = 0; i < row; ++i) {
        grid[i] = new Pixel[col];
    }
}

// Copy Constructor
Image::Image(const Image& other) {
    this->row = other.row;
    this->col = other.col;

    //allocation of dynamic 2d array
    grid = new Pixel*[row];
    for (int i = 0; i < row; ++i) {
        grid[i] = new Pixel[col];
        
        //copying values from the other grid to new grid
        for (int j = 0; j < col; ++j) {
            this->grid[i][j] = other.grid[i][j];
        }
    }
}

Image::Image(string path) {
    int channels;
    unsigned char* data = stbi_load(path.c_str(), &this->col, &this->row, &channels, 3); 

    if (data == nullptr) {
        cout << "Error: Could not load image at " << path << endl;
        this->row = 0; 
        this->col = 0;
        grid = nullptr;
        return;
    }

    //allocate your 2D grid
    grid = new Pixel*[row];
    for (int i = 0; i < row; ++i) {
        grid[i] = new Pixel[col];
    }

    //transfer data from 1D array to 2D grid
    for (int y = 0; y < row; ++y) {
        for (int x = 0; x < col; ++x) {
            //finding pixel's position 
            int index = 3 * (y * col + x); 
            int r = data[index + 0]; 
            int g = data[index + 1]; 
            int b = data[index + 2]; 

            grid[y][x] = Pixel(r, g, b); 
        }
    }
    stbi_image_free(data); 
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

void Image::displayASCII() {
    if (grid == nullptr || row == 0 || col == 0) {
        cout << "No image data to display." << endl;
        return;
    }

    cout << "========= Image Preview (" << col << "x" << row << ") =========" << endl;

    //Decreases the size of image if the image is big so it fits in the console
    int step = 1;
    if (col > 100 || row > 100) {
        step = col / 60; // Limits width to 60 characters
        if (step == 0) step = 1;
    }

    for (int y = 0; y < row; y += step) {
        for (int x = 0; x < col; x += step) {
            cout << grid[y][x]; 
        }
        cout << endl; 
    }
    
    cout << "Total pixels: " << (row * col) << endl;
}

void Image::save(string path) {
    if (grid == nullptr || row == 0 || col == 0) {
        cout << "No image data to save!" << endl;
        return;
    }

    // 1D Array to hold the pixel data
    unsigned char* temp_1D_array = new unsigned char[row * col * 3];

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; ++x) {
            int index = 3 * (y * col + x);

            temp_1D_array[index + 0] = grid[y][x].getR(); 
            temp_1D_array[index + 1] = grid[y][x].getG();
            temp_1D_array[index + 2] = grid[y][x].getB();
        }
    }

    // Writing the image using stb_image_write
    int success = stbi_write_png(path.c_str(), col, row, 3, temp_1D_array, col * 3); 
    
    if (success != 0) {
        cout << "Image saved successfully to " << path << endl;
    } else {
        cout << "Failed to save image." << endl;
    }

    delete[] temp_1D_array;
}


