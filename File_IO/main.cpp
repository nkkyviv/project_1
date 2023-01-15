#include "project.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(void)
{
    project network;

    std::vector<std::string> vec;
    std::string str;

    std::cout << "Enter string!\n";
    cin >> str;
    vec.push_back(str);
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << "my string" << vec[i] << "numbers.\n";
    }
    fstream rep_File;
    rep_File.open("Vivian.txt", ios::in);
    if (!rep_File)
    {
        cout << "File not created";
    }
    else
    {
        cout << "File is created";
        rep_File.close();
    }

    return 0;
}