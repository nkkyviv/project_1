#include "project.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

project::project() {}
project::~project() {}

bool project::open()
{
    fstream repFile;
    bool status{false};

    repFile.open("Vivian.txt", ios::out);
    if (repFile.is_open())
    {
        std::cout << "File is opened" << std::endl;
        status = true;
    }
    return false;
}
void project::close()
{
    fstream repFile;
    repFile.close();
    std::cout << "File is closed " << std::endl;
}

int project::write_line()
{
    ofstream repFile("Vivian.txt");
    repFile << "My file has a content";

    return 0;
}
void project::read_line()
{
    ifstream repFile("Vivian.txt", ios::in);
    string data[1];
    int num;
    std::cout << "specify line of file:" << std::endl;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        getline(repFile, data[0]);
        std::cout
            << "This is the text in "
            << "line" << i + 1 << "::" << data[i] << std::endl;
    }
}

void project::read_container()
{
    std::ifstream repFile("Vivian.txt");
    std::vector<std::string> vec;
    std::string str;
    while (repFile >> str)
    {
        vec.push_back(str); // push all contents of the file to the container
    }
    copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n")); // to print the container of the vector
}

void project::write_container()
{
    std::vector<std::string> vec;
    std::string str;
    cout << "Enter string:\n";
    std::getline(std::cin >> ws, str);

    vec.push_back(str);
    for (int i = 0; i < vec.size(); i++)
        std::cout << "Strings in the container are: \n"
                  << vec[i] << std::endl;
}