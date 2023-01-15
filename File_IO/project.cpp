#include "project.h"
#include <iostream>
using namespace std;

project::project() { std::cout << "constructor called"; }
project::~project() { std::cout << "Destructor called"; }

void project::func1()
{
    std::cout << "Function 1 is called" << std::endl;
}
void project::func2()
{
    std::cout << "Function 2 is called" << std::endl;
}
void project::func3()
{
    std::cout << "Function 3 is called" << std::endl;
}
void project::func4()
{
    std::cout << "Function 4 is called" << std::endl;
}
