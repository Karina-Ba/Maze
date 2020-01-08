//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This class is made for a point in a maze's functions, including the character     //
// in that point, the row that is the height or the point and                        //
// the column that is the width of the point.                                        //
//***********************************************************************************//

#ifndef __POINT_
#define __POINT_

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996) 

class Point
{
private:
	char m_item;
	int  m_height;
	int  m_width;

public:
	 //C'tors
	 Point() = default;
	 Point(char item, int height = 0, int width = 0); 
	 //Default for the rest
	 Point(const Point& other) = default;
	 Point(Point&& other)      = default;
	~Point()                   = default;

	//Set functions
	void setItem   (char item);
	void setHeight (int height);
	void setWidth  (int width);

	//Get functions
	const char getItem   () const;
	const int  getHeight () const;
	const int  getWidth  () const;

	//Operators
	const Point& operator=(const Point& other);

};

#endif //__POINT_