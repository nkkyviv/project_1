#ifndef PROJECT_H
#define PROJECT_H

class project
{
private:
    project(const project &) = delete;            // uncopyable
    project &operator=(const project &) = delete; // unassignable

public:
    project();
    ~project();

    void func1;
    void func2;
    void func3;
    void func4;
};
#endif