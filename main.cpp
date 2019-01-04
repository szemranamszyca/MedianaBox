#include <iostream>
#include <memory>

#include "containers/include/SimpleVec.hpp"

class ICalculator
{
    public:
        virtual ~ICalculator(){};
        virtual void insert(int) = 0;
        virtual double calculate() = 0;
};

class Calculator : public ICalculator
{ 
public:
    Calculator(std::unique_ptr<medianabox::containers::ISimpleContainer> container) :
        container_(move(container))
    {}
    void insert(int value) override
    {
        if (container_->size() == 0)
        {
            container_->push_back(value);
        }
        else
        {
            for(std::size_t i = 0; i < container_->size(); i++)
            {
                if (value < (*container_)[i])
                {
                    container_->insert(value, i);
                    return;
                }
            }
            container_->push_back(value);
        }
    }

    double calculate() override
    {
        return 1.0;
    }

    void dbgPrintMedianaBox()
    {
        std::cout << "DEBUG PRINT: \n";
        for(std::size_t i = 0; i < container_->size(); ++i)
        {
            std::cout << (*container_)[i] << " ";
        }
        std::cout << '\n';
    }
    
    private:
        std::unique_ptr<medianabox::containers::ISimpleContainer> container_; 
};

int main()
{
    std::cout << "Welcome to MedianaBox!\n";
    Calculator mb(std::make_unique<medianabox::containers::SimpleVec>());
    mb.insert(5);
    mb.insert(2);
    mb.insert(8);
    mb.dbgPrintMedianaBox();
    mb.insert(1);
    mb.insert(54);
    mb.insert(23);
    mb.dbgPrintMedianaBox();

    return 0;
}
