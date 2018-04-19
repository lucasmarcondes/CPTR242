/*************************************************************************
 *
 * HW01: Building a basic shape and square class to highlight C++ concepts.
 *      - Polymorphism
 *      - Inheritance
 *      - Exception handling
 * 
 * File Name:  Square.h
 * Name:       Lucas Marcondes
 * Course:     CPTR 242
 * Date:       4/16/18
 * Time Taken: ?
 * 
 **************************************************************************/
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "NegativeLengthException.h"

class Square : public Shape
{
private:
	int sideLength;
public:
	Square();
	Square(int l);
	int getSideLength();
	friend ostream& operator << (ostream& output, const Square & square);
};
#endif // SQUARE_H