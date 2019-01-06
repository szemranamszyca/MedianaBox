#include <iostream>
#include <memory>
#include <sstream>
#include <fstream>

#include "core/include/Calculator.hpp"
#include "containers/include/SimpleVec.hpp"


// FOR MEDIANABOX2
// #include <vector>
// #include <iomanip>
// #include <algorithm>

// class MedianaBox2
// {
//     public:
//     void process(std::istream& input)
//     {
//         std::string streamValue;
//         while(getline(input, streamValue, ' ')) 
//         {
//             if (streamValue == "m")
//             {
//                 std::cout << std::setprecision(1) << std::fixed << calculate() << ' ';
//             }
//             else if (streamValue == "q")
//             {
//                 return;
//             }
//             else
//             {
//                 data_.push_back(std::stoi(streamValue));
//             }
//         } 
//     }

//     private:
//         double calculate()
//         {
//             std::sort(data_.begin(), data_.end());
//             auto size = data_.size();
//             if (size % 2 != 0)
//             {
//                 return data_[size/2];
//             }
//             else
//             {
//                 return (data_[size/2] + data_[size/2-1])/2.0;
//             }
//         }
//         std::vector<int> data_;
// };


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
