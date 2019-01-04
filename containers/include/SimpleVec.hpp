#ifndef SIMPLEVEC_HPP
#define SIMPLEVEC_HPP

#include <cstddef>
#include "ISimpleVec.hpp"

namespace medianabox {
namespace containers {

class SimpleVec : public ISimpleVec
{
    public:
        SimpleVec();
        virtual ~SimpleVec();
        int get(int) const override;
        void set(int, int) override;
        void insert(int, int) override;
        void push_back(int) override;
        int& operator[](int)  override;
        const int& operator[](int) const override;
    
    private:
        int* vecData;
        std::size_t vecSize;
        std::size_t vecCapacity;

};

} // namespace containers
} // namespace medianabox

#endif /* SIMPLEVEC_HPP */