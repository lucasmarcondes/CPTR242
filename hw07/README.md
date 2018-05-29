# CPTR 242: Homework Assignment #7

## Problem Overview
Your task in this assignment is to implement __ancestors__ for a Binary Search Tree.
The function __ancestors__ prints the ancestors fo a given node whose _info_ member contains _value_.
Do not print value.
The __ancestors__ function must be implemented in three ways: iterative, recursive and reverse.
The problem is based on a book exercise (Chapter 8 Exercise 26, 27, 28).


## Solution Specifications

Your solution to this problem must meet the following criteria.


1. Implement the three versions of _ancestors_ for a linked implemenation in _ancestors.cpp_. 
   A stub of the function has been given to you.
```
void TreeType::AncestorsIterative(ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors iterative print
}

void PrintAncestorsRecursive(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors recursive print
}

void PrintAncestorsReverse(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    // TODO implement ancestors reverse print
}
```
2. Pass all the tests in Submitty.

## Test Driver

The book outlines a method of testing a list.
The submitty tests are based on this test driver.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

Each list implemenation has a unique name: SortedArray and SortedList.
A simple way to compile them is to list the cpp files after the g++ compiler.
You can run the test by executing the following:

```
g++ *.cpp & ./a.out
```


Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

