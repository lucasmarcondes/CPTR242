# CPTR 242: Homework Assignment #1

## Problem Overview
Your task in this assignment is to utilize inheritance, polymorphism and exception handling.

## Description

A _shape_ class has been given to you.
The class has member variable called __name__.
The constructor sets the name and an accessor allows others to view the value.

Your task is to create two new classes (circle and square) that inherit _shape_'s name member variable and accessor function.
Both _circle_ and _square_ have an additional member variable for _radius_ and _sideLength_, respectfully.

Next, you will include a thrown exception in the constructor for each class if the _radius_ or _sideLength_ is negative.
The _NegativeLengthExcpetion_ class has been given for you to use.

Finally, you will write a function to collect input form the user and create a circle.
Use the try catch framework to catch any exceptions for negative circle values.
If you get an exception, write a message to __cerr__ and ask the user to enter the radius again.
Use the submitty feedback to create error messages.

## Solution Specifications

Your solution to this problem must meet the following criteria.

1. Create _Circle_ which inherits _Shape_
2. Create _Square_ which inherits _Shape_
3. Add a throw statement to the constructor for negative values
4. Create a _getCircleFromUser()_ function that uses try catch to only return a circle with a positive radius.


## Submission

Your submission must include a _Circle.h_ and _Square.h_ file.
You may include other _.cpp_ files as necessary.
