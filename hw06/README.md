# CPTR 242: Homework Assignment #6

## Problem Overview
Your task in this assignment is to implement __minLoc__ and __sort__ for an Unsorted List.
The function __minLoc__ recursively searches for a smallest item in the list and returns its location.
The __sort__ function uses __minLoc__ to build a recursive sort function.
The problem is based on the book exercise we covered in class (Chapter 7 Exercise 21).


## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __minLoc__ for the linked implemenation in _minSort.cpp_. 
   A stub of the function has been given to you.
2. Implement __sort__ for the linked implemenation in _minSort.cpp_. 
   A stub of the function has been given to you.
   The sort must use __minLoc__ to perform the sort operation.
3. Pass all the tests in Submitty.

## Test Driver

The book outlines a method of testing a list.
The submitty tests are based on this test driver.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

Each list implemenation has a unique name: SortedArray and SortedList.
A simple way to compile them is to list the cpp after the g++ compiler.

```
g++ *.cpp
```

You can run the test by executing the following:

```
./a.out
```

The __listData.txt__ is an example test file that can be used when the test driver requests an input file.

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

