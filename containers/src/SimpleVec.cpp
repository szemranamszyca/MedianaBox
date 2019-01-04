#include "../include/SimpleVec.hpp"

namespace medianabox {
namespace containers {

SimpleVec::SimpleVec() : 
    vecSize(0),
    vecCapacity(4)
{}

SimpleVec::~SimpleVec()
{}


int SimpleVec::get(int i) const
{
    return 0;
}

void SimpleVec::set(int value, int i)
{}

void SimpleVec::insert(int value, int place)
{}

void SimpleVec::push_back(int value)
{}

int& SimpleVec::operator[](int i)
{
    int tmp = 0;
    return tmp;
}

const int& SimpleVec::operator[](int i) const 
{
    return 0;
}


} // namespace containers
} // namespace medianabox
