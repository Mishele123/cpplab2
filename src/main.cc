
#include "header.h"

int main()
{
	setlocale(LC_ALL, "ru");

	LinkedList list1;
	LinkedList list2;

	list1.push_tail(1);
	list1.push_tail(2);
	list1.push_tail(3);

	LinkedList list3;
	list3.push_tail(list1);

	list2.push_tail(4);
	list2.push_tail(5);
	list2.push_head(6);

	std::cout << "list1 = ";
	list1.display();
	print(list1.get_head());
	std::cout << "list2 = ";
	list2.display();
	std::cout << "list3 = ";
	list3.display();
	list3 = list2;
	std::cout << "list3 = list2 = ";
	list3.display();

	std::cout << "list1.push_tail(list2)" << std::endl;
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

	std::cout << "Удалить элемент с конца второго списка" << std::endl;
	list2.pop_tail();
	list2.display();

	list1.push_head(4);
	list1.push_tail(4);
	list1.display();
	std::cout << "Удаление всех 4" << std::endl;
	list1.delete_node(4);
	list1.display();

	std::cout << "Доступ по индексу:" << std::endl;
	std::cout << list1[0] << " ";
	std::cout << list1[1] << " ";
	std::cout << list1[2] << " ";
	std::cout << list1[3] << " ";
	std::cout << list1[4] << " ";


	std::cout << std::endl;

	std::cout << "list1[0] + list1[2] = " << list1[0] + list1[2] << std::endl;


	LinkedList list4;
	list4.push_tail(2);
	list4.push_tail(3);
	list4.push_tail(-4);
	list4.push_tail(2);
	list4.push_tail(3);

	list4.display();

	std::cout << "list4.calculate() = " << calculate(list4, 2) << std::endl;

	std::cout << "Метод push head" << std::endl;
	std::cout << "list1 = ";
	list1.display();
	LinkedList list5;
	std::cout << "list5 = ";
	list5.display();
	list5.push_head(list1);
	std::cout << "list5 = ";
	list5.display();
	
	std::cout << "Заполнение случайными числами" << std::endl;
	LinkedList list6(11);
	list6.display();

	return 0;
}