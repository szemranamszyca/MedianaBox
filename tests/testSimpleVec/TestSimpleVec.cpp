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

TEST_F(TestSimpleVec, ShouldReturnCorrectSize)
{
    simpleVec_.push_back(5);
    ASSERT_EQ(1, simpleVec_.size());
    
    simpleVec_.push_back(10);
    simpleVec_.push_back(15);
    ASSERT_EQ(3, simpleVec_.size());
}

TEST_F(TestSimpleVec, ShouldAddMoreValues)
{
    simpleVec_.push_back(5);
    simpleVec_.push_back(10);
    simpleVec_.push_back(15);
    simpleVec_.push_back(20);
    simpleVec_.push_back(25);
    ASSERT_EQ(5, simpleVec_.size());
    ASSERT_EQ(10, simpleVec_[1]);
    ASSERT_EQ(25, simpleVec_[4]);
}