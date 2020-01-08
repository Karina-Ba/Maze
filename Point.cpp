#include "Point.h"

//-------------------------------------------------------------//
//C'tor
Point::Point(char item, int height, int width)
{
	this->setItem   (item  );
	this->setHeight (height);
	this->setWidth  (width );
}
//-------------------------------------------------------------//
//Set functions
void Point::setItem(char item)
{
	this->m_item = item;;
}
//-------------------------------------------------------------//
void Point::setHeight(int height)
{
	this->m_height = height;
}
//-------------------------------------------------------------//
void Point::setWidth(int width)
{
	this->m_width = width;
}
//-------------------------------------------------------------//
//Get functions
const char Point::getItem() const
{
	return this->m_item;
}
//-------------------------------------------------------------//
const int Point::getHeight() const
{
	return this->m_height;
}
//-------------------------------------------------------------//
const int Point::getWidth() const
{
	return this->m_width;
}
//-------------------------------------------------------------//
//Operators
const Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		this->m_item   = other.m_item;
		this->m_width  = other.m_width;
		this->m_height = other.m_height;
	}

	return *this;
}
//-------------------------------------------------------------//