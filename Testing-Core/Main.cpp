#include "Test.hpp"
#include "TestsCommon.hpp"

// using -v will enable verbose mode 1, -vv will enable verbose mode 2
// using -f [test file name] will run only tests in a given test file.
// using -f [test file name] -t [test name] will only run the given test.

// Example invocations:
// Test.exe
// Test.exe -v
// Test.exe -vv -f example_tests
// Test.exe -f example_tests
// Test.exe -vv -f example_tests -t example_test2

int main( int a_Count, const char** a_Args )
{
    return Testing::ParseArguments( a_Count - 1, a_Args + 1 );
}