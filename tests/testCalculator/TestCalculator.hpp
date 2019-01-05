#ifndef TESTCALCULATOR_HPP
#define TESTCALCULATOR_HPP

#include "gtest/gtest.h"
#include "../../core/include/Calculator.hpp"

class TestCalculator : public ::testing::Test 
{
    protected:
        TestCalculator();
        virtual ~TestCalculator();
        virtual void SetUp();

        medianabox::core::Calculator calculator_;
};

#endif /* TESTCALCULATOR_HPP */
