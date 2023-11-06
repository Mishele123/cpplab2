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
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();
	LinkedList& operator=(const LinkedList& other);
	void push_tail(int data);
	void push_tail(const LinkedList& other);
	void display() const;
};