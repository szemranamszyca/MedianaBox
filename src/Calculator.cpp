#include <iostream>

#include "../include/Calculator.hpp"

namespace medianabox {

Calculator::Calculator(std::unique_ptr<containers::ISimpleContainer> container) :
    container_(move(container))
{}

void Calculator::insert(int value)
{
    for(std::size_t i = 0; i < container_->size(); i++)
    {
        if (value < (*container_)[i])
        {
            container_->insert(value, i);
            return;
        }
    }
    container_->push_back(value);
}

double Calculator::calculate() const
{
    auto size = container_->size();
    if (size % 2 != 0)
    {
        return (*container_)[size/2];
    }
    else
    {
        return ((*container_)[size/2] + (*container_)[size/2-1])/2.0;
    }
}

void Calculator::dbgPrintMedianaBox()
{
    std::cout << "DEBUG PRINT: \n";
    for(std::size_t i = 0; i < container_->size(); ++i)
    {
        std::cout << (*container_)[i] << " ";
    }
    std::cout << '\n';
}
    
} // medianabox