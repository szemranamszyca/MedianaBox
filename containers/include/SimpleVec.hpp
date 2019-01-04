#ifndef SIMPLEVEC_HPP
#define SIMPLEVEC_HPP

#include "ISimpleContainer.hpp"

namespace medianabox {
namespace containers {

class SimpleVec : public ISimpleContainer
{
    public:
        SimpleVec();
        virtual ~SimpleVec();
        int get(std::size_t) const override;
        void set(int, std::size_t) override;
        void insert(int, std::size_t) override;
        void push_back(int) override;
        int& operator[](std::size_t)  override;
        const int& operator[](std::size_t) const override;
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