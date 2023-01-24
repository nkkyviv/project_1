#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

FileIO network("Vivian.txt");
TEST(FileIOTest, TestWriteFunc)
{
    network.write_line("lineFunc");
    EXPECT_EQ(network.read_line(), "lineFunc");
}