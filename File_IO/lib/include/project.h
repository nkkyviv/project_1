#ifndef PROJECT_H
#define PROJECT_H
#include <string>

class project
{

public:
    project();
    ~project();

    void open();
    int write_line();
    void read_line();
    void read_container();
    void write_container();
    void close();
};
#endif // FILE_IO_H