# CPTR 242: Project #1

## Problem Overview
Your task in this project is to design and implement tests for __merging__ and __splitting__ Sorted Lists.
The __merge__ function takes two lists and returns a single list (Chapter 4 Exercise 4).
The __split__ function takes one list and an item then return two lists where the first list is less then item and the second is the rest of the list (Chapter 4 Exercise 8).


## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement __testMergeLists__ to test the client implemenation of __mergeLists__ in _testLists.cpp_. 
    A stub of the function has been given to you.
2. Implement __testSplitLists__ to test the client implemenation of __splitLists__ in _testLists.cpp_. 
    A stub of the function has been given to you.
. Pass all the tests in Submitty.


### Code Prototypes

Test Functions:
```c++
bool testMergeLists(SortedType list1, SortedType list2);
bool testSplitLists(SortedType list, ItemType item);
```

Functions being tested:
```c++
void mergeLists(SortedType list1, SortedType list2, SortedType& result);
void splitLists(SortedType list, ItemType item, SortedType& list1, SortedType& list2);
```

## Test Function

The test function will be passed sample input.
You should call the test function and pass these input into the function.
Then check to see if the results are correct.

Consider the input and the output to the functions to determine what is appropriate results.

## Compiling List Implementations

The tests are using a linked Sorted List, but the implementation should not affect your testings.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.
