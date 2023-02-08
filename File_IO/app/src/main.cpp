#include "project.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    FileIO fileio("Vivian.txt");

    fileio.open(true);
    fileio.open(false);

    std::string write;
    std::cout << "Enter a line to be written:";
    std::getline(std::cin, write);

    fileio.write_line(write);

    fileio.read_line();

    std::vector<std::string> Inputs;
    std::string Input;
    std::cout << "Enter the Lines to be written in the file:" << std::endl;
    std::getline(std::cin >> ws, Input);

    Inputs.push_back(Input);
    for (int i = 0; i < Inputs.size(); i++)
        std::cout << "Strings in the container are: \n"
                  << Inputs[i] << std::endl;

    fileio.write_container(Inputs);

    std::vector<std::string> ReadLines = fileio.read_container();
    for (const auto &str : Inputs)
    {
        std::cout << str << std::endl;
    }

    fileio.close();

    return 0;
}