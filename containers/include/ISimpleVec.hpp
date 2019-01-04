#ifndef ISIMPLEVEC_HPP
#define ISIMPLEVEC_HPP

namespace medianabox {
namespace containers {

class ISimpleVec
{
    public:
        virtual int get(int) const = 0;
        virtual void set(int, int) = 0;
        virtual void insert(int, int) = 0;
        virtual void push_back(int) = 0;
        virtual int& operator[](int)  = 0;
        virtual const int& operator[](int) const = 0;
};

} // namespace containers
} // namespace medianabox

#endif /* ISIMPLEVEC_HPP */
