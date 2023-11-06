#pragma once

// Односвязный циклический список
#include <stdexcept>


struct Node
{
	Node* next;
	int _data;
};

class LinkerdList
{
	Node* head;
	LinkerdList();
	LinkerdList(const LinkerdList& other);
	~LinkerdList();
	LinkerdList& operator=(const LinkerdList& other);
	void push_tail(int data);
	void push_tail(const LinkerdList& other);
};