#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

// testing the Readlines(read container) function
TEST(File_IO_tests, WriteAndReadTest)
{
    FileIO file_m("Vivian.txt");
    // Open the file
    ASSERT_TRUE(file_m.open(true)); // Make sure the file is opened successfully

    // Write some lines to the file
    std::vector<std::string> inputs = {"Hello", "World", "How are you?"};
    file_m.write_container(inputs);

    // Close the file
    file_m.close();

    file_m.open(false);
    std::vector<std::string> read_lines = file_m.read_container();

    for (size_t index = 0; index < inputs.size(); ++index)
        for (auto line : read_lines)
        {
            std::cout << line << std::endl;
            EXPECT_EQ(line, inputs[index]);
        }
    file_m.close();
}

// Read a line from a non existing file
TEST(File_IO_tests, NoneExistingFileReadLine)
{
    FileIO file_m("nonexistent_file.txt");

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
    FileIO file_m("nonexistent_file.txt");
    try
    {
        file_m.read_container();
    }
    catch (const std::runtime_error &e)
    {
        assert(std::string(e.what()) == "Error: file does not exist");
    }
}
