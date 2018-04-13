# CPTR 242: Homework Assignment #2

## Problem Overview
Your task in this assignment is to implement a new function for an Unsorted List.
The function __IsThere__ searches for a key and return a true when the key is found.
You must write the __IsThere__ function for both array and linked implementation for the list.
The problem is based on the book exercise we covered in class (Chapter 3 Exercise 1).


## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __IsThere__ for the array implemenation in _IsThereArray.cpp_. A stub of the function has been given to you.
2. Implement __IsThere__ for the linked implemenation in _IsThereLinked.cpp_. A stub of the function has been given to you.
3. Pass all the tests in Submitty.


## Files

Array implementation files:
* IsThereArray.cpp
* ItemType.cpp
* ItemType.h
* UnsortedArray.cpp
* UnsortedArray.h


Linked implementation files:
* IsThereLinked.cpp
* ItemType.cpp
* ItemType.h
* UnsortedList.cpp
* UnsortedList.h

## Test Driver

The book outlines a method of testing a list.
The submitty tests are based on this test driver.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

Each list implemenation has a unique name: UnsortedArray and UnsortedList.
A simple way to compile them is to list the cpp after the g++ compiler.

```
g++ IsThereArray.cpp ItemType.cpp UnsortedArray.cpp
```

Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

