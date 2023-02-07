#include "project.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

FileIO::FileIO(const std::string &FileName) : FileName(FileName) {}

bool FileIO::open()
{
    bool status{false};

    Files.open(FileName, ios::out | ios::in | ios::app);
    File.open(FileName, ios::out | ios::in | ios::app);
    if (Files.is_open() && File.is_open())
    {
        std::cout << "File is opened" << std::endl;

        status = true;
    }
    return status;
}

void FileIO::write_line(const std::string &write)
{
    Files.open(FileName);
    Files << "My file has a content" << std::endl;
}
std::string FileIO::read_line()
{
    string data;
    File.open(FileName);
    getline(File, data);

    return data;
}

std::vector<std::string> FileIO::read_container()
{
    std::vector<std::string> vec;
    std::string str;
    while (getline(File, str))
    {
        vec.push_back(str); // push all contents of the file to the container
    }
    return vec;
}

void FileIO::write_container(const std::vector<std::string> &writecont)
{
    for (const auto &write : writecont)
    {
        Files << write << std::endl;
    }
}

void FileIO::close()
{
    File.close();
    Files.close();
    std::cout << "File closed" << std::endl;
}