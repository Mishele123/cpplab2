#pragma once

// Односвязный циклический список
#include <stdexcept>
#include <iostream>

struct Node
{
	Node* next;
	int _data;

	Node();
};

class LinkedList
{
	Node* head;
public:

	Node* get_head()
	{
		return head;
	}

	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();
	LinkedList& operator=(const LinkedList& other);

	void push_tail(int data);
	void push_tail(const LinkedList& other);
	
	void push_head(int data);
	void push_head(const LinkedList& other);
	
	void pop_head();
	void pop_tail();

	void delete_node(int data);
	void display() const;

	const int& operator[](int index) const;
	int& operator[](int index);
};

void print(Node* head); // средний уровень #4

int calculate(Node* head, int x); // сложный уровень #1