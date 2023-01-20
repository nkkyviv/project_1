#include <gtest/gtest.h>
#include <project.h>
#include <fstream>
#include <stdexcept>

/*
A task: write a function, which simplifies a full phone number:
- removes a code of the Country ( +46, +10, +1 .etc )
- removes possible dashes ( 999-999-99  -> 99999999)
- removes spaces in between numbers ( 99 99 -> 9999 )
*/
std::string SimplifyPhoneNumber(std::string phoneNumber)
{
    if (phoneNumber.empty())
    {
        return "ERROR";
    }
    return phoneNumber.substr(1);
}

TEST(PhoneNumberChecks, InputIsNotOutput)
{
    // input data
    std::string fakeNumber("+50 11 999 12-34");
    // expected value
    std::string expectedNumber("0119991234");
    // logic
    std::string output = SimplifyPhoneNumber(fakeNumber);
    // comparing results
    EXPECT_NE(fakeNumber, output);
}

TEST(PhoneNumberChecks, ReturnErrorOnEmptyString)
{
    std::string fakeNumber("");
    std::string expectedResult("ERROR");
    std::string output = SimplifyPhoneNumber(fakeNumber);
    EXPECT_EQ(output, expectedResult);
}

/*
 2. Read Lines (all content) From file,
    which doesn't exist, throws an Exception
*/
/*TEST(File_IO_tests, ExceptionIfFileDoesnExistOnRead)
{
    /* Your Input Data */
std::string non_existing_file("fake_text.txt");
{
    std::ifstream checkStream(non_existing_file);
    ASSERT_EQ(false, checkStream.is_open());
}
/* Your Expected Data */

File_IO file; // Your File_IO class from library
if (file.open(non_existing_file.c_str()))
{
    EXPECT_THROW(file.readLines(), std::runtime_error);
}

/* Your Logic of test case */

/* Assert / Equal/ Checking/ Comparing /etc. */
}
* /