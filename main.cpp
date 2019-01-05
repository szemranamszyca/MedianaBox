#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>

#include "core/include/Calculator.hpp"
#include "containers/include/SimpleVec.hpp"

int main()
{
    std::cout << "Welcome to MedianaBox!\n";

    medianabox::core::Calculator calc(std::make_unique<medianabox::containers::SimpleVec>());

    std::string dataString("3 5 m 8 m 6 m q");
    std::istringstream dataStream(dataString);

    std::cout << "Input data:\n"; 
    std::cout << dataString << '\n';
    std::cout << "Result for stringstream: \n"; 
    std::cout << "OUTPUT: ";
    dataStream >> calc;
    std::cout << '\n';

    std::ifstream dataFile;
    dataFile.open("example.data");
    std::cout << "Result for filestream: \n"; 
    std::cout << "OUTPUT: ";
    dataFile >> calc;
    std::cout << '\n';

    return 0;
}
