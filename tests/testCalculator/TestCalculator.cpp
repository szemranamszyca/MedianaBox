#include "TestCalculator.hpp"
#include "../../containers/include/SimpleVec.hpp"

TestCalculator::TestCalculator() :
    calculator_(std::make_unique<medianabox::containers::SimpleVec>())
{}

TestCalculator::~TestCalculator() {}
void TestCalculator::SetUp() {}

using namespace medianabox;

TEST_F(TestCalculator, FirstTest)
{
    ASSERT_TRUE(true);
}
