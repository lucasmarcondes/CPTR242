/*************************************************************************
*
* HW01: Building a basic shape and square class to highlight C++ concepts.
*      - Polymorphism
*      - Inheritance
*      - Exception handling
*
* File Name:  Circle.cpp
* Name:       Lucas Marcondes
* Course:     CPTR 242
* Date:       4/16/18
* Time Taken: ?
*
*/
#include "Circle.h"

Circle::Circle() : Shape("Circle")
{

}

int Circle::getRadius()
{
	return radius;
}

Circle::Circle(int r) : Shape("Circle") 
{
	if (r < 0)
		throw NegativeLengthException();
	else
		this->radius = r;
}

Circle getCircleFromUser()
{
	Circle c;
	int r;
	cout << "Enter the size of the circle: ";
	cin >> r;
		try
		{
			c = Circle(r);
		}
		catch (NegativeLengthException& n)
		{
			cerr << "Input Error: " << n.what();
			c = getCircleFromUser();
		}
	return c;
}

ostream& operator << (ostream& output, const Circle & circle)
{
	output << circle.getName() << "(" << circle.radius << ")";
	return output;
}
