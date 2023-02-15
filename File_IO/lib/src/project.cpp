#include "project.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

FileIO::FileIO(const std::string &FileName) : FileName(FileName) {}

bool FileIO::open(bool write = false)
{
    bool status{false};

    if (write)
    {
        Files.open(FileName, ios::out);
        if (Files.is_open())
        {
            std::cout << "File opened" << std::endl;
            status = true;
        }
    }
    else
    {
        File.open(FileName, ios::in);
        if (File.is_open())
        {
            std::cout << "File opened" << std::endl;
            status = true;
        }
    }
    return status;
}

void FileIO::write_line(const std::string &write)
{
    open(true);
    if (!Files)

    {
        throw std::runtime_error("Error: file does not exist");
    }
    Files << write << std::endl;
}
std::string FileIO::read_line()
{
    open(false);
    if (!File)

    {
        throw std::runtime_error("Error: file does not exist");
    }

    string data;
    getline(File, data);

    return data;
}

std::vector<std::string> FileIO::read_container()
{
    open(false);
    const int bufferSize = 256;
    std::vector<std::string> vec;
    while (File.good())
    {
        char buffer[bufferSize] = {0};
        File.getline(buffer, bufferSize - 1);
        vec.emplace_back(buffer);
    }
    return vec;
}

void FileIO::write_container(std::vector<std::string> writecont)
{
    open(true);
    for (std::string Lines : writecont)
    {
        Files << Lines << std::endl;
    }
}

void FileIO::close()
{
    File.close();
    Files.close();
    std::cout << "File closed" << std::endl;
}