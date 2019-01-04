#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <memory>
#include "ICalulator.hpp"
#include "../containers/include/ISimpleContainer.hpp"

namespace medianabox {

class Calculator : public ICalculator
{ 
public:
    Calculator(std::unique_ptr<containers::ISimpleContainer>);

    void insert(int) override;
    double calculate() const override;
    void dbgPrintMedianaBox();
    
    private:
        std::unique_ptr<containers::ISimpleContainer> container_; 
};
    
} // medianabox

#endif /* CALCULATOR_HPP */
