#ifndef TESTSIMPLEVEC_HPP
#define TESTSIMPLEVEC_HPP

#include "gtest/gtest.h"
#include "../../containers/include/SimpleVec.hpp"

class TestSimpleVec : public ::testing::Test 
{
    protected:
        TestSimpleVec();
        virtual ~TestSimpleVec();
        virtual void SetUp();

        medianabox::containers::SimpleVec simpleVec_;
};

#endif /* TESTSIMPLEVEC_HPP */