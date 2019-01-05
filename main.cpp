#include <iostream>
#include <memory>
#include <sstream>

#include "include/Calculator.hpp"
#include "containers/include/SimpleVec.hpp"


class Controller
{
    public:
    Controller() : calculator_(std::make_unique<medianabox::containers::SimpleVec>())
    {}

    void addData(int value)
    {
        calculator_.insert(value);
    }
    double result() const
    {
        return calculator_.calculate();
    }

    friend std::istream& operator>>(std::istream& in, const Controller& lhs);

    private:
        medianabox::Calculator calculator_;
};


std::istream& operator>>(std::istream& input, Controller& controller)
{
    std::string inter;
    while(getline(input, inter, ' ')) 
    { 
        if (inter == "m")
        {
            std::cout << "Mediana is equal: " <<controller.result() << '\n';
        }
        else if (inter == "q")
        {
            std::cout << "END!" << '\n';
        }
        else
        {
            controller.addData(std::stoi(inter));
        }
    } 
    return input;
}

int main()
{
    std::cout << "Welcome to MedianaBox!\n";

    Controller control;
    std::string data("5 2 4 m 43 24 m 2 m 42 q");
    std::istringstream dataStream(data);
    
    dataStream >> control;

    return 0;
}
