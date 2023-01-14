#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>

class projects
{
private:
    projects(const projects &) = delete;            // uncopyable
    projects &operator=(const projects &) = delete; // unassignable

public:
    projects() { cout << "constructor called"; }

    void func1() { std::cout << "Function 1 created" << std::endl; }
    void func2() { std::cout << "Function 2 created" << std::endl; }
    void func3() { std::cout << "Function 3 created" << std::endl; }
    void func4() { std::cout << "Function 4 created" << std::endl; }

    ~projects() { cout << "Destructor called"; }
};
#endif