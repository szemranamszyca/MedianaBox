[![Build Status](https://travis-ci.org/szemranamszyca/MedianaBox.svg?branch=master)](https://travis-ci.org/szemranamszyca/MedianaBox)
[![codecov](https://codecov.io/gh/szemranamszyca/MedianaBox/branch/master/graph/badge.svg)](https://codecov.io/gh/szemranamszyca/MedianaBox)

# MedianaBox

## 1. Introduction
The goal of this project was to design and implement a simple solution to find a median element from given unsorted stream.

Median calculation might be triggered in any time by the letter 'm' in stream; the letter 'q' indicates the end of stream. Data are separated by single space ' '.

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

Now, the only thing you need is to head your stream toward Calculator object:

```
dataStream >> calc; // output: 4.0 5.0 5.5   
dataStream >> calc; // output: 4.0 5.0 5.5
```

## 4. Design
The project consists of two elements:
* Class Calculator is responsible for reading values from stream, calculating the median value, and redirecting results to the standard output.
* Class SimpleVec is a data storage for received values; it implements interface class ISimpleContainer.

### 4.1 Class Calculator complexity
The critical place in this class is **Calculator::insert**.
When a new value is received from stream, *Calculator* inserts it into the right place -- to keep SimpleVec sorted. This operation has linear complexity. The other operations are constant.

### 4.2 Class SimpleVec complexity
There are two places which have O(N) complexity:
* *insert* method where values need to be moved to make place for new ones
* *increaseVecCapacity* method is called when the data storage size reaches the current capacity

The other operations are constant.

## 5. Comments
In this project, I've tried to actually *follow* the SOLID principles, although I'm aware of the fact that some classes (e.g. Calculator) should be split to extra classes.  One class should be only responsible for reading from stream, while another one - for writing to output. However, taking into account complexity of this problem, I've decided not to do it. Still, the class hierarchy is flat and based on interfaces.

Calculator does not depend on low-level classes. We can inject any other container which implements ISimpleContainer interface.

Also, I've tried to work in TDD using gtest framework. One fragment of my code might be controversial. While testing the Calculator, I used the SimpleVec object instead of making an ISimpleContainerMock. I'd like to stress that somehow this solution is a compromise between the project complexity and its simplicity.

All in all, I've had real fun fulfilling this task, and I hope you'll like my solution!

