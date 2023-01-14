#include "project.h"
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    projects network;
    std::vector<string> vec;
    string str;
    std::cout << "Enter string!\n";
    do
    {
        std::cin >> str;
        vec.push_back(str);
    } while (str);
    std::cout << "my vector stores" << string(vec.size()) << "numbers.\n";
    return 0;
}