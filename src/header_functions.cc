

#include "header.h"


Node::Node() : next(nullptr), _data(0) {}



LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int size) : head(nullptr)
{
	srand(time(nullptr));
	


	for (int i = 0; i < size; i++)
	{
		push_tail(rand() % 10);
	}
}

LinkedList::LinkedList(const LinkedList& other)
{
	if (other.head == nullptr)
	{
		head = nullptr;
		return;
	}

	head = nullptr;
	Node* otherCurrent = other.head;
	do
	{
		push_tail(otherCurrent->_data);
		otherCurrent = otherCurrent->next;
	} while (otherCurrent != other.head);

}

LinkedList::~LinkedList()
{
	if (head == nullptr)
		return;
	while (head != nullptr)
	{
		pop_head();
	}

	head = nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this == &other)
		return *this;
	LinkedList temp(other);
	std::swap(head, temp.head);
	return *this;
}

void LinkedList::push_tail(int data)
{
	Node* newNode = new Node;
	newNode->_data = data;

	if (head == nullptr)
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
		return;
	
	Node* current = head;
	if (head != nullptr)
	{
		while (current->next != head)
			current = current->next;
	}
	Node* otherCurrent = other.head;
	do
	{
		Node* newNode = new Node;
		newNode->_data = otherCurrent->_data;
		
		if (head == nullptr)
		{
			head = newNode;
			head->next = head;
			current = head;
		}
		else
		{
			newNode->next = head;

			current->next = newNode;
			current = newNode;
		}

		otherCurrent = otherCurrent->next;

	} while (otherCurrent != other.head);
}



void LinkedList::display() const
{
	if (head == nullptr)
	{
		std::cout << "Список пуст" << std::endl;
		return;
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
		return;
	}
	
	//if (head == nullptr)
	//{
	//	head = other.head; // 3 2 1 -> 1 2 3
	//	return;
	//}
	

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
		throw std::runtime_error("the list is empty");
	}

	if (head->next == head)
	{
		delete head;
		head = nullptr;
		return;
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
		throw std::runtime_error("the list is empty");

	if (head->next == head)
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
		throw std::runtime_error("the list is empty");

	while (head->_data == data)
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
	while (current->next != head)
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

	if (head == nullptr || size() < index)
		throw std::out_of_range("Index out of range");

	
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}

	return current->_data;
}


const int& LinkedList::operator[](int index) const
{
	if (head == nullptr || size() < index)
		throw std::out_of_range("Index out of range");
	
	Node* current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	return current->_data;
}


void print(Node* head)
{
	if (head == nullptr)
		throw std::runtime_error("the list is empty");

	LinkedList reverse;
	Node* current = head;
	do
	{
		reverse.push_head(current->_data);
		current = current->next;
	} while (current != head);

	std::cout << "Инвертированный список: ";

	Node* otherCurrent = reverse.get_head();
	do
	{
		std::cout << otherCurrent->_data << " ";
		otherCurrent = otherCurrent->next;
	} while (otherCurrent != reverse.get_head());
	
	std::cout << std::endl;
}

int calculate(const LinkedList& other, int x)
{
	if (other.get_head() == nullptr)
		throw std::runtime_error("the list is empty");

	Node* current = other.get_head();
	int result = 0;
	int n = other.size();
	
	for (int i = n; i >= 0; i--)
	{
		result += current->_data * pow(x, i);
		current = current->next;
	}

	return result;
}



int LinkedList::size() const
{
	int n = 0;

	Node* temp = head;
	while (temp->next != head)
	{
		n += 1;
		temp = temp->next;
	}
	return n;
}