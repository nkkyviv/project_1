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
