add_executable(TestCalculator main.cpp TestCalculator.cpp)      

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/testSimple.data
    ${EXECUTABLE_OUTPUT_PATH} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/testExample.data
    ${EXECUTABLE_OUTPUT_PATH} COPYONLY)

target_link_libraries(
    TestCalculator
    Calculator
    SimpleVec
    libgtest
    libgmock
    test_warnings --coverage
)

add_test(NAME TestCalculator
COMMAND TestCalculator WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})