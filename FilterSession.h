#ifndef FILTERSESSION_H
#define FILTERSESSION_H
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<ctime>
#include "image.h"
#include "filter.h"
using namespace std;

class FilterSession{
private:
    Image* image;
    vector<Filter*> pipeline;
    string cnic;
    string timestamp;
    string outputFile;

    string generateTimestamp();
    string buildFilterString();

public:
    FilterSession(Image* img, string cnic);
    ~FilterSession();

    FilterSession& addFilter(Filter* f);
    void clearPipeline();
    void displayPipeline();
    int getPipelineSize();

    void applyPipeline();
    bool saveResult(string fmt);
    void recordSession();

    string getOutputFile();
    string getTimestamp();
};

#endif