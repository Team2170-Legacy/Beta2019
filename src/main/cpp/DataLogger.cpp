// This program will act as a data logger for rpm
/**
#include "DataLogger.h"

void DataLogger::addRPM(double rpmToAdd, char leftOrRight)
{
    if (leftOrRight == 'l' || leftOrRight == 'L')
    {
        rpmL.push_back(rpmToAdd);
    }
    if (leftOrRight == 'r' || leftOrRight == 'R')
    {
        rpmR.push_back(rpmToAdd);
    }
}

void DataLogger::addVisionError(double errorToAdd)
{
    visionError.push_back(errorToAdd);
}

void DataLogger::addTimeStamp(long timestampToAdd)
{
    timestamp.push_back(rpmToAdd);
}

void DataLogger::writeToTXTFile(string filename)
{
    ofstream logFile("example.txt");
    if (logFile.is_open())
    {
        logFile << "This is a line.\n";
        logFile << "This is another line.\n";
        logFile.close();
    }
}

std::string DataLogger::vectorToStr(vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size())
            cout << v.at(i) << ", ";
        else
            cout << v.at(i) << std::endl;
        //(i != v.size()) ? cout << v.at(i) << "," : cout << v.at(i) << std::endl;
    }
}

std::string DataLogger::vectorToStr(vector<long> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i != v.size())
            cout << v.at(i) << ", ";
        else
            cout << v.at(i) << std::endl;
        //(i != v.size()) ? cout << v.at(i) << "," : cout << v.at(i) << std::endl;
    }
}
**/