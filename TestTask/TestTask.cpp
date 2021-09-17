#include <iostream>
#include <fstream>
#include<string>
#include <map>
#include <vector>
struct DateAndHour
{
    std::string date;
    std::string hour;
};

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
};


int main()
{
    std::ifstream csv_reader("acme_worksheet.csv");
    std::string line;
    std::map<std::string, std::vector<DateAndHour>> employees;


    if (csv_reader.is_open()) 
    {
        std::vector<std::string> ss;
        while (getline(csv_reader, line))
        {
            ss.clear();
            std::cout << line << std::endl;
            ss = split(line, ",");
            employees[ss[0]].push_back({ ss[1], ss[2] });
        }
    }

    std::fstream fout;
    fout.open("reportcard.csv", std::ios::out);
    std::vector<std::string> vints;
    for (auto const& imap : employees)
        vints.push_back(imap.first);
    std::vector<DateAndHour> date = employees[vints[0]];
    std::cout << "f";
    //fout << employees
}

