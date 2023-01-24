#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

FileIO file;

TEST(File_IO_tests, FileWriteTest)
{
    try
    {
        file.write_line("Hello, this is my write function");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        return;
    }
}
