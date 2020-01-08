#include "Queue.h"

//-------------------------------------------------------------//
//C'tor
Queue::Queue(const Point& start, const int size)
{
	this->m_data  = new Point[size];
	this->m_size  = size;
	this->MakeEmpty ();
	this->EnQueue   (start);
}
//-------------------------------------------------------------//
void Queue::MakeEmpty()
{
	this->m_head = 1;
	this->m_tail = 0;
}
//-------------------------------------------------------------//
int Queue::AddOne(int x)
{
	return ((1 + x) % this->m_size);
}
//-------------------------------------------------------------//
bool Queue::IsEmpty()
{
	return( ( this->AddOne( this->m_tail ) ) == this->m_head);
}
//-------------------------------------------------------------//
Point Queue::Front()
{
	if (this->IsEmpty())
	{
		cout << "Error: QUEUE IS EMPTY" << endl;
		exit(1);
	}
	else
	{
		return this->m_data[this->m_head];
	}
}
//-------------------------------------------------------------//
void Queue::EnQueue(const Point& item)
{
	if (this->AddOne( this->AddOne( this->m_tail ) ) == this->m_head)
	{
		cout << "Error: QUEUE IS FULL" << endl;
		exit(1);
	}
	else
	{
		this->m_tail = this->AddOne( this->m_tail );
		this->m_data[this->m_tail] = item;
	}
}
//-------------------------------------------------------------//
Point Queue::DeQueue()
{
	if (this->IsEmpty())
	{
		cout << "Error: QUEUE IS EMPTY" << endl;
		exit(1);
	}
	else
	{	
		Point item   = this->m_data[this->m_head];
		this->m_head = this->AddOne(this->m_head);
		return(item);
	}
}
//-------------------------------------------------------------//

