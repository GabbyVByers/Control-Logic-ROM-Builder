
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


int main()
{
	std::ifstream file("Lookup_Table.csv");
	std::string line;
	std::vector<std::string> lines;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    for (std::string& line : lines)
    {
        std::cout << line << "\n";
    }
}

