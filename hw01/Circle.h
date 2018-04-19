/*************************************************************************
 *
 * HW01: Building a basic shape and square class to highlight C++ concepts.
 *      - Polymorphism
 *      - Inheritance
 *      - Exception handling
 * 
 * File Name:  Circle.h
 * Name:       Lucas Marcondes
 * Course:     CPTR 242
 * Date:       4/16/18
 * Time Taken: ?
 * 
 ***************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "NegativeLengthException.h"

class Circle : public Shape
{
private:
	int radius;
public:
	Circle(int r);
	Circle();
	int getRadius();
	friend ostream& operator << (ostream& output, const Circle & circle);
};

Circle getCircleFromUser();

#endif // CIRCLE_H