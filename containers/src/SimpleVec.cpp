#include "../include/SimpleVec.hpp"

namespace medianabox {
namespace containers {

SimpleVec::SimpleVec() : 
    vecSize_(0),
    vecCapacity_(4)
{
    vecData_ = new int[vecCapacity_];
}

SimpleVec::~SimpleVec()
{
    delete[] vecData_;
}

int SimpleVec::get(int i) const
{
    return vecData_[i];
}

void SimpleVec::set(int value, int index)
{
    vecData_[index] = value;
}

void SimpleVec::insert(int value, int index)
{}

void SimpleVec::push_back(int value)
{
    vecData_[vecSize_] = value;
}

int& SimpleVec::operator[](int index)
{
    return vecData_[index];
}

const int& SimpleVec::operator[](int index) const 
{
    return vecData_[index];
}

std::size_t SimpleVec::size() const
{
    return vecSize_;
}



} // namespace containers
} // namespace medianabox
