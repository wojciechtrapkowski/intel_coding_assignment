#include <iostream>
#include "data.hpp"
#include "serializer.hpp"
#include "verifier.hpp"
#include "tests.hpp"

int main(int argc, char** argv)
{
    // When doing serialization & deserialization I assumed that data is correctly formatted and didn't do any checks

    std::cout << "Test 1: " << (Task::Test1() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 2: " << (Task::Test2() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 3: " << (Task::Test3() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 4: " << (Task::Test4() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 5: " << (Task::Test5() ? "Passed" : "Failed") << std::endl;
    std::cout << "Test 6: " << (Task::Test6() ? "Passed" : "Failed") << std::endl;

    return 0;
}
