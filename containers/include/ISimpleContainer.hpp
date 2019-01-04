#ifndef ISIMPLECONTAINER_HPP
#define ISIMPLECONTAINER_HPP

#include <cstddef>

namespace medianabox {
namespace containers {

class ISimpleContainer
{
    public:
        virtual ~ISimpleContainer(){};
        virtual int get(std::size_t) const = 0;
        virtual void set(int, std::size_t) = 0;
        virtual void insert(int, std::size_t) = 0;
        virtual void push_back(int) = 0;
        virtual int& operator[](std::size_t)  = 0;
        virtual const int& operator[](std::size_t) const = 0;
        virtual std::size_t size() const = 0;
};

} // namespace containers
} // namespace medianabox

#endif /* ISIMPLECONTAINER_HPP */
