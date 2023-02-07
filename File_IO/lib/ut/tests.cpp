#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

FileIO file_m("Vivian.txt");
/*
 2. Read Lines (all content) From file,
    which doesn't exist, throws an Exception
*/

TEST(File_IO_tests, FileWriteLinesTest)
{
    file_m.open();
    std::vector<std::string> write_lines = {"testing my write lines function", "for my FileIO component"};
    file_m.write_container(write_lines);
    int i = 0;
    std::vector<std::string> read_lines = file_m.read_container();
    for (auto input : read_lines)
    {
        std::cout << input << std::endl;
        EXPECT_EQ(input, read_lines[i]);
        i++;
    }
    file_m.close();
}
