add_executable(TestCalculator main.cpp TestCalculator.cpp)      

target_link_libraries(
    TestCalculator
    Calculator
    SimpleVec
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestCalculator
COMMAND TestCalculator)