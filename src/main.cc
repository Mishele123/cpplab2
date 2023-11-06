
#include "header.h"

int main()
{
	setlocale(LC_ALL, "ru");

	LinkedList list1;
	LinkedList list2;

	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);

	LinkedList list3(list1);

	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_head(6);


	list1.display();
	print(list1.get_head());
	list2.display();
	list3.display();

	list3 = list2;
	list3.display();


	list1.push_tail(list2);
	list1.display();
	print(list1.get_head());

	list1.push_head(list2);
	list1.display();
	print(list1.get_head());


	list1.pop_head();
	list1.display();
	print(list1.get_head());

	list1.pop_tail();
	list1.display();

	list2.pop_tail();
	list2.display();

	list1.push_head(4);
	list1.push_tail(4);
	list1.display();
	list1.delete_node(4);
	list1.display();

	std::cout << list1[0] << std::endl;
	std::cout << list1[1] << std::endl;
	std::cout << list1[2] << std::endl;
	std::cout << list1[3] << std::endl;
	std::cout << list1[4] << std::endl;

	std::cout << list1[0] + list1[2] << std::endl;

	return 0;
}