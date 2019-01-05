add_executable(TestCalculator main.cpp TestCalculator.cpp)      

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/testSimple.data
    DESTINATION ${EXECUTABLE_OUTPUT_PATH})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/testExample.data
    DESTINATION ${EXECUTABLE_OUTPUT_PATH})

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