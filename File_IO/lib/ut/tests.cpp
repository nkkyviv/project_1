#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>
FileIO file_m("Vivian.txt");

TEST(File_IO_tests, FileWriteTest)
{
    try
    {
        file_m.write_line("Hello, this is my write function");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        return;
    }
}

/*
 2. Read Lines (all content) From file,
    which doesn't exist, throws an Exception
*/
TEST(File_IO_tests, ExceptionIfFileDoesnExistOnRead)
{
    /* Your Input Data */
    std::string non_existing_file("fake_text.txt");
    {
        std::ifstream checkStream(non_existing_file);
        ASSERT_EQ(false, checkStream.is_open());
    }
    /* Your Expected Data */

    if (file_m.open())
    {
        EXPECT_THROW(file_m.read_line(), std::runtime_error);
        EXPECT_THROW(file_m.read_container(), std::runtime_error);
    }

    /* Your Logic of test case */

    /* Assert / Equal/ Checking/ Comparing /etc. */
}
