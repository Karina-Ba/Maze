#include "Stack.h"

//-------------------------------------------------------------//
Stack::Stack(const Point& point)
{
	this->m_top = new Node(point);
}
//-------------------------------------------------------------//
Stack::~Stack()
{
	this->MakeEmpty();
}
//-------------------------------------------------------------//
void Stack::MakeEmpty()
{
	Node* temp;

	while (this->m_top != nullptr)
	{
		temp = this->m_top;
		this->m_top = this->m_top->m_next;
		delete temp;
	}
}
//-------------------------------------------------------------//
bool Stack::IsEmpty()
{
	return (this->m_top == nullptr);
}
//-------------------------------------------------------------//
void Stack::Push(Point& item)
{
	this->m_top = new Node(item, this->m_top);
}
//-------------------------------------------------------------//
Point Stack::Pop()
{
	if (this->IsEmpty())
	{
		cout << "Error: STACK UNDERFLOW" << endl;
		exit(1);
	}

	else
	{
		Node* temp  = this->m_top;
		Point item  = this->m_top->m_data;
		this->m_top = this->m_top->m_next;
		delete temp;
		return(item);
	}
}
//-------------------------------------------------------------//
Point Stack::Top()
{
	return Point();
}
//-------------------------------------------------------------//