#ifndef ICALCULATOR_HPP
#define ICALCULATOR_HPP

namespace medianabox {
namespace core {

class ICalculator
{
    public:
        virtual ~ICalculator(){};
        virtual void insert(int) = 0;
        virtual double calculate() const = 0;
};

} // core
} // medianabox


#endif /* ICALCULATOR_HPP */  
