// This program will act as a data logger for rpm
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Datalogger {
public:
    vector<double> rpm;
    vector<long> timestamp;

    void addRPM(double rpmToAdd);
    void addTimeStamp(long timestampToAdd);
    void writeToTXTFile(string filename); 
}