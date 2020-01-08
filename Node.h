//***********************************************************************************//
// Karina Batmanishvili - 321800898.                                                 //
// This class is made for the single node and it's functions as we learned in class  //
//***********************************************************************************//

#ifndef __NODE_
#define __NODE_

#include <iostream>
#include "Point.h"
using namespace std;

#pragma warning(disable: 4996)

class Node
{
public:
	Node* m_next;
	Point m_data;

	 //C'tor
  	 Node ();
	 Node (const Point& point, Node* node = nullptr);
	~Node () = default;

	//Node functions
	void  InsertAfter(Node* newNode);
	Node* DeleteAfter();
};


#endif // !__NODE_
