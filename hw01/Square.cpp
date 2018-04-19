/*************************************************************************
*
* HW01: Building a basic shape and square class to highlight C++ concepts.
*      - Polymorphism
*      - Inheritance
*      - Exception handling
*
* File Name:  Square.cpp
* Name:       Lucas Marcondes
* Course:     CPTR 242
* Date:       4/16/18
* Time Taken: ?
*
***************************************************************************/
#include "Square.h"

Square::Square() : Shape("Square")
{
}

int Square::getSideLength()
{
	return sideLength;
}

Square::Square(int l) : Shape("Square")
{
	if (l < 0)
	{
		throw NegativeLengthException();
	}
	else
		this->sideLength = l;
}

ostream& operator << (ostream& output, const Square & square)
{
	output << square.getName() << "(" << square.sideLength << ")";
	return output;
}
