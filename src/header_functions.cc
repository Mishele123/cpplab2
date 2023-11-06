

#include "header.h"


Node::Node() : next(nullptr), _data(0) {}


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

void LinkedList::push_tail(int data)
{
	Node* newNode = new Node;
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



void LinkedList::push_tail(const LinkedList& other)
{
	if (other.head == nullptr)
		std::runtime_error("the other list is empty");
	if (head == nullptr)
		head = other.head;

	Node* current = head;

	while (current->next != head)
		current = current->next;

	Node* otherCurrent = other.head;
	while (otherCurrent != other.head)
	{
		Node* newNode = new Node;
		newNode->_data = otherCurrent->_data;
		newNode->next = head;

		current->next = newNode;
		current = newNode;

		otherCurrent = otherCurrent->next;

	}
}

void LinkedList::display() const
{
	if (head == nullptr)
	{
		std::cout << "Список пуст" << std::endl;
	}

	Node* current = head;

	while (current->next != head)
	{
		std::cout << current->_data << std::endl;
		current = current->next;
 	}
}











