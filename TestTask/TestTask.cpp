#include <iostream>
#include <fstream>
#include<string>

int main()
{
    std::ifstream csvReader("acme_worksheet.csv");
    std::string line;
    if (csvReader.is_open()) 
    {
        while (getline(csvReader, line))
        {
            std::cout << line << std::endl;
        }
    }
}
