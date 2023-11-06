#pragma once

// ќдносв€зный циклический список
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

void print(Node* el); // средний уровень #4