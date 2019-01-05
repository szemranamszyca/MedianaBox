#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <memory>
#include "ICalulator.hpp"
#include "../../containers/include/ISimpleContainer.hpp"

namespace medianabox {
namespace core {

class Calculator : public ICalculator
{ 
public:
    Calculator(std::unique_ptr<containers::ISimpleContainer>);

    void insert(int) override;
    double calculate() const override;
    // void dbgPrintMedianaBox();

    friend std::istream& operator>>(std::istream& in, const Calculator& lhs);
    
    private:
        std::unique_ptr<containers::ISimpleContainer> container_; 
};

std::istream& operator>>(std::istream& input, Calculator& calculator);

} // core
} // medianabox

#endif /* CALCULATOR_HPP */
