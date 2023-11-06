
#include "header.h"

int main()
{
	LinkedList list1;
	LinkedList list2;

	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);

	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_head(6);

	list1.display();
	list2.display();

	list1.push_tail(list2);
	list1.display();

	return 0;
}