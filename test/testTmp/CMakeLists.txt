add_executable(TestTmp main.cpp TestTmp.cpp)      

target_link_libraries(
    TestTmp
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestTmp
COMMAND TestTmp)