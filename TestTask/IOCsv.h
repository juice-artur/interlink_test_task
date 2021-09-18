#pragma once
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

struct DateAndHour
{
    std::string date;
    std::string hour;
};


class IOCsv
{
public:
	IOCsv(std::string inputPath, std::string outputPath);
private:
    std::vector<std::string> split(std::string s, std::string delimiter);
    std::string DateToNumber(std::string date);
    void ReadCsv(std::string path);
    void WriteCsv(std::string path);
    std::ifstream csv_reader;
    std::string line;
    std::map<std::string, std::vector<DateAndHour>> employees;
    std::vector<std::string> dateList;
};

