#pragma once

// Односвязный циклический список
#include <stdexcept>
#include <iostream>
#include <random>


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

	int size() const;

	Node* get_head() const
	{
		return head;
	}

	LinkedList();
	LinkedList(int size);
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

int calculate(const LinkedList& other, int x); // сложный уровень #1