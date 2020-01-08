//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This class is made for the dynamicstack and it's functions as we learned in class //
//***********************************************************************************//

#ifndef __STACK_
#define __STACK_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Point.h"
#include "Node.h"
using namespace std;

#pragma warning(disable: 4996)

class Stack
{
private:
	Node* m_top; //Pointer to the top node in stack

public:
	 //C'tor
	 Stack(const Point& point);
	 //D'tor
	~Stack();

	//Stack functions
	void  MakeEmpty ();
	bool  IsEmpty   ();
	void  Push      (Point& item);
	Point Pop       ();
	Point Top       ();
};


#endif // !__STACK_
