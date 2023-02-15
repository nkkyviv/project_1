#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

FileIO file_m("Vivian.txt");
// testing the Readlines(read container) function
TEST(File_IO_tests, FileReadLinesTest)
{
    file_m.open(false);
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
// testing the write container function
TEST(File_IO_tests, OpenAndCloseTest)
{
    // Open the file
    ASSERT_TRUE(file_m.open(true)); // Make sure the file is opened successfully

    // Write some lines to the file
    std::vector<std::string> inputs = {"Hello", "World", "How are you?"};
    file_m.write_container(inputs);

    // Close the file
    file_m.close();
}

// Read a line from a non existing file
TEST(File_IO_tests, NoneExistingFileReadLine)
{
    std::string non_existing_file("nonexistent_file.txt");
    try
    {
        file_m.read_line();
    }
    catch (const std::runtime_error &e)
    {
        assert(std::string(e.what()) == "Error: file does not exist");
    }
}
// Read lines(all content) from a file which doesn't exists
TEST(File_IO_tests, NoneExistingFileReadlines)
{
    std::string non_exiting_file("nonexistent_file.txt");
    try
    {
        file_m.read_container();
    }
    catch (const std::runtime_error &e)
    {
        assert(std::string(e.what()) == "Error: file does not exist");
    }
}
