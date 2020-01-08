#include "Node.h"

//-------------------------------------------------------------//
//C'tor
Node::Node()
{
	this->m_next = nullptr;
}
//-------------------------------------------------------------//
//Copy c'tor
Node::Node(const Point& point, Node* node)
{
	this->m_data = point;
	this->m_next = node;
}
//-------------------------------------------------------------//
//Function inserts new node 
void Node::InsertAfter(Node* newNode)
{
	newNode->m_next = this->m_next;
	this->m_next    = newNode;
}
//-------------------------------------------------------------//
//Function deletes the node after
Node* Node::DeleteAfter()
{
	Node* temp = this->m_next;

	if (temp == nullptr)
	{
		return nullptr;
	}

	else
	{
		this->m_next = temp->m_next;
		return temp;
	}
}
//-------------------------------------------------------------//