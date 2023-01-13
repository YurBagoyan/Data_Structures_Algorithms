#include "List.hpp"

using namespace DataStructure;

template <typename T>
void randomFillList(List<T>& list)
{
	constexpr int size = 8;
	for (int i = 0; i < size; ++i) {
		const int randNum = rand() % 10;
		list.push_back(randNum);
	}
}

int main()
{
	List<int> list;

	randomFillList(list);

	std::cout << "Size of list = " << list.size() << std::endl;
	list.print();

	list.push_front(9);
	std::cout << "\nAfter push_front size of list = " << list.size() << std::endl;
	list.print();

	list.insert(4, 99);
	std::cout << "\nAfter insert size of list = " << list.size() << std::endl;
	list.print();

	std::cout << "\n4th element of list " << list[4] << std::endl;

	std::cout << "\nMiddle value = " << list.find_Middle_Node_Value() << std::endl;

	list.reverse();
	list.print();
}