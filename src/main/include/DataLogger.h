// This program will act as a data logger for rpm
/**
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Datalogger {
public:
    vector<double> rpmL; rpmL.reserve(10000);
    vector<double> rpmR; rpmR.reserve(10000);
    vector<double> visionError; visionError.reserve(10000);
    vector<long> timestamp; timestamp.reserve(10000);

    void addRPM(double rpmToAdd, char leftOrRight);
    void addVisionError(double errorToAdd);
    void addTimeStamp(long timestampToAdd);
    void writeToTXTFile(string filename);
    std::string vectorToStr(vector<double> v);
    std::string vectorToStr(vector<long> v); 
}
**/