#include <fstream>

#include "TestCalculator.hpp"
#include "../../containers/include/SimpleVec.hpp"

TestCalculator::TestCalculator() :
    calculator_(std::make_unique<medianabox::containers::SimpleVec>())
{}

TestCalculator::~TestCalculator() {}
void TestCalculator::SetUp() 
{
    testing::internal::CaptureStdout();
}

TEST_F(TestCalculator, ShouldWorksWithEmptyStream)
{
    std::string data;
    std::istringstream dataStream(data);

    dataStream >> calculator_;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("", output);
}

TEST_F(TestCalculator, ShouldWorksWithSimpleStringStream)
{
    std::string data("5 2 4 m q");
    std::istringstream dataStream(data);

    dataStream >> calculator_;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("4.0 ", output);
}

TEST_F(TestCalculator, ShouldWorksWithSimpleFileStream)
{
    std::ifstream dataStream;
    dataStream.open("testSimple.data");

    dataStream >> calculator_;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("4.0 ", output);
    dataStream.close();
}

TEST_F(TestCalculator, ShouldWorksWithExampleDataInString)
{
    std::string data("3 5 m 8 m 6 m q");
    std::istringstream dataStream(data);

    dataStream >> calculator_;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("4.0 5.0 5.5 ", output);
}

TEST_F(TestCalculator, ShouldWorksWithExampleDataInFile)
{
    std::ifstream dataStream;
    dataStream.open("testExample.data");

    dataStream >> calculator_;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ("4.0 5.0 5.5 ", output);
    dataStream.close();
}
