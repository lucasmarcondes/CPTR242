# CPTR 242: Homework Assignment #8

## Problem Overview
Your task in this assignment is to implement __reheap__ for a Priority Queue based on a heap.
The function __reheap__ functions have been implemented as a recursive function and you task is to 
write the equivalent function as an interative function.
The __reheap__ iterative function must be implemented in two ways: up, and down.
The problem is based on a book exercise (Chapter 9 Exercise 8).

Note the file you are using has the extention __tpp__.
This is because you are using a template and it must be include in the header file.
To help designate they difference between impelmentation and template, the extention has been changed.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Implement the two versions of _reheap_ for a linked implemenation in _reheap.tpp_. 
   A stub of the function has been given to you.
```
template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom)
{
// TODO Implement a Iterative ReheapDown Function.
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom)
{
// TODO Implement a Iterative ReheapUp Function.
}
```
2. Pass all the tests in Submitty.

## Test Driver

The book outlines a method of testing a list.
The submitty tests are based on this test driver.
It may be helpful to create your own test driver to validate your functions.

## Compiling List Implementations

A simple way to compile them is to list the cpp files after the g++ compiler.
You can run the test by executing the following:

```
g++ *.cpp & ./a.out
```


Remember you only need to list the cpp files and must be in the local directory.
Since the header files are in the same folder they are included in the _#include_ statement.

The sample files provided don't provide a main or driver function.
If you want to test, you will need to create one.

