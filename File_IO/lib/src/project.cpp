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
    Files << "My file has a content" << std::endl;
}
std::string FileIO::read_line()
{
    open(false);
    string data;
    getline(File, data);

    return data;
}

std::vector<std::string> FileIO::read_container()
{
    open(false);
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
    open(true);
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