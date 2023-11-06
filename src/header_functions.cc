

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

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList()
{
	if (head == nullptr)
		return;

	Node* current = head;
	Node* next;

	do
	{
		next = current->next;
		delete current;
		current = next;
	} while (current != head);

	head = nullptr;
}

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
	do
	{
		Node* newNode = new Node;
		newNode->_data = otherCurrent->_data;
		newNode->next = head;

		current->next = newNode;
		current = newNode;

		otherCurrent = otherCurrent->next;

	} while (otherCurrent != other.head);
}



void LinkedList::display() const
{
	if (head == nullptr)
	{
		std::cout << "Список пуст" << std::endl;
	}

	Node* current = head;

	do
	{
		std::cout << current->_data << " ";
		current = current->next;
	} while (current != head);
	std::cout << std::endl;
}



void LinkedList::push_head(int data)
{

	Node* newNode = new Node;
	newNode->_data = data;


	if (head == nullptr)
	{
		head = newNode;
		head->next = head;
		return;
	}

	Node* current = head;
	while (current->next != head)
		current = current->next;
		
	current->next = newNode;
	newNode->next = head;
	head = newNode;
}

void LinkedList::push_head(const LinkedList& other)
{
	if (other.head == nullptr)
	{
		std::runtime_error("the other list is empty");
	}

	if (head == nullptr)
	{
		head = other.head;
		return;
	}

	Node* otherCurrent = other.head;
	LinkedList reverse;
	do
	{
		reverse.push_head(otherCurrent->_data);
		otherCurrent = otherCurrent->next;
	} while (otherCurrent != other.head);

	Node* current = reverse.head;
	do
	{
		push_head(current->_data);
		current = current->next;
	} while (current != reverse.head);
}



void LinkedList::pop_head()
{
	if (head == nullptr)
	{
		std::runtime_error("the list is empty");
	}

	Node* current = head;
	while (current->next != head)
		current = current->next;

	Node* temp = head;
	head = head->next;
	
	current->next = head;

	delete temp;
}

void LinkedList::pop_tail()
{
	if (head == nullptr)
		std::runtime_error("the list is empty");
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}

	Node* current = head;
	Node* prev = nullptr;
	while (current->next != head)
	{
		prev = current;
		current = current->next;
	}
	delete current;
	prev->next = head;
}


void LinkedList::delete_node(int data)
{
	if (head == nullptr)
		std::runtime_error("the list is empty");

	while (head != nullptr && head->_data == data)
	{
		Node* temp = head;
		Node* current = head;
		while (current->next != head)
			current = current->next;
		current->next = head->next;
		head = head->next;

		delete temp;
	}

	Node* current = head;
	while (current != nullptr && current->next != nullptr)
	{
		if (current->next->_data == data)
		{
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}

		if (current == head)
			break;
	}

}



int& LinkedList::operator[](int index)
{
	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		if (current == nullptr)
			std::out_of_range("Index out of range");
		current = current->next;
	}
	if (current == nullptr)
		std::out_of_range("Index out of range");

	return current->_data;
}


const int& LinkedList::operator[](int index) const
{
	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		if (current == nullptr)
			std::out_of_range("Index out of range");
		current = current->next;
	}
	if (current == nullptr)
		std::out_of_range("Index out of range");

	return current->_data;
}





