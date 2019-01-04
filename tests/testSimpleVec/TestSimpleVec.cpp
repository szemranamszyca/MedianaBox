#include "TestSimpleVec.hpp"

TestSimpleVec::TestSimpleVec() {}
TestSimpleVec::~TestSimpleVec() {}
void TestSimpleVec::SetUp() {}

using namespace medianabox::containers;

TEST_F(TestSimpleVec, FirstTest)
{
    ASSERT_EQ(0, simpleVec_.get(1));
}