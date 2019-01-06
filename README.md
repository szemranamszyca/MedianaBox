[![Build Status](https://travis-ci.org/szemranamszyca/MedianaBox.svg?branch=master)](https://github.com/szemranamszyca/MedianaBox)
[![codecov](https://codecov.io/gh/szemranamszyca/MedianaBox/branch/master/graph/badge.svg)](https://codecov.io/gh/szemranamszyca/MedianaBox)

# MedianaBox

## 1. Introduction
The goal of this project was to design and implement a simple solution to find a median element from given unsorted stream.

Median calculation might be triggered in any time by letter 'm' in stream; letter 'q' indicates the end of stream. Data are separated by single space ' '.

## 2. Installation
The simpliest way to compile and run the project is:
- clone repository to your local directory
- mkdir build
- cd build
- cmake ..
- make all
- ctest (to run all tests)

Now you can find compiled executable file in ../bin directory.

## 3. Usage example

You can find few examples in main.cpp file.

String stream:

```
std::string dataString("3 5 m 8 m 6 m q");    
std::istringstream dataStream(dataString);
```

or file stream

```
std::ifstream dataFile;  
dataFile.open("example.data");
```

Now, the only thing you need is just direct your stream into Calculator object:

```
dataStream >> calc; // output: 4.0 5.0 5.5   
dataStream >> calc; // output: 4.0 5.0 5.5
```

## 4. Design
The project consists of two elements:
* Class Calculator - responsible for reading values from stream, calculate the median value, and redirect result to standard output.
* Class SimpleVec - data storage for received values; implementation of interface class ISimpleContainer.

### 4.1 Class Calculator complexity
Critical place in this class is **Calculator::insert**.
When new value is received from stream, *Calculator* insert it into right place -- to keep SimpleVec sorted. This operation has linear complexity. Other operations are constant.

### 4.2 Class SimpleVec complexity
Here two places have O(N) complexity:
* *insert* - values needs to be moved to make place for new one)
* *increaseVecCapacity* - when size reaches the current capacity

Other operation are constant.

## 5. Comments
In this project, I tried to *obey* SOLID principles. Although, I'm aware that e.g. Calculator might be split to extra class which only responsibility should be reading from stream and another one - writing to output. Regarding to problem complexity, I've decided not to do it. Still, the class hierarchy is flat and based on interfaces.

Calculator is not depended on low-level class and we can inject any other container which implements ISimpleContainer interface.

Also, I tried work in TDD using gtest framework. However, one place might be controversial. While testing Calculator I used SimpleVec object, when the right approach is to make a ISimpleContainerMock and during the tests mocks all behaviours of containers. Again - it was compromised between project complexity and its simplicity.

All in all, I had a real fun during work on this recruitment task and I hope you'll like my solution!
