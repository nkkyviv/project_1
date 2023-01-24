#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <vector>
#include <fstream>

class FileIO
{
private:
    std::string FileName;
    std::ofstream Files;
    std::ifstream File;

public:
    FileIO(const std::string &FileName) : FileName(FileName) {}

    bool open();
    void write_line(const std::string &write);
    std::string read_line();
    std::vector<std::string> read_container();
    void write_container(const std::vector<std::string> &writecont);
    void close();

    ~FileIO() {}
};
#endif // FILE_IO_H