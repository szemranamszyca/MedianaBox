#include <iostream>
#include <memory>
#include <sstream>

#include "include/Calculator.hpp"
#include "containers/include/SimpleVec.hpp"

int main()
{
    std::cout << "Welcome to MedianaBox!\n";

    medianabox::Calculator calc(std::make_unique<medianabox::containers::SimpleVec>());

    std::string data("5 2 4 m 43 24 m 2 m 42 q");
    std::istringstream dataStream(data);
    
    dataStream >> calc;

    return 0;
}
