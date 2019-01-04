#include "TestSimpleVec.hpp"

TestSimpleVec::TestSimpleVec() {}
TestSimpleVec::~TestSimpleVec() {}
void TestSimpleVec::SetUp() {}

using namespace medianabox::containers;

TEST_F(TestSimpleVec, ShouldReturnSetElement)
{
    simpleVec_.set(3,0);
    ASSERT_EQ(3, simpleVec_.get(0));
}

TEST_F(TestSimpleVec, ShouldReturnSetElementUsingOperator)
{
    simpleVec_.set(3,0);
    ASSERT_EQ(3, simpleVec_[0]);
}

TEST_F(TestSimpleVec, ShouldPushBackAndReturnIt)
{
    simpleVec_.push_back(5);
    ASSERT_EQ(5, simpleVec_[0]);
}