//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This class is made for the static queue and it's functions as we learned in class //
//***********************************************************************************//

#ifndef __QUEUE_
#define __QUEUE_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Point.h"
using namespace std;

#pragma warning(disable: 4996)


class Queue
{
private:
	int     m_head;   //Start of array
	int     m_tail;  //End of array
	Point*  m_data; //Array of points
	int     m_size;//Array size
	
	int AddOne(int x) ; //Function adds one to x for check purposes

public:
	 //C'tor
	 Queue (const Point& start, const int size = (MAX_COL * MAX_ROW));
	 //D'tor
	~Queue () { delete[] m_data; };

	//Queue functions
	void  MakeEmpty ();
	bool  IsEmpty   ();
	Point Front     ();
	void  EnQueue   (const Point& item);
	Point DeQueue   ();

	static const int MAX_COL = 80;
	static const int MAX_ROW = 25;
};


#endif // !__QUEUE_
