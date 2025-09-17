
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>


int main()
{
	std::ifstream file("Lookup_Table.csv");
	std::string line;
	std::vector<std::string> lines;


    // Load "address,value" lines from Lookup_Table.csv
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    std::cout << "num lines: " << lines.size() << "\n\n";
    for (std::string& line : lines)
    {
        std::cout << line << "\n";
    }

    // Remove "address," from "address,value"
    for (std::string& line : lines)
    {
        while (true)
        {
            if (line[0] == ',')
            {
                break;
            }

            line.erase(0, 1);
        }

        line.erase(0, 1);
    }

    std::cout << "\n";
    for (std::string& line : lines)
    {
        std::cout << line << "\n";
    }

    // Convert "value" to unsigned int;
    std::vector<unsigned int> values;
    assert(sizeof(unsigned int) == sizeof(unsigned long));
    for (std::string& line : lines)
    {
        unsigned int value = (unsigned int)std::stoul(line);
        values.push_back(value);
    }

    std::cout << "\n";
    for (unsigned int value : values)
    {
        std::cout << (unsigned)value << "\n";
    }

    // Write to binary file
    std::ofstream out("ControlRom.bin", std::ios::binary);
    out.write(reinterpret_cast<const char*>(values.data()), values.size() * sizeof(unsigned int));
    out.close();

    return 0;
}

