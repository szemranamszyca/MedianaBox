add_executable(TestSimpleVec main.cpp TestSimpleVec.cpp)      

target_link_libraries(
    TestSimpleVec
    SimpleVec
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestSimpleVec
COMMAND TestSimpleVec)