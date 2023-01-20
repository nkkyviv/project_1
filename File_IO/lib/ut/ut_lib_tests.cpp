#include <gtest/gtest.h>
#include <project.h>

/*
Cover a case if we want to:
write a line into an empty file( file doesn't exist)
*/
/*TEST(File_IO_tests, WriteLineToEmptyFile)
{
    project file;
    bool isOpened = file.open("test.txt");

    EXPECT_EQ(isOpened, true);
    // EXPECT_THROW( file.close() , std::exception );
    //  more code to write to a file

    // read a file by C++ functions (for example: fread or ifstream)
    // compare the conent
}*/

/*
Links to read (not deeply, just to find right info) :
https://google.github.io/googletest/primer.html
https://google.github.io/googletest/reference/assertions.html
https://google.github.io/googletest/reference/testing.html
https://cplusplus.com/reference/exception/exception/exception/
*/

/*
 Rules for a Test Case:
 1. Input data (for example :filename, or text written)
    Should be defined as a variable
    OR
    written by C/C++ function (for example: fread, ifstream)
 2. Expected data (for example, text written) should be defined as a variable
    OR
    read by C/C++ function (for example: fread, ifstream),
 3. In the end of the testcase ( if a file was opened via C/C++ function)
    The file should be closed.
    TEST() {
        //file opened
        // test ...
        // file shouuld be closed
    }
*/

/* List of Test cases to implement:
1. Read Line From file, which doesn't exist,'
   throws an Exception
2. Read Lines (all content) From file,
   which doesn't exist, throws an Exception
3. Write Line to file, which doesn't exist, should create a file
4. Write Lines (all content) to file,
   which doesn't exist, should create a file
5. If file exists,
   Write Line to file should <...> (1 -> append OR 2-> override)
6. If file exists, Write Lines (all content)
   to file should <...> (1 -> append OR 2-> override)
7. if a user provided an empty string
   for filename -> throw an exception.
8. When we have finished to use File_IO component,
   the file should be closed. ( we can open it via C/C++ functions)
9. After "read" functions (if file doesn't exist) file should not exist.
*/

TEST(File_IO_tests, /* test case name ( or number from list above : N1 , N2)*/ N1)
{
   /* Your Input Data */

   /* Your Expected Data */

   project file; // Your File_IO class from library

   /* Your Logic of test case */

   /* Assert / Equal/ Checking/ Comparing /etc. */
}
