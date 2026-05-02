#include "filtersession.h"

// Constructor
FilterSession::FilterSession(Image* img, string cnic) {
    this->image = img;
    this->cnic = cnic;
    this->timestamp = generateTimestamp();
    this->outputFile = "";
}

// Destructor
FilterSession::~FilterSession() {
    clearPipeline(); 
}

// Generates a timestamp "YYYYMMDD_HHMMSS"
string FilterSession::generateTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);
    return string(buffer);
}

// Builds the filter string for sessions.txt 
string FilterSession::buildFilterString() {
    string result = "";
    // Dynamically check size instead of tracking filterCount
    for (int i = 0; i < pipeline.size(); ++i) { 
        result += pipeline[i]->getFilterName();

        if (i < pipeline.size() - 1) {
            result += ">";
        }
    }
    
    if (result == "") {
        result = "NoFilters";
    }
    return result;
}

// Safely push to the back of the vector
FilterSession& FilterSession::addFilter(Filter* f) {
    pipeline.push_back(f); 
    return *this; 
}

// Safely delete memory and empty the vector
void FilterSession::clearPipeline() {
    for (int i = 0; i < pipeline.size(); ++i) {
        delete pipeline[i];
        pipeline[i] = nullptr; 
    }
    pipeline.clear(); 
}

void FilterSession::displayPipeline() {
    cout << "Current Pipeline: [ ";
    for (int i = 0; i < pipeline.size(); ++i) {
        cout << pipeline[i]->getFilterName() << " "; 
    }
    cout << "]" << endl;
}

int FilterSession::getPipelineSize() {
    return pipeline.size();
}

void FilterSession::applyPipeline() {
    if (image == nullptr) {
        cout << "Error: No image loaded." << endl;
        return;
    }

    cout << "======== Applying Filters ========" << endl;
    for (int i = 0; i < pipeline.size(); ++i) {
        cout << "Applying filter " << (i + 1) << "/" << pipeline.size() << "..." << endl;
        
        // Polymorphism in action
        pipeline[i]->apply(*image); 
        
        // Show ASCII preview after each filter
        image->displayASCII(); 
    }
    cout << "All " << pipeline.size() << " filters applied." << endl;
}

bool FilterSession::saveResult(string format) {
    if (image == nullptr) return false;

    // CNIC_timestamp.png
    outputFile = cnic + "_" + timestamp + "." + format;
    image->save(outputFile);
    return true;
}

void FilterSession::recordSession() {
    ofstream outFile("sessions.txt", ios::app); 
    
    if (!outFile) {
        cout << "Error: Could not open sessions.txt for writing." << endl;
        return;
    }

    // Format: CNIC | Timestamp | Filters Applied | OutputFile
    outFile << cnic << "|" 
            << timestamp << "|" 
            << buildFilterString() << "|" 
            << outputFile << endl;

    outFile.close();
    cout << "Session recorded in sessions.txt." << endl;
}

string FilterSession::getOutputFile() { return outputFile; }
string FilterSession::getTimestamp() { return timestamp; }