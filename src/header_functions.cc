

#include "header.h"



//LinkerdList::LinkerdList(const LinkerdList& other)
//{
//	if (!other.head)
//	{
//		std::runtime_error("the list is empty");
//	}
//
//	Node* oldhead = head;
//	Node* next = oldhead->next;
//	while (oldhead)
//	{
//		next = oldhead->next;
//		delete oldhead;
//		oldhead = next;
//	}
//
//	head = nullptr;
//}

void LinkerdList::push_tail(int data)
{
	Node* newNode;
	newNode->_data = data;
	newNode->next = head;

	if (!head)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		Node* current = head;
		while (current->next != head)
		{
			current = current->next;
		}
		current->next = newNode;
		newNode->next = head;
	}

}
















