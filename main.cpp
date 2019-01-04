#include <iostream>
#include <memory>

#include "include/Calculator.hpp"
#include "containers/include/SimpleVec.hpp"

int main()
{
    std::cout << "Welcome to MedianaBox!\n";
    medianabox::Calculator mb(std::make_unique<medianabox::containers::SimpleVec>());
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
