/*************************************************************************
 *
 * Implementation of the Shape class.
 * Part of HW01 assignment for CPTR242.
 * 
 * File Name:  Shape.cpp
 * Course:     CPTR 242
 * 
 * Provided Code...
 */

#include <iostream>
#include "Shape.h"
using namespace std;

Shape::Shape() {
    this->name = "Shape";
}

Shape::Shape(string name) {
    this->name = name;
}

string Shape::getName() const {
    return name;
}

ostream& operator << (ostream& output, const Shape & shape) {
    output << shape.getName();
    return output;
}
