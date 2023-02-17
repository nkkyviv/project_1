#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

// Write Line to file, which doesn't exist, should create a file
TEST(File_IO_Tests, NewFileCreated)
{
    const std::string file_name = "New_file.txt";
    const std::string expected_text = "Hello, world!";

    std::ofstream file(file_name);
    file << expected_text << std::endl;
    file.close();

    // Assert
    std::ifstream read_file(file_name);
    std::string actual_text;
    getline(read_file, actual_text);
    read_file.close();

    EXPECT_EQ(actual_text, expected_text);
}

// if a user provided an empty string for filename->throw an exception.'
TEST(File_IO_tests, EmptyFileWriteLine)
{
    FileIO file_m(" ");
    std::string text = "Hello";

    try
    {
        file_m.write_line(text);
    }
    catch (const std::runtime_error &e)
    {
        assert(std::string(e.what()) == "Error: file does not exist");
    }
}
