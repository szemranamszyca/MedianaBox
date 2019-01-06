#include <exception>
#include <iostream>
#include "../include/SimpleVec.hpp"

namespace medianabox {
namespace containers {

SimpleVec::SimpleVec() : 
    vecSize_(0),
    vecCapacity_(4)
{
    vecData_ = new int[vecCapacity_];
}

SimpleVec::SimpleVec(const SimpleVec& lhs)
{
    vecCapacity_ = lhs.vecCapacity_;
    vecSize_ = lhs.vecSize_;

    vecData_ = new int[vecCapacity_];
    for(int i = 0; i < vecSize_; i++)
    {
        vecData_[i] =  lhs.vecData_[i];
    }
}

SimpleVec::~SimpleVec()
{
    delete[] vecData_;
}

int SimpleVec::get(std::size_t index) const
{
    if (index >= vecSize_)
    {
        throw std::out_of_range("Range error");
    }

    return vecData_[index];
}

void SimpleVec::set(int value, std::size_t index)
{
    if (index >= vecSize_)
    {
        throw std::out_of_range("Range error");
    }

    vecData_[index] = value;
}

void SimpleVec::insert(int value, std::size_t index)
{
    if (index >= vecSize_)
    {
        throw std::out_of_range("Range error");
    }

    push_back(0);
    for(int i = vecSize_-1; i > index; i--)
    {
        vecData_[i] = vecData_[i-1];  
    }
    vecData_[index] = value;
}

void SimpleVec::push_back(int value)
{
    if (vecSize_ >= vecCapacity_)
    {
        increaseVecCapacity();
    }

    vecData_[vecSize_] = value;
    ++vecSize_;
}

int& SimpleVec::operator[](std::size_t index)
{
    if (index >= vecSize_)
    {
        throw std::out_of_range("Range error");
    }

    return vecData_[index];
}

const int& SimpleVec::operator[](std::size_t index) const 
{
    if (index >= vecSize_)
    {
        throw std::out_of_range("Range error");
    }
    
    return vecData_[index];
}

std::size_t SimpleVec::size() const
{
    return vecSize_;
}

void SimpleVec::increaseVecCapacity()
{
    int* newVecData = new int[2 * vecCapacity_];
    for(int i = 0; i < vecSize_; i++)
    {
        newVecData[i] = vecData_[i];
    }
    delete[] vecData_;
    vecData_ = newVecData;
    vecCapacity_ *= 2;
}

} // namespace containers
} // namespace medianabox
