#include <iostream>
#include "containers/include/SimpleVec.hpp"

class IMedianaBox
{
    public:
        virtual ~IMedianaBox(){};
        virtual void insert(int) = 0;
        virtual double calculate() = 0;
};

class MedianaBox : public IMedianaBox
{
public:
    void insert(int value) override
    {
        if (container_.size() == 0)
        {
            container_.push_back(value);
        }
        else
        {
            for(std::size_t i = 0; i < container_.size(); i++)
            {
                if (value < container_[i])
                {
                    container_.insert(value, i);
                    return;
                }
            }
            container_.push_back(value);
        }
    }

    double calculate() override
    {
        return 1.0;
    }

    void dbgPrintMedianaBox()
    {
        std::cout << "DEBUG PRINT: \n";
        for(std::size_t i = 0; i < container_.size(); ++i)
        {
            std::cout << container_[i] << " ";
        }
        std::cout << '\n';
    }
    
    private:
        medianabox::containers::SimpleVec container_; 
};

int main()
{
    std::cout << "Welcome to MedianaBox!\n";
    MedianaBox mb;
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
