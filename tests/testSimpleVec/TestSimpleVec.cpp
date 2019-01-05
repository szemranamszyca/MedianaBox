#include "TestSimpleVec.hpp"

TestSimpleVec::TestSimpleVec() {}
TestSimpleVec::~TestSimpleVec() {}
void TestSimpleVec::SetUp() {}

using namespace medianabox::containers;

TEST_F(TestSimpleVec, ShouldReturnSetElement)
{
    simpleVec_.push_back(0);
    simpleVec_.set(3,0);
    ASSERT_EQ(3, simpleVec_.get(0));
}

TEST_F(TestSimpleVec, ShouldReturnSetElementUsingOperator)
{
    simpleVec_.push_back(0);
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

TEST_F(TestSimpleVec, ShouldInsertNewValueOnCorrectPlace)
{
    simpleVec_.push_back(5);
    simpleVec_.push_back(10);
    simpleVec_.push_back(15);
    simpleVec_.push_back(20);
    simpleVec_.push_back(25);
    ASSERT_EQ(5, simpleVec_.size());
    
    simpleVec_.insert(12, 2);
    EXPECT_EQ(10, simpleVec_[1]);
    EXPECT_EQ(12, simpleVec_[2]);
    EXPECT_EQ(15, simpleVec_[3]);
    EXPECT_EQ(25, simpleVec_[5]);
    ASSERT_EQ(6, simpleVec_.size());
}

TEST_F(TestSimpleVec, ShouldWorksCorectlyOnOneElement)
{
    simpleVec_.push_back(5);
    EXPECT_EQ(5, simpleVec_[0]);
    simpleVec_.insert(2, 0);
    EXPECT_EQ(2, simpleVec_[0]);
    EXPECT_EQ(5, simpleVec_[1]);
    ASSERT_EQ(2, simpleVec_.size());
}

TEST_F(TestSimpleVec, ShouldThrowIfGetIsOutOfRange)
{
    simpleVec_.push_back(5);
    ASSERT_THROW(simpleVec_.get(1), std::out_of_range);
}

TEST_F(TestSimpleVec, ShouldThrowIfSetIsOutOfRange)
{
    ASSERT_THROW(simpleVec_.set(3,0), std::out_of_range);
}