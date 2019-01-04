#ifndef ICALCULATOR_HPP
#define ICALCULATOR_HPP

namespace medianabox {

class ICalculator
{
    public:
        virtual ~ICalculator(){};
        virtual void insert(int) = 0;
        virtual double calculate() const = 0;
};

} // medianabox

#endif /* ICALCULATOR_HPP */  
