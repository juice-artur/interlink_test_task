﻿#include <iostream>
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
    std::vector<std::string> dateList;
    dateList.resize(1);

    if (csv_reader.is_open()) 
    {
        std::vector<std::string> ss;
        while (getline(csv_reader, line))
        {
            ss.clear();
            ss = split(line, ",");
            if (ss[1] != dateList.back()) 
            {
                dateList.push_back(ss[1]);
            } 

            employees[ss[0]].push_back({ ss[1], ss[2] });
        }
    }
    dateList.erase(dateList.begin(), dateList.begin() + 2);




    std::fstream fout;
    fout.open("reportcard.csv", std::ios::out);
    std::vector<std::string> all_names;
    for (auto const& imap : employees)
        all_names.push_back(imap.first);
    fout << "Name/Date" << ",";
    std::cout << "Name/Date" << ",";
    for (auto const& imap : dateList) 
    {

        if (dateList.back() == imap)
        {
            fout << imap;
            std::cout << imap;
        }
        else
        {
            fout << imap << ",";
            std::cout << imap << ",";
        }
    }

    fout << "\n";
    std::cout << "\n";
    for(auto const& imap : all_names)
    {
        fout << imap << ",";
        std::cout << imap << ",";
        std::vector<DateAndHour> date = employees[imap];
        int count = 0;
        int ff = 0;
        for (auto const& i : dateList)
        {
            for(auto const& j : date)
            {
                auto pred = [i](const DateAndHour& item) {
                    return item.date == i;
                };
                auto q = std::find_if(std::begin(date), std::end(date), pred) != std::end(date);
                if (q)
                {
                    if (i == j.date)
                    {
                        if (count < dateList.size() - 1)
                        {
                            fout << j.hour << ",";
                            std::cout << j.hour << ",";
                            count++;
                        }
                        else
                        {
                            fout << j.hour;
                            std::cout << j.hour;
                        }
                    }
                }
                else
                {
                    //auto iter = date.cbegin();
                    DateAndHour dh{ i, "0" };
                    //date.emplace(date.cbegin() + count,dh);
                    date.push_back(dh);
                    if (i != j.date)
                    {
                        if (count < dateList.size() - 1)
                        {
                            fout << 0 << ",";
                            std::cout << 0 << ",";
                            count++;
                        }
                        else
                        {
                            fout << 0;
                            std::cout << 0;
                        }
                    }
                }

            }
            ff = 0;
        }
        fout << "\n";
        std::cout << "\n";
    }
    std::cout << "f";
}

