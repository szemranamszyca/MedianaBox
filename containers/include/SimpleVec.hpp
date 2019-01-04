#ifndef SIMPLEVEC_HPP
#define SIMPLEVEC_HPP

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
        std::size_t size() const override;
    
    private:
        void increaseVecCapacity();
        int* vecData_;
        std::size_t vecSize_;
        std::size_t vecCapacity_;

};

} // namespace containers
} // namespace medianabox

#endif /* SIMPLEVEC_HPP */